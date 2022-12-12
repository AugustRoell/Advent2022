//Day 2 of adventofcode2022
//
//A simple program to find your score in a game of rock, paper, scissors, given a 
//document contain all opponent moves, as well as your recommended moves.


#include <iostream>


int main() {

	//The character objects that will contain your opponents move, as well as 
	//the outcome of this game round (which you have to realise through the 
	//magic of christmas). The moves are codified such that your opponent's 
	//choice of rock, paper, and scissors respectively correspond to A, B, C 
	//and X, Y, Z correspond respectively to you losing, playing draw, 
	//or winning.
	char opponent_move, outcome;

	//An unsigned integer that keeps track of your total score.
	unsigned int score = 0;

	//Here we read the input .txt file per line. The puzzle input should 
	//contain 2500 lines, hence the 2500 fold itteration. Each line contains 
	//two moves, your opponents and your respectively.
	//
	//With a simple if-elif-else tree we distinguish between all possible 
	//combinations of a single rock, paper, scissors game. The scoring is as 
	//follows: 1, 2, or 3 points for playing rock, paper, scissors, 
	//and 0, 3, or 6 points for losing, playing draw, winning respectively.
	for (int i = 0; i < 2500; i++) {
		std::cin >> opponent_move;
		std::cin >> outcome;

		if (outcome == 'X') {
			if (opponent_move == 'A') {
				score += 3;
			}
			else if (opponent_move == 'B') {
				score += 1;
			}
			else {
				score += 2;
			}
		}

		else if (outcome == 'Y') {
			if (opponent_move == 'A') {
				score += 4;
			}
			else if (opponent_move == 'B') {
				score += 5;
			}
			else {
				score += 6;
			}
		}

		else if (outcome == 'Z') {
			if (opponent_move == 'A') {
				score += 8;
			}
			else if (opponent_move == 'B') {
				score += 9;
			}
			else {
				score += 7;
			}
		}


	}

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	std::cout << "If everything goes according to plan" 
		<< " your score will be " << score << '\n';

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	return 0;
}
