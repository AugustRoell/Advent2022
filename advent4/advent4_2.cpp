//Day 4 of Advent of Code 2022
//
//A simple program to find the number of elf pairs where the range of sections 
//one elf has to clean overlaps the others range. 


#include <iostream>
#include <string>


int main () {

	//The unsigned integer object that will contain the number of 
	//occurences of the range of one elf in a pair overlapping the range of 
	//the other.
	unsigned int num_of_overlappings = 0;

	//A string object that will contain a line from the input.
	std::string line;

	//Four unsigned integer objects that will contain the start and the 
	//end of the ranges of the first and the second elf in a pair 
	//respectively.
	unsigned int sec_1_start, sec_1_end, sec_2_start, sec_2_end;

	//Here we read the input .txt file per line. The puzzle input should 
	//contain 1000 lines, hence the 1000 fold itteration. Each line 
	//contains a string of the form "a-b,c-d", where a,b,c, and d are 
	//unsigned integers corresponding to sec_1_start, sec_1_end, 
	//sec_2_start, sec_2_end, respectively.
	//
	//We find the number of times one of these ranges overlaps the other 
	//by splitting the input string into four substrings, according to 
	//where the characters '-' and ',' occur, and transforming these 
	//substrings to integers. Finally, we check whether one of the two 
	//ranges overlaps the other.
	for (int i = 0; i < 1000; i++) {
		std::cin >> line;

		sec_1_start = stoi(line.substr(0, line.find('-')));
		sec_1_end = stoi(line.substr(line.find('-') + 1, 
					line.find(',') - 
					line.find('-') - 1));
		sec_2_start = stoi(line.substr(line.find(',') + 1, 
					line.find_last_of('-') - 
					line.find(',') - 1));
		sec_2_end = stoi(line.substr(line.find_last_of('-') + 1));
		
		if (!(sec_1_end < sec_2_start or sec_1_start > sec_2_end))
			num_of_overlappings += 1;
	}

	std::cout << "There are " << num_of_overlappings << 
		" pairs where one section range overlaps the other" << '\n';


	return 0;
}
