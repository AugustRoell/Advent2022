//Day 3 of adventofcode2022
//
//A simple program to find the sum of the priorities of the unique item 
//categories occuring at least once in each triplet of backpacks. Each such 
//item is the badge that the triplet of elves should be carrying.


#include <iostream>
#include <string>


int main() {
	
	//The string objects that will contain the inventories of each of the 
	//three elves in any group.
	std::string backpack_1, backpack_2, backpack_3;

	//In order to ascribe the numerical priorities to each item category, 
	//as put forward in the challenge, we define a string containing the 
	//alphabet (once lower-case, once upper-case), so that the priority of 
	//an item category is 1 plus the index of the character corresponding 
	//to that item category.
	std::string alphabet = 
	{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	//unsigned integer objects containing the sum of all the priorities of 
	//the badges.
	unsigned int priorities_sum = 0;

	//Here we read the input .txt file per line. The puzzle input should 
	//contain 300 lines, hence the 100 fold itteration of tripple reads. 
	//Each line contains a string of arbitrary even length, with the 
	//promise that one and only one item category occurs in all three 
	//backpacks of any elf triplet.
	//
	//We find this badge by looping over the characters of the first 
	//string corresponding to the invetory of the first elf, and checking 
	//whether this character occurs in both of the other strings. If it 
	//does, we attribute a value, called the priority, to this character  
	//by finding its index in the alphabet list above and adding 1 (so 
	//that 'a' has value 1). After that we break the iteration over 
	//characters, to prevent double occurences.
	//
	//NOTE: it may provide a marginal speed-up to first find out which of 
	//the three elves has the smallest inventory and then loop over that 
	//string, instead of looping over the first inventory regardless of 
	//size.
	for (int i = 0; i < 100; i++) {
		std::cin >> backpack_1;
		std::cin >> backpack_2;
		std::cin >> backpack_3;

		for (char item : backpack_1) {
			if (backpack_2.find(item) != 
					std::string::npos && 
					backpack_3.find(item) != 
					std::string::npos) {

				priorities_sum += alphabet.find(item) + 1;
				break;
			}
		}
	}

	std::cout << "The sum of priorities of the bagdes is " << 
		priorities_sum << '\n';


	return 0;
}
