//Day 7 of Advent of Code 2022
//
//A program to find the total amount of memory occupied by the smallest 
//directory which, if removed, would bring up the unused disc space to at 
//least 30000000 out of 70000000, given a filesystem structure through a 
//sequence of terminal commands and outputs.


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


int main() {
	
	//Three string objects, the first of which will contain the input lines, 
	//the second of which will contain the path to the current working 
	//directory, and the third of which will contain the path to the 
	//smallest directory which, if removed, would result in an unused disc 
	//space of at least 30000000.
	std::string line, working_dir, smallest_dir_path;

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

	//An unsigned integer object that will contain the size of the 
	//smallest directory which, if removed, would result in an unused disc 
	//space of at least 30000000. We initialize it to the total available 
	//disc space in order to have a reference point to compare the sizes 
	//of the directories.
	unsigned int smallest_dir_size = 70000000;


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
	//NOTE: It is important to define the lengths of the substrings 
	//containing the directory to which we have to change, and not simply 
	//take all of the string starting after "$ cd", since we get the input 
	//through "std::getline" and the end of each line contains special 
	//characters.
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


	//An unsigned integer object that represents the unused disc space.
	unsigned int unused_space = 70000000 - directory_sizes["/"];

	//Here, we itterate over elements of the unordered map containing the 
	//information about the sizes of all the directories in order to find 
	//the smallest directory such that if that directory is removed we 
	//would end up with at least 30000000 unused disc space.
	for (auto x : directory_sizes) {
		if (x.second >= 30000000 - unused_space 
				&& x.second < smallest_dir_size) {
			smallest_dir_path = x.first;
			smallest_dir_size = x.second;
		}
	}

	std::cout << "The total available disk space is 70000000" << "\n\n" 
		<< "The total unused disk space is " << unused_space << "\n\n" 
		<< "The smallest directory which, if removed, would result " 
		<< "in an unused disk space" << '\n'
		<< "of at least 30000000 can be found at: " << "\n\n"
		<< smallest_dir_path << "\n\n" 
		<< "and has a size of " << smallest_dir_size << '\n';


	return 0;
}
