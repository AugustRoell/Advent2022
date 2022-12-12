//Day 1 of adventofcode2022
//
//A simple program to find the largest number of calories any of the elves is 
//carrying.


#include <iostream>
#include <string>


//A function to find whether the given string constitutes a white line.
//Returns 1 if the line is white and 0 if it is not.
bool isWhitespace(std::string s){
    for(std::size_t index = 0; index < s.length(); index++){
        if(!std::isspace(s[index]))
            return false;
    }
    return true;
}


int main() {

	//The string object that will contain the number of callories of a 
	//given snack.It is a string object because we need to check for white 
	//lines in order to distinguish between the inventories of the elves.
	std::string line;

	//The int objects that keep track of the calorie count per snack and 
	//per elf, as well as the the largest number of calories carried by a 
	//single elf. 
	int snack, calories = 0, max_calories = 0;

	//Here we read the input .txt file per line.
	//
	//If the line is not white the input line contains the calorie count 
	//of a snack in the form of a string object. We convect the string 
	//object to an integer and add it to the number of calories carried by 
	//one elf.
	//
	//If the line is white we have accounted for all the snacks carried by 
	//one elf. This calorie count is compared to the largest calorie count 
	//up to this point and if it is larger it becomes the new tentative 
	//maximum.
	while (std::getline(std::cin, line)) {
		if (isWhitespace(line)) {
			max_calories = (max_calories < calories) 
				? calories : max_calories;
			calories = 0;

		}
		else {
			snack = stoi(line);
			calories += snack;
		}
	}

	std::cout << "\n=====================================================" 
		<< "==========================" << "\n\n";

	std::cout << "The largest number of calories carried by any elf is " 
		<< max_calories << '\n';

	std::cout << "\n=====================================================" 
		<< "==========================" << "\n\n";

	return 0;
}
