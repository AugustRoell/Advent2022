//Day 5 of Advent of Code 2022
//
//A program to find the final configuration of the input stacks of named 
//crates after performing the provided permutations. In particular, when we 
//are moving multiple crates from one stack to another we move them one by 
//one, effectively reversing their order. The final output is a sequence of 
//the names, as upper case characters, of the crates on top of each of the 
//stacks.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


//A function to find whether the given string constitutes a white line. 
//Return 1 if the line is white and 0 if it is not.
bool isWhitespace(std::string s) {
	for (std::size_t index = 0; index < s.length(); index++) {
		if (!std::isspace(s[index])) {
			return false;
		}
	}
	return true;
}


int main() {
	
	//The string object that will contain the input lines, which will 
	//contain information either on the initial configuration of crates or 
	//the permutations that we will apply to this initial configuration.
	std::string line;

	//A vector object containing vectors of characters, such that each of 
	//the substrings corresponds to a stack, and each of the characters in 
	//such a substring represents a name of a crate in that stack.
	std::vector<std::vector<char>> stacks;

	//Three unsigned integer object which contain information about a 
	//permutation of the crate configuration, such that the first 
	//corresponds to the number of crates that will be moved, the second 
	//corresponds to the stack that the crates will be taken from, and the 
	//third corresponds to the stack the crates will be moved to.
	unsigned int num_of_moves, origin, destination;


	//Here we read the input .txt file per line untill we encounter a 
	//white line. Effectively, this means we only read those lines that 
	//contain information about the intial configuration of the crates.
	//
	//After getting an input line, we check whether the "stacks" vector is 
	//empty. This should only be the case at the first input line. If it 
	//is indeed empty, we append a number of empty vectors, untill the 
	//'stacks' object contains as many empty vectors as there are stacks 
	//in the input file. We calculate this number by simply dividing the 
	//length of the input string by 4.
	//
	//Now, for every non-white input line, we itterate over the number of 
	//stacks and check whether the element at index 1 + 4*i of the input 
	//string is an upper case letter. Here, 'i' corresponds to the 
	//"i + 1"-th stack. We only look at the 1 + 4*i indices because these 
	//are the indices that potentially point to the name of a crate, while 
	//the other indices point to ' ', '[', or ']'. We check whether the 
	//elements at the 1 + 4*i indices are upper case in order to exclude 
	//those instances where there is no crate at the corresponding index 
	//(i.e. the element at that index is ' ').
	//
	//Once we have checked that the element at such an index is indeed an 
	//upper case character corresponding to the name of a crate, we append 
	//this character to the i-th vector of the "stacks" object.
	while (std::getline(std::cin, line)) {
		if (isWhitespace(line)) {
			break;
		}
		else {
			if (stacks.empty()) {
				for (std::size_t i = 0; 
						i < line.length()/4; i++) {

					stacks.push_back({});
				}
			}

			for (std::size_t i = 0; i < line.length()/4; i++) {
				if (std::isupper(line[1 + 4*i])) {
					stacks[i].push_back(line[1 + 4*i]);
				}	
			}
		}
	}


	//Here we reverse all of the substrings of the "stacks" object, so 
	//that the last element of such a substring correspond to the top 
	//crate of the corresponding stack.
	for (unsigned int i = 0; i < stacks.size(); i++) {
		std::reverse(stacks[i].begin(), stacks[i].end());
	}


	//Here we read the rest of the input .txt file per line. Effectively 
	//this means that here we only read those lines that contain 
	//information about the permutations we are going to perform on the 
	//initial configuration of the stacks.
	//
	//Using the regular format of the input file, one can find the ranges 
	//of the indices of an input line that contain the integers 
	//corresponding to the number of crates that must be moved, the stack 
	//from which these crates will be taken, and the stack to which they 
	//will be moved.
	//
	//Subsequently, we perform the permutation specified by the input line.
	//As is required in this challenge, the crates are moved one by one, 
	//effectively reversing their order.
	while (std::getline(std::cin, line)) {
		num_of_moves = stoi(line.substr(5, 
					line.find('f') - 6));
		origin = stoi(line.substr(line.find_last_of('m') + 2, 
					line.find('t') - 
					line.find_last_of('m') - 3));
		destination = stoi(line.substr(line.find_last_of('o') + 2));

		for (unsigned int i = 0; i < num_of_moves; i++) {
			stacks[destination - 1].push_back(
					stacks[origin - 1].back());

			stacks[origin - 1].pop_back();
		}
	}


	//Here, we output the last element of each of the substrings of the 
	//"stacks" object, so that we give the names of the top crate of each 
	//stack.
	for (unsigned int i = 0; i < stacks.size(); i++) {
		std::cout << stacks[i].back() << ' ';
	}
	std::cout << '\n';

	return 0;
}
