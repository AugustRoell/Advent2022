//Day 3 of adventofcode2022
//
//A simple program to find the sum of the priorities of the unique
//item categories, mistakenly placed in both compartments of an elf's
//backpack.


#include <iostream>
#include <string>


int main() {
	
	//The string objects that will contain a line from the input, 
	//the characters corresponding to the items in the first 
	//compartment of the backpack, and similarly those in the 
	//second compartment.
	std::string line, first_compartment, second_compartment;

	//In order to ascribe the numerical priorities to each item 
	//category, as put forward in the challenge, we define a 
	//string containing the alphabet (once lower-case, once 
	//upper-case), so that the priority of an item category is 1
	//plus the index of the character corresponding to that item 
	//category.
	std::string alphabet = 
	{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	//unsigned integer objects containing the length of an input 
	//string, as well as the sum of all the priorities of the 
	//misplaced items.
	unsigned int length, priorities_sum = 0;

	//Here we read the input .txt file per line. The puzzle input should
	//contain 300 lines, hence the 300 fold itteration. Each line contains
	//a string of arbitrary even length, with the promise that one and 
	//exactly one character in the first half of the string also occurs in
	//the second half of the string.
	//
	//We find this unique repeated character by splitting the original 
	//string in half (guaranteed to be possible since all strings here are 
	//of even length), after which we loop over the characters in the first 
	//half of the string, checking every time if this character also occurs 
	//in the second half of the string. If it does, we attribute a value, 
	//called the priority, to this character by finding its index in the 
	//alphabet list above and adding 1 (so that 'a' has value 1). After 
	//that we break the iteration over characters, to prevent double 
	//occurences.
	for (int i = 0; i < 300; i++) {
		std::cin >> line;

		length = line.length();

		first_compartment = line.substr(0, length/2);
		second_compartment = line.substr(length/2, length);

		for (char item : first_compartment) {
			if (second_compartment.find(item) != std::string::npos) {
				priorities_sum += alphabet.find(item) + 1;
				break;
			}
		}
	}

	std::cout << "The sum of priorities of the displaced items is " << priorities_sum << '\n';


	return 0;
}
