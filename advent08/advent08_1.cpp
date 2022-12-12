//Day 8 of Advent of Code 2022
//
//A program to find the total number of trees visible from the outside of a 
//grid of trees, given the positions and heights of the trees in this grid. 
//A tree is considered visible from the outside if there is at least one 
//direction along its row or column (upward, downward, to the right, or to the 
//left, but not diagonal) such that there are no trees of greater or equal 
//height there.


#include <iostream>
#include <string>
#include <vector>


//A function that takes as its arguments a grid of trees (represented by a 
//matrix of unsigned integers), as well as two insigned integers 
//representing the row and column of a specific tree. It will return "true" if 
//that specific tree is visible from the outside, and "false" if it is not.
//
//This is done by two separate itterations, one over the row, the other over 
//the column of the specific tree. If a tree of equal or greater height is 
//found, it is noted whether this tree is to the right, left, top, or bottom 
//of the original tree. Finally, if the tree is not visible from any of these 
//four directions, the function returns "false", and otherwise it 
//returns "true".
bool isVisible(std::vector<std::vector<unsigned int>> grid, 
		unsigned int row, unsigned int column) {

	unsigned int num_of_rows = grid.size(), 
		num_of_columns = grid[0].size();

	bool visible_from_right = true, 
		visible_from_left = true,
		visible_from_top = true,
		visible_from_bottom = true;

	for (unsigned int column_number = 0; 
			column_number < num_of_columns; 
			column_number++) {
		
		if (column_number != column) {
			if (grid[row][column_number] >= 
					grid[row][column]) {
				
				if (column_number > column) {
					visible_from_right = false;
				}
					
				else {
					visible_from_left = false;
				}
			}
		}
	}

	for (unsigned int row_number = 0; 
			row_number < num_of_rows; 
			row_number++) {
		
		if (row_number != row) {
			if (grid[row_number][column] >= 
					grid[row][column]) {
				
				if (row_number > row) {
					visible_from_bottom = false;
				}
					
				else {
					visible_from_top = false;
				}
			}
		}
	}

	return (visible_from_right || 
		visible_from_left || 
		visible_from_top || 
		visible_from_bottom);
}


int main() {

	//A string object that will contain the input lines.
	std::string line;

	//Three unsigned integer objects, the first two of which specify the 
	//dimensions of the grid of trees, and the third of which keeps track 
	//of the number of visible trees in the grid.
	unsigned int num_of_rows = 99, num_of_columns = 99, 
		     num_of_visible_trees = 0;

	//A vector object, containing vectors of unsigned integers, so that 
	//the whole object represents the grid of trees, with each integer 
	//representing the height of a specific tree. It is initialized with 
	//the dimensions given by "num_of_rows" and "num_of_columns".
	std::vector<std::vector<unsigned int>> grid (num_of_rows, 
			std::vector<unsigned int> (num_of_columns));


	//Here we read the input .txt file per line.
	//
	//For each input line, we convert each of the characters in the string 
	//to an (unsigned) integer and write it to the corresponding element 
	//of the "grid" object. In this way we construct the "grid" objects, 
	//representing the grid of trees given by the input .txt file.
	for (unsigned int i = 0; i < num_of_rows; i++) {

		std::cin >> line;

		for (unsigned int j = 0; j < num_of_columns; j++) {
			grid[i][j] = stoi(line.substr(j, 1));
		}
	}


	//Here we itterate over the entire "grid" object and check for each 
	//element, corresponding to a single tree in the grid of trees,
	//whether this tree would be visible from the outside, which is done 
	//by applying the "isVisbile" function. If a tree is visible from the 
	//outside, we increase the "num_of_visible_trees" integer by one.
	for (unsigned int row = 0; row < num_of_rows; row++) {
		for (unsigned int column = 0; 
				column < num_of_columns; column++) {
		
			if (isVisible(grid, row, column)) {
				num_of_visible_trees++;
			}
		}
	}


	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	std::cout << "                                    _---_              " 
		<< "                        \n"
		  << "                          _---_    (*(*)^)             " 
		  << " _---_                  \n" 
		  << "      _---_     _---_    (^(')*)  (*(^*')*)   _---_    " 
		  << "(*(')*)    _---_        \n" 
		  << "     (*(*)^)   (@(*)^)  ('(**^)*) _(*(*)')   (*(*)^)  (" 
		  << "'(**^)*)  (*(*)^)       \n" 
		  << "    (^('*@)') (*(^*')*)  (@(*)') |__|\\|/    (@(^*')*) " 
		  << " (*(*)')  (^('**)@)      \n" 
		  << "     (*(')*)   (*(*)')     \\|/    \\_\\|||     (*(*)')" 
		  << "     \\|/     ('(*)*)       \n" 
		  << "       \\|/       \\|/       |||       |\\|       \\|/ " 
		  << "      |||       \\|/         \n" 
		  << "       |||       |\\|       |||       |||       |||    " 
		  << "   |\\|       |||         \n" 
		  << "      /|/|\\     /|||\\     /|/|\\     /|||\\     /|\\|" 
		  << "\\     /|||\\     /|/|\\        \n";

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";


	std::cout << "There are " << num_of_visible_trees 
		<< " trees visibile from the outside of the grid.\n";

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	return 0;
}
