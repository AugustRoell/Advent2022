//Day 9 of Advent of Code 2022
//
//A program to find the number of positions traversed at least once by a tail 
//knot of a tenfold knotted rope. In particular, we simulate the behaviour of 
//a rope consisting of ten knots, each with one Planck Length distance. These 
//knots live on a square lattice with spacing equal to one Planck Length. Note 
//that we take the diagonal distance to also be equal to one Planck Length. 
//The simulation then deals with the movements of the head knot, as provided 
//by the input .txt file, and the subsequent movements of all the other knots, 
//which must stay at most one Planck Length away from the knot in front of 
//them.


#include "Knot.hpp"
#include <vector>
#include <algorithm>


int main() {

	//A string object that will contain the input lines.
	std::string line;

	//A pair object of two integers, which represents the origin of the 
	//lattice over which the knot objects will move. 
	std::pair<int, int> origin = std::make_pair(0, 0);

	//A vector of pair objects which will contain all the positions the 
	//tail knot traversed at least once. It will contain each such 
	//position exactly once. It is initialized with a vector containing 
	//only the origin, because that is where all the knots start.
	std::vector<std::pair<int, int>> traversed_positions = {origin};

	//Ten Knot objects, which will represent the head, the tail, and all 
	//the knots in between of the simulated rope. They are initialized at 
	//their default position at the origin.
	Head head;
	Tail knot_2, knot_3, knot_4, knot_5, knot_6, knot_7, knot_8, knot_9;
	Tail tail;

	//A character object that will contain the character in the input .txt 
	//file that represents the direction of the instructed movement of 
	//the head knot.
	char direction;

	//An unsigned integer object that will contain the integer in the 
	//input .txt file that represents the number of steps of the 
	//instructed movement of the head knot.
	unsigned int distance;


	//Here we read the input .txt file per line.
	//
	//For each input line, we apply the instructed movement through the 
	//member functions defined on the "Head" and "Tail" classes. 
	//Subsequently, we check if the new position of the "tail" object is 
	//already an element of the "traversed_positions" vector, and if it is 
	//not, we append it to the vector.
	while (std::getline(std::cin, line)) {
		
		direction = line[0];
		distance = stoi(line.substr(2));

		for (unsigned int i = 0; i < distance; i++) {

			head.change_position(direction);

			knot_2.follow(head);
			knot_3.follow(knot_2);
			knot_4.follow(knot_3);
			knot_5.follow(knot_4);
			knot_6.follow(knot_5);
			knot_7.follow(knot_6);
			knot_8.follow(knot_7);
			knot_9.follow(knot_8);

			tail.follow(knot_9);
			

			if (std::find(traversed_positions.begin(), 
						traversed_positions.end(), 
						tail.get_position()) == 
			  			traversed_positions.end()) {
				
				traversed_positions.push_back(
						tail.get_position());
			}
		}
	}


	std::cout << "\n=====================================================" 
		<< "==========================\n\n";
	
	std::cout << "The tail visited " 
		<< traversed_positions.size() 
		<< " positions at least once.\n";

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";
	
	return 0;
}
