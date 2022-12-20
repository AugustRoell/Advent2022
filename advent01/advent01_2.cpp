//Day 1 of adventofcode2022
//
//A simple program that outputs the three largest calorie counts carried by 
//individual elves, ordered non-increasingly, as well as the sum of these 
//three calorie counts.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<int> VI;


//A function to find whether the given string constitutes a white line.
//Returns 1 if the line is white and 0 if it is not.
bool isWhitespace(const std::string s) {
    for(size_t index = 0; index < s.length(); index++){
        if(!std::isspace(s[index]))
            return false;
    }
    return true;
}


int main() {

	//The string object that will contain the number of callories of a 
	//given snack. It is a string object because we need to check for 
	//white lines in order to distinguish between the inventories of the 
	//elves.
	std::string line;

	//The int objects that keep track of the calorie count per snack and 
	//per elf.
	int snack, calories = 0;

	//The vector object containing the three integer objects that keep 
	//track of the three largest calorie counts per elf.
	VI top3_calories (3,0);

	//Here we read the input .txt file per line.
	//
	//If the line is not white the input line contains the calorie count 
	//of a snack in the form of a string object. We convect the string 
	//object to an integer and add it to the number of calories carried by 
	//one elf.
	//
	//If the line is white we have accounted for all the snacks carried by 
	//one elf. This calorie count is compared to the smallest of the 
	//largest three calorie counts up to this point and if it is larger it 
	//takes over the spot in the top three. Subsequently, the vector is 
	//ordered non-increasingly.
	while (std::getline(std::cin, line)) {
		if (isWhitespace(line)) {
			top3_calories[2] = (top3_calories[2] < calories) 
				? calories : top3_calories[2];
			std::sort(top3_calories.begin(), top3_calories.end(), 
					std::greater<int>());
			calories = 0;
		}
		else {
			snack = stoi(line);
			calories += snack;
		}
	}


	std::cout << "\n    _      _      _      _      _        O        _  " 
		<< "    _      _      _    \n" 
		<< "   /\\\\    /\\\\    /\\\\    /\\\\    /\\\\      /|\\   " 
		<< "   /\\\\    /\\\\    /\\\\    /\\\\   \n" 
		<< "  0  O   0  O   0  O   0  O   0  O     / | \\    0  O   0" 
		<< "  O   0  O   0  O   \n" 
		<< "    /|\\    /|\\    /|\\    /|\\    /|\\      |        /|" 
		<< "\\    /|\\    /|\\    /|\\  \n" 
		<< "     |      |      |      |      |      | |        |     " 
		<< " |      |      |   \n" 
		<< "    / |    / |    / |    / |    / |    /  |       / |    " 
		<< "/ |    / |    / |  \n";
	
	std::cout << "\n=====================================================" 
		<< "==========================" << "\n\n";

	std::cout << "The top three elves are carrying " << top3_calories[0] 
		<< ", " << top3_calories[1] << ", and " << top3_calories[2] 
		<< " calories.\nTogether they are carrying " 
		<< top3_calories[0] + top3_calories[1] + top3_calories[2] 
		<< " calories.\n";

	std::cout << "\n=====================================================" 
		<< "==========================" << "\n\n";

	return 0;
}
