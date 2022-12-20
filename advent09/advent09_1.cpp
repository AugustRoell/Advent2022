//Day 9 of Advent of Code 2022
//
//A program to find the number of positions traversed at least once by a tail 
//knot of a double knotted rope. In particular, we simulate the behaviour of a 
//rope of Planck Length with a knot at its head and tail, and these head and 
//tail knots live on a square lattice with spacing equal to one Planck Length. 
//Note that we take the diagonal distance to also be equal to one Planck 
//Length. The simulation then deals with the movements of the head knot, as 
//provided by the input .txt file, and the subsequent movements of the tail 
//knot, which must stay at most one Planck Length away from the head.


#include "Knot.hpp"
#include <vector>
#include <algorithm>

typedef std::pair<int, int> P;
typedef std::vector<P> VP;

int main() {

	//A string object that will contain the input lines.
	std::string line;

	//A pair object of two integers, which represents the origin of the 
	//lattice over which the knot objects will move. 
	P origin = std::make_pair(0, 0);

	//A vector of pair objects which will contain all the positions the 
	//tail knot traversed at least once. It will contain each such 
	//position exactly once. It is initialized with a vector containing 
	//only the origin, because that is where the head and tail knots start.
	VP traversed_positions = {origin};

	//A Head and a Tail object, which will represent the head and the tail 
	//of the simulated rope. They are initialized at their default 
	//position at the origin.
	Head head;
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

			tail.follow(head);
			
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
