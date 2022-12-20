//Day 12 of Advent of Code 2022
//
//A program to find the shortest path through a height profile map from a 
//starting place to an ending place. In particular, given a .txt file with 
//characters on a 2D grid representing the height of each grid point (where 
//height is measured from 'a' to 'z' with 'z' one higher than 'y', one higher 
//than 'x' etc.), and the rule that we can only traverse from one grid point 
//to one of its horizontal or vertical neighbors if that neighbor is at most 
//one higher than the grid point we are currently on, we need to find the 
//shortest path between a set of starting points and a given ending point, 
//adhering to this rule.
//
//In outline, this is done by generating a directed graph using the height 
//profile and the previously stated rule, so that node X is connected to node 
//Y iff X and Y are neighbors and the height of Y is at most one higher than 
//the height of X. This results in an unweighted directed graph, such that 
//each link has magnitude 1. On this graph we then apply Dijkstra's algorithm 
//to find the shortest path.
//
//NOTE: In this program, we largely represent the nodes as natural numbers, 
//such that the node in the top left of the grid is node 0, one to the right 
//we have node 1, one further to the right node 2, etc. , untill we reach node 
//W-1 at the end of the top row, after which we name the first node of the 
//second row W. Effectively we chain the rows after one another and count from 
//left to right, which gives an easy bijection from the 2D grid to the natural 
//numbers. Instead, one could also work exclusively with 2D coordinates 
//(pairs), but in that case one would need to implement a hash function for 
//the unordered map for it to take pairs as keys.


#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#include <set>


typedef std::vector<int> VI;
typedef std::unordered_map<int, std::vector<int>> M;
typedef std::pair<int, int> P;
typedef std::vector<P> VP;
typedef std::vector<VP> VVP;
typedef std::vector<char> VC;
typedef std::vector<VC> VVC;
typedef std::pair<int, P> PIP;


//A utility function to switch between the integer and the coordinate 
//representation of the nodes. It takes as input an integer representing a 
//node in the graph, as well as the width of the grid, and outputs the 
//coordinate representation of that node.
P int_to_coordinate(int n, int num_columns) {

	P coordinate = {n%num_columns, n/num_columns};
	return coordinate;
}

//A utility function to switch between the coordinate and the integer 
//representation of the nodes. It takes as input a pair representing a node 
//int the graph, as well as the width of the grid, and outputs the integer 
//representation of that node.
int coordinate_to_int(P coordinate, int num_columns) {

	int n = coordinate.first + coordinate.second*num_columns;
	return n;
}


//An implementation of Dijkstra's algorithm to find the shortest path between 
//a set of starting nodes and any other node in a graph. Obviously this could 
//be optimized in the case where we are only interested in one ending node by 
//breaking out of the iteration once we reach the desired node. In that case 
//we could additionally apply a heuristic using a priority queue to probably 
//reach the node faster. We do not do so here, so that the distances to all 
//nodes can be retrieved in constant time, in case we are interested in any 
//other paths.
//
//The function takes in a vector of integers representing the starting nodes, 
//two integers representing the linear dimensions of the grid, and an 
//unordered map object representing the graph. It outputs a vector of 
//integers, such that each integer represents the minimum distance from the 
//start nodes to the node represented by the index of the integer in the 
//output vector.
VI DijkstraAlgorithm(VI start, int num_rows, int num_columns, M graph) {

	const int num_nodes = num_rows*num_columns;
	VI distances(num_nodes, num_nodes);
	std::set<P> set_length_node;

	for (int node : start) {
		distances[node] = 0;
		set_length_node.insert(P(0, node));
	}

	while (!set_length_node.empty()) {
	
		P top = *set_length_node.begin();
		set_length_node.erase(set_length_node.begin());

		int current_node = top.second;

		for (int neighbor : graph[current_node]) {
			
			if (distances[neighbor] > 
				distances[current_node] + 1) {
				
				if (distances[neighbor] != num_nodes) {
					set_length_node.erase(
					set_length_node.find(
					P(distances[neighbor],neighbor)));
				}

				distances[neighbor] = 
					distances[current_node] + 1;

				set_length_node.insert(
					P(distances[neighbor], neighbor));
			}
		}
	}

	return distances;
}


int main() {

	//A string object that will contain the input lines.
	std::string line;

	//A vector object containing vectors of characters, such that each 
	//character is read from the input .txt file and represents a height, 
	//each subvector contains all the characters on one line of the input 
	//file, and the supervector contains all the lines of the input file.
	VVC height_map;

	//An unordered map object that will contain the graph generated by the 
	//input .txt file and the rule for traversal stated in the 
	//introduction. Each key object is an integer representing a node in 
	//the graph, and each value is a vector containing integers 
	//representing nodes that are connected to the key node.
	M directed_graph;

	//Two size type objects that represent the linear dimensions of the 2D 
	//grid.
	size_t num_rows, num_columns;

	//A pair object representing the coordinates of the end node, as well 
	//as a vector of integers representing the starting nodes, as given by 
	//the input.
	P end;
	VI start;


	//Here we read the input .txt file per line.
	//
	//For each character in a given line, we check if the character is 
	//either lower or upper case, and if it is either, we add it to a 
	//temporary vector object. Once we finish iterating over the 
	//characters in the line, we append the temporary vector object to the 
	//"height_map" vector.
	while (std::getline(std::cin, line)) {

		VC line_heights = {};

		for (char c : line) {

			if (islower(c) or isupper(c)) {
				line_heights.push_back(c);
			}
		}

		height_map.push_back(line_heights);
	}

	//Now that we have loaded in the height map, we define the linear 
	//dimensions of the grid.
	num_rows = height_map.size();
	num_columns = height_map[0].size();

	//Three temporary objects to simplify generating the graph form the 
	//height map. The vector "connections" will hold all the nodes 
	//connected to the node under consideration. The character 
	//"current_height" will represent the height of the node under 
	//consideration. We do not simply refer to the character at the 
	//respective index in the "height_map" object because the start and 
	//end nodes are given as 'S' and 'E' respectively, while their heights 
	//are 'a' and 'z'. Finally, the integer "n" gives a transformation 
	//from the iteration indices to the integer name of the current node.
	VI connections;
	char current_height;
	int n;

	//Here we generate the graph.
	for (unsigned int i = 0; i < num_rows; i++) {
		for (unsigned int j = 0; j < num_columns; j++) {

			connections = {};
			n = i*num_columns + j;

			if (height_map[i][j] == 'S') {
				current_height = 'a';
				start.push_back(n);
			}

			else if (height_map[i][j] == 'E') {
				current_height = 'z';
				end = P(j,i);
			}

			else {
				current_height = height_map[i][j];
			}
			

			if (j > 0 && current_height >= 
					height_map[i][j-1] - 1) {
				
				connections.push_back(n-1);
			}
			
			if (j < num_columns - 1 && current_height >=
					height_map[i][j+1] - 1) {
				
				connections.push_back(n+1);
			}
			
			if (i > 0 && current_height >= 
					height_map[i-1][j] - 1) {
				
				connections.push_back(n-num_columns);
			}
			
			if (i < num_rows - 1 && current_height >=
					height_map[i+1][j] - 1) {
				
				connections.push_back(n+num_columns);
			}

			directed_graph[n] = connections;
		}
	}


	//We transform the end node from its coordinate representation to its 
	//integer representation and apply the "DijkstraAlgorithm" function to 
	//calculate the minimal distances from the start nodes to all others.
	int end_int = coordinate_to_int(end, num_columns);
	VI distances = DijkstraAlgorithm(start, num_rows, num_columns, 
			directed_graph);	


	std::cout << "Minimum distance from start to end is " 
		<< distances[end_int] << "\n\n";

	return 0;
}
