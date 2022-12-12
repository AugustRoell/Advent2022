//Day 6 of Advent of Code 2022
//
//A program to find the position of the start-of-message (SoM) marker in a 
//long string. The SoM marker is characterised by the fact that it is a 
//sequence of fourteen consecutive characters without repetitions. Here, we 
//find the position (index + 1) of the last character of the first 
//tetrakaidekatuplet of consecutive characters in the input string which 
//satisfy this criterion.


#include <iostream>
#include <string>
#include <unordered_set>


int main() {

	//Two string objects, the first of which will contain the input string 
	//and the second of which will, one after the other, contain all the 
	//tetrakaidekatuplets of consecutive characters in this input string. 
	std::string line, tetrakaidekatuplet;

	//A size type object that will contain the position (index + 1) of the 
	//last character of the first instance of a SoM tetrakaidekatuplet in 
	//the input string.
	std::size_t first_SoM_position;

	//An unordered set that will, for each tetrakaidekatuplet, contain 
	//characters of that tetrakaidekatuplet, in order to test if a 
	//character in the tetrakaidekatuplet occurs more than once.
	std::unordered_set<char> occured;

	//A boolean object that contains information about whether there was 
	//a character in a given tetrakaidekatuplet that occured more than once.
	bool repetition;

	//Here we read-in the singular line of the input .txt file.
	std::cin >> line;

	//Here we itterate over the input string and for each itteration 
	//define a tetrakaidekatuplet as a substring of length 14 starting at 
	//the index equal to the itterator. We then set the unordered list of 
	//occured characters to be empty, in order to forget about the 
	//previous tetrakaidekatuplet. Moreover, we set the boolean 
	//"repetition" to "false", since no repetitions have yet been found in 
	//the new tetrakaidekatuplet.
	//
	//Subsequently, we itterate over the characters in the 
	//tetrakaidekatuplet and check whether any character occurs more than 
	//once by checking if the current character already is an element in 
	//the unordered list of occured characters. If it is not, we insert 
	//the current character to the unordered list of occurrences. If it 
	//is, we set the "repetition" bool to "true" and break the itteration 
	//over the tetrakaidekatuplet.
	//
	//Finally, we check if, for the currently considered 
	//tetrakaidekatuplet, there were no repeating characters. If this is 
	//indeed the case, we set the size type object "first_SoM_position" to 
	//the position of the last character in this tetrakaidekatuplet and 
	//break out of the itteration over the input string.
	for (std::size_t i = 0; i < line.length() - 13; i++) {

		tetrakaidekatuplet = line.substr(i, 14);

		occured = {};

		repetition = false;

		for (char c : tetrakaidekatuplet) {
			if (occured.find(c) != occured.end()) {
				repetition = true;
				break;
			}

			else {
				occured.insert(c);
			}
		}

		if (!repetition) {
			first_SoM_position = i + 14;
			break;
		}
	}


	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	std::cout << "We needed to process " 
		<< first_SoM_position 
		<< " characters to find the first start-of-message marker.\n";

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	return 0;
}
