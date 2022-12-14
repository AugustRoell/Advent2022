//Day 4 of Advent of Code 2022
//
//A simple program to find the number of elf pairs where the range of sections 
//one elf has to clean fully contains the others range. 


#include <iostream>
#include <string>

typedef unsigned int UI;

int main () {

	//The unsigned integer object that will contain the number of 
	//occurences of the range of one elf in a pair to contain the range of 
	//the other.
	UI num_of_containments = 0;

	//A string object that will contain a line from the input.
	std::string line;

	//Four unsigned integer objects that will contain the start and the 
	//end of the ranges of the first and the second elf in a pair 
	//respectively.
	UI sec_1_start, sec_1_end, sec_2_start, sec_2_end;

	//Here we read the input .txt file per line. The puzzle input should 
	//contain 1000 lines, hence the 1000 fold itteration. Each line 
	//contains a string of the form "a-b,c-d", where a,b,c, and d are 
	//unsigned integers corresponding to sec_1_start, sec_1_end, 
	//sec_2_start, sec_2_end, respectively.
	//
	//We find the number of times one of these ranges contains the other 
	//by splitting the input string into four substrings, according to 
	//where the characters '-' and ',' occur, and transforming these 
	//substrings to integers. Finally, we check whether one of the two 
	//ranges contains the other.
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

		if ((sec_1_start >= sec_2_start 
					and sec_1_end <= sec_2_end) 
					or (sec_2_start >= sec_1_start 
					and sec_2_end <= sec_1_end)) {

			num_of_containments += 1;
		}
	}


	std::cout << "          __           __           __           __    " 
		<< "       __      \n" 
		<< "       | //\\\\       | //\\\\       | //\\\\       | //" 
		<< "\\\\       | //\\\\     \n" 
		<< "       |\\0  '       |\\0  '       |\\0  '       |\\0  ' " 
		<< "      |\\0  '     \n" 
		<< "       | |\\         | |\\         | |\\         | |\\   " 
		<< "      | |\\       \n" 
		<< "       |/ \\         |/ \\         |/ \\         |/ \\   " 
		<< "      |/ \\       \n" 
		<< "      /x\\          /x\\          /x\\          /x\\     " 
		<< "     /x\\         \n" 
		<< "     //x\\\\        //x\\\\        //x\\\\        //x\\\\" 
		<< "        //x\\\\        \n";

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	std::cout << "There are " << num_of_containments 
		<< " assignment pairs where one section range contains the other.\n";

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	return 0;
}
