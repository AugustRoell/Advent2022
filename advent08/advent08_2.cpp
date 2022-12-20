//Day 8 of Advent of Code 2022
//
//A program to find the largest scenic score of any tree in a grid of trees, 
//given the positions and heights of the trees in the grid. The scenic score 
//of a tree is calculated by the product of the viewing distances along the 
//axes of the grid. The viewing distance along any direction is the number of 
//trees that can be seen in that direction, so that it is 1 plus the number of 
//steps in that direction untill a tree of equal or greater height is found. 
//The 1 is added because the tree of equal or greater height is also visible. 


#include <iostream>
#include <string>
#include <vector>

typedef unsigned int UI;
typedef std::vector<UI> VUI;
typedef std::vector<VUI> VVUI;


//A function that takes as its arguments a grid of trees (represented by a 
//matrix of unsigned integers), as well as two insigned integers 
//representing the row and column of a specific tree. It will return and 
//unsigned integer representing the scenic score of that tree.
//
//This is done by four separate itterations, towards the right, left, top, and 
//bottom of the specific tree. In each of these directions, we find how many 
//trees are visible from our starting tree. Finally, we output the product of 
//these numbers of visible trees in all four directions to obtain the scenic 
//score. Note that we first check if the tree is at the edge of the grid 
//("row" or "column" equal to zero), because in that case we know its scenic 
//score will be zero without calculating all the viewing distances.
UI ScenicScore(VVUI grid, UI row, UI column) {

	if (row == 0 || column == 0) {
		return 0;
	}

	UI num_of_rows = grid.size(), 
		num_of_columns = grid[0].size(),
		visible_to_right = 0, 
		visible_to_left = 0,
		visible_to_top = 0,
		visible_to_bottom = 0;

	for (UI column_number = column + 1;
			column_number < num_of_columns; 
			column_number++) {
			
		visible_to_right++;

		if (grid[row][column_number] >= grid[row][column]) {
			break;
		}
	}

	for (int column_number = column - 1;
			column_number >= 0; 
			column_number--) {
		
		visible_to_left++;

		if (grid[row][column_number] >= grid[row][column]) {
			break;
		}
	}

	for (int row_number = row - 1;
			row_number >= 0; 
			row_number--) {
		
		visible_to_top++;

		if (grid[row_number][column] >= grid[row][column]) {
			break;
		}
	}

	for (UI row_number = row + 1;
			row_number < num_of_rows; 
			row_number++) {
		
		visible_to_bottom++;

		if (grid[row_number][column] >= grid[row][column]) {
			break;
		}
	}

	return (visible_to_right * 
		visible_to_left * 
		visible_to_top * 
		visible_to_bottom);

}


int main() {

	//A string object that will contain the input lines.
	std::string line;

	//Four unsigned integer objects, the first two of which specify the 
	//dimensions of the grid of trees, and the second two of which 
	//respectively keep track of the scenic score of each tree and the 
	//largest scenic score yet encountered.
	UI num_of_rows = 99, num_of_columns = 99, 
		     new_scenic_score,
		     max_scenic_score = 0;

	//A vector object, containing vectors of unsigned integers, so that 
	//the whole object represents the grid of trees, with each integer 
	//representing the height of a specific tree. It is initialized with 
	//the dimensions given by "num_of_rows" and "num_of_columns".
	VVUI grid (num_of_rows, VUI (num_of_columns));


	//Here we read the input .txt file per line.
	//
	//For each input line, we convert each of the characters in the string 
	//to an (unsigned) integer and write it to the corresponding element 
	//of the "grid" object. In this way we construct the "grid" objects, 
	//representing the grid of trees given by the input .txt file.
	for (UI i = 0; i < num_of_rows; i++) {

		std::cin >> line;

		for (UI j = 0; j < num_of_columns; j++) {
			grid[i][j] = stoi(line.substr(j, 1));
		}
	}


	//Here we itterate over the entire "grid" object and check for each 
	//element, corresponding to a single tree in the grid of trees,
	//whether the scenic score of this tree is greater than the greatest 
	//scenic score yet encountered. If it is, it becomes the new value of 
	//"max_scenic_score".
	for (UI row = 0; row < num_of_rows; row++) {
		for (UI column = 0; 
				column < num_of_columns; column++) {
			
			new_scenic_score = ScenicScore(grid, row, column);

			if (new_scenic_score > max_scenic_score) {
				max_scenic_score = new_scenic_score;
			}
		}
	}


	std::cout << '\n';

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

	std::cout << "The largest scenic score in this grid of trees is " 
		<< max_scenic_score << '\n';

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	return 0;
}
