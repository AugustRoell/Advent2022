//Day 10 of Advent of Code 2022
//
//A program to find the image, projected on the screen of a cathode-ray tube 
//(CRT) provided with the output of a program run by a central processing 
//unit (CPU), while both the time their operations based on the cycles of a 
//clock circuit. 
//
//In particular, the CPU calculates the position of a sprite, saved in a 
//register as an integer X starting with value 1 and changing depending on the 
//program in the input .txt file. The program consists solely of two types of 
//commands: "noop", which is the No-Operation command and takes one cycle of 
//the internal clock circuit to perform, and "addx", which is the addition 
//command adding a specified integer to the value X in the register and takes 
//two cycles to perform.
//
//At the start of each cycle of the internal clock circuit, the CRT draws one 
//pixel on the fourty pixel wide screen. The sprite is three pixels wide and 
//the integer X in the register represents the position of the middle pixel of 
//the sprite. If the sprite the CRT is drawing currently overlaps with the 
//sprite, the CRT draws a "#". Otherwise, it draws a ".". If the CRT-drawn 
//lines are all rendered, eight capital letters should appear.


#include <iostream>
#include <string>


int main() {

	//Two string objects, the first of which will contain the input lines, 
	//and the second of which will contain a single fourty-wide line 
	//rendered by the CRT.
	std::string line, CRT_line = "";

	//Three integer objects, the first of which keeps track of the cycle 
	//number, the second of which keeps track of the value in the 
	//register, and the third of which keeps track of which pixel the CRT 
	//is currently drawing.
	int cycle = 1, X = 1, pixel = 0;

	std::cout << '\n';

	//Here we read the input .txt file per line.
	//
	//For each input line, we check what the command is. If it is "noop", 
	//we increment the cycle counter by 1 and leave the value in the 
	//register unchanged. If, instead, the command is "addx", we increment 
	//the cycle counter by 1, increment it by 1 again, and then add the 
	//specified value to the value in the register. Moreover, before each 
	//increment of the cycle counter, we check if the current pixel to be 
	//drawn by the CRT overlaps with the sprite, and if it does we append 
	//a "#" to the "CRT_line" string. Otherwise, we append ".". After that 
	//we check if the current CRT line is complete (i.e. if the cycle 
	//counter is a multiple of 40) and if it is we output it and reset the 
	//pixel counter and the "CRT_line" string. 
	while (std::getline(std::cin, line)) {
		
		if (line.substr(0, 4) == "noop") {

			if (pixel == X - 1 || pixel == X || pixel == X + 1) {
				CRT_line += "#";
			}

			else {
				CRT_line += ".";
			}


			pixel++;


			if (cycle % 40 == 0) {
				std::cout << CRT_line << '\n';
				CRT_line = "";
				pixel = 0;
			}


			cycle++;
		}

		else if (line.substr(0, 4) == "addx") {

			if (pixel == X - 1 || pixel == X || pixel == X + 1) {
				CRT_line += "#";
			}

			else {
				CRT_line += ".";
			}


			pixel++;


			if (cycle % 40 == 0) {
				std::cout << CRT_line << '\n';
				CRT_line = "";
				pixel = 0;
			}


			cycle++;


			if (pixel == X - 1 || pixel == X || pixel == X + 1) {
				CRT_line += "#";
			}

			else {
				CRT_line += ".";
			}


			pixel++;


			if (cycle % 40 == 0) {
				std::cout << CRT_line << '\n';
				CRT_line = "";
				pixel = 0;
			}


			X += stoi(line.substr(5));

			cycle++;
		}
	}


	std::cout << '\n';


	return 0;
}
