//Day 7 of Advent of Code 2022
//
//A program to find the total amount of memory occupied by directories with 
//size smaller or equal to 100000, given a filesystem structure through a 
//sequence of terminal commands and outputs.


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


int main() {
	
	//Two string objects, the first of which will contain the input lines, 
	//and the second of which will contain the path to the current working 
	//directory.
	std::string line, working_dir;

	//A vector object that will contain a sequence of paths of 
	//directories, such that the first element is the root, the last 
	//element is the current working directory, and the order is such that 
	//for any two elements at indices "i" and "i+1" the directory 
	//represented by the path at index "i+1" is inside the directory 
	//represented by the path at index "i". For example, if we are working 
	//in the directory "//dir_x/dir_y/dir_z", the vector would be 
	//{"/", "//dir_x", "//dir_x/dir_y", "//dir_x/dir_y/dir_z"}.
	std::vector<std::string> branch;

	//An unordered map object that will take as its keys the full paths to 
	//directories, and as its values the sum of the sizes of all the files 
	//contained either directly or indirectly by the directory with that 
	//path.
	std::unordered_map<std::string, unsigned int> directory_sizes;

	//An unsigned integer object that will contain the sum of all the 
	//sizes of all the directories that occupy at most 100000 memory.
	unsigned int total_size = 0;


	//Here we read the input .txt file per line.
	//
	//For each input line we check if the line contains a 
	//"change directory" command by checking if it starts with "$ cd". If 
	//it does, we change the path of the working directory to be the path 
	//of the previous working directory plus "/" plus the directory we are 
	//told to change to, and push back this new path onto the vector 
	//"branch", which tells us the paths of our current working directory 
	//and all of the directories that contain it up to and including the 
	//root. However, if the "$ cd" command is followed by "..", we instead 
	//remove the last element of the "branch" vector, since we are moving 
	//out one directory. We also check if the "branch" object is empty, 
	//which should only occur at the first input line, where we move to 
	//the root.
	//
	//If, instead, the first element of the line is a digit, the line 
	//specifies the size of a file in the current woring directory. Since 
	//such a file is also inside all the directories that contain the 
	//current working directory, we should add the size of this file to 
	//the sizes of all these directories. We do this by itterating over 
	//all the paths in the "branch" vector and adding the file size to 
	//the value in the "directory_sizes" object corresponding to each of 
	//the keys given by the elements of the "branch" vector. If such a key 
	//does not yet exist in the "directory_sizes" object we create it and 
	//give it a value equal to the file size.
	//
	//NOTE: It is important to define the lengths of the substrings 
	//containing the directory to which we have to change, and not simply 
	//take all of the string starting after "$ cd", since we get the input 
	//through "std::getline" and the end of each line contains special 
	//characters.
	while (std::getline(std::cin, line)) {

		if (line.substr(0, 4) == "$ cd") {

			if (line.substr(5, 2) == "..") {
				branch.pop_back();
			}

			else if (branch.empty()) {
				branch.push_back(line.substr(5, 
							line.length() - 6));
			}

			else {
				working_dir = branch.back();
				working_dir += "/";
				working_dir += line.substr(5, 
						line.length() - 6);
				branch.push_back(working_dir);
			}	
		}

		else if (std::isdigit(line[0])) {
			for (std::string directory : branch) {
				if (directory_sizes.count(directory) == 0) {
					directory_sizes[directory] = 
						stoi(line.substr(0, 
						line.find(' ')));
				}

				else {
					directory_sizes[directory] += 
						stoi(line.substr(0, 
						line.find(' ')));
				}
			}
		}
	}


	for (auto x : directory_sizes) {
		if (x.second <= 100000) {
			total_size += x.second;
		}
	}

	std::cout << "The total available disk space is 70000000" << "\n\n" 
		<< "The total unused disk space is " 
		<< 70000000 - directory_sizes["/"] << "\n\n" 
		<< "The total disk space taken up by directories " << '\n' 
		<< "of size 100000 and under is " << total_size << '\n';

	return 0;
}
