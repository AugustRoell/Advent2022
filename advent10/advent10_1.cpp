//Day 10 of Advent of Code 2022
//
//A program to find the sum of the signal strengths at the relevant cycles of 
//an internal clock circuit. Here, the signal strength is the product of the 
//integer value "X", stored in a register which starts with value 1 and to 
//which integer values are added or substracted over the course of the 
//program, with the cycle number, which also starts with value 1. The 
//program is provided by the input .txt file, and consists of a sequence of 
//two types of commands: "noop", which is the No-Operation command and takes 
//one cycle of the internal clock circuit to perform, and "addx", which is the 
//addition command adding a specified integer to the value X in the register 
//and takes two cycles to perform. The relevant cycles for the signal 
//strengths start with cycle 20 and every 40 cyles after that (i.e. 20, 60, 
//100, 140, ...) up to and including cycle 220.


#include <iostream>
#include <string>


int main() {

	//A string object that will contain th input lines.
	std::string line;

	//Three integer objects, the first of which keeps track of the cycle 
	//number, the second of which keeps track of the value in the 
	//register, and the third of which keeps track of the sum of the 
	//relevant signal strengths.
	int cycle = 1, X = 1, signal_strength_sum = 0;


	std::cout << "\n=====================================================" 
		<< "==========================\n\n";
	
	std::cout << "Cycle\t\tSignal Strength\n";

	//Here we read the input .txt file per line.
	//
	//For each input line, we check what the command is. If it is "noop", 
	//we increment the cycle counter by 1 and leave the value in the 
	//register unchanged. If, instead, the command is "addx", we increment 
	//the cycle counter by 1, increment it by 1 again, and then add the 
	//specified value to the value in the register. Moreover, after each 
	//increment of the cycle counter, we check if we are in a relevant 
	//cycle, and if we are we add the current signal strength to the 
	//"signal_strength_sum" object. That is also why we increment the 
	//cycle counter twice during an "addx" command, instead of 
	//incrementing once by two.
	//
	//NOTE: Even though the "cycle" object will always be greater than 0, 
	//it should be declared as an integer, rather than an unsigned 
	//integer. If it is declared as an unsigned integer, the expression 
	//"(cycle - 20)" will evaluate to (2^32 + cycle - 20), so that for 
	//"cycle" equal to 4 the expression "(cycle - 20) % 40 == 0" will 
	//evaluate to true. The 32 is due to the fact that by default an 
	//unsigned integer object is a 32 bit object.
	while (std::getline(std::cin, line) && cycle <= 220) {
		
		if (line.substr(0, 4) == "noop") {

			cycle++;

			if ((cycle - 20) % 40 == 0) {
				signal_strength_sum += cycle*X;
				std::cout << cycle 
					<< "\t\t" 
					<< cycle*X 
					<< '\n';
			}
		}

		else if (line.substr(0, 4) == "addx") {

			cycle++;

			if ((cycle - 20) % 40 == 0) {
				signal_strength_sum += cycle*X;
				std::cout << cycle 
					<< "\t\t" 
					<< cycle*X 
					<< '\n';
			}
			
			cycle++;

			X += stoi(line.substr(5));

			if ((cycle - 20) % 40 == 0) {
				signal_strength_sum += cycle*X;
				std::cout << cycle 
					<< "\t\t" 
					<< cycle*X 
					<< '\n';
			}
		}
	}



	std::cout << "\nThe sum of the relevant signal strengths is " 
		<< signal_strength_sum << '\n';

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";	

	return 0;
}
