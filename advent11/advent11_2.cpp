//Day 11 of Advent of Code 2022
//
//A program to find the level of monkey business after an extended game of 
//keep away. In particular, each monkey in a group of monkeys decides, 
//during their turn, on the basis of your worry regarding each of your lost 
//items, modeled as a positive integer property, to which other monkey they 
//will throw the just inspected item. Depending on the monkey, the act of 
//inspecting your item increases your worry about that item. 
//
//As opposed to before, your worry is no longer floor-divided by three, so 
//that the worry integers quickly become very large. However, the only 
//relevant information contained in these integers is whether they are 
//divisible by the test integers, specific to each monkey. Therefore, after 
//every inspection, we take the worry meter modulo the least common multiple 
//(lcm) of all these test integers. Though the lcm of these integers is likely 
//simply the product of all of them, this operation still guarantees that the 
//worry meter will not exceed the square of this lcm (this follows from the 
//possible operations each inspection of a monkey can bring about). To account 
//for this still significant maximum value, we switch from unsigned integers 
//to size types to keep track of the worry levels. The resulting monkey 
//business is the product of the number of inspected items of the two most 
//active monkeys.


#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

typedef std::vector<size_t> DST;
typedef std::deque<size_t> DST;


//A function that returns the inventory of a monkey as a deque object, given 
//as input a string containing the information about the monkey's inventory.
DST ConstructInventory(std::string const& s) {
	
	std::string temp = s;
	std::string delimiter = ", ";

	std::string token;
	size_t pos = 0;

	DST inventory_deque;

	while((pos = temp.find(delimiter)) != std::string::npos) {
		token = temp.substr(0, pos);
		inventory_deque.push_back(stoi(token));
		temp.erase(0, pos + delimiter.length());
	}

	inventory_deque.push_back(stoi(temp));

	return inventory_deque;
}


//A function that, given a size type representing your old worry level about 
//an item and a string representing the way this worry level changes when the 
//current monkey inspects the item, returns a size type representing your new 
//worry level about that item.
size_t PerformOperation(std::string const& operation, size_t worry_level) {
	
	size_t new_worry_level;

	if (std::isdigit(operation[12])) {

		if (operation.substr(10, 1) == "+") {
			new_worry_level = worry_level + stoi(operation.substr(12));
		}

		else if (operation.substr(10, 1) == "*") {
			new_worry_level = worry_level * stoi(operation.substr(12));
		}

		else {
			std::cout << "ERROR: Not a defined operrant!" << '\n';
			new_worry_level = 0;
		}
	}

	else if (operation.substr(12, 3) == "old") {
		
		if (operation.substr(10, 1) == "+") {
			new_worry_level = worry_level + worry_level;
		}

		else if (operation.substr(10, 1) == "*") {
			new_worry_level = worry_level * worry_level;
		}

		else {
			std::cout << "ERROR: Not a defined operrant!" << '\n';
			new_worry_level = 0;
		}
	}

	else {
		std::cout << "ERROR: Not a defined object to operate upon!" 
			<< '\n' 
			<< operation.substr(12) 
			<< '\n';

		new_worry_level = 0;
	}

	return new_worry_level;
}


//A recursive function that returns the greatest common divisor of two input 
//integers, all rendered as size types.
size_t gcd(size_t a, size_t b) {

	if (b == 0) {
		return a;
	}

	return gcd(b, a%b);
}


//A simple function that returns the least common multiple of two input 
//integers, all rendered as size types. The function is based on the fact that 
//for two integers "a" and "b", "a*b = gcd(a, b) * lcm(a, b)".
size_t lcm(size_t a, size_t b) {

	return (a / gcd(a, b)) * b;
}


int main() {

	//A string object that will contain the input lines.
	std::string line;

	//Two unsigned integer objects, the first of which keeps track of 
	//the total number of monkeys in the game, and the second of which 
	//defines the number of rounds of the game.
	unsigned int num_of_monkeys = 0, num_of_rounds = 10000; 

	//A size type that will contain the final result.
	size_t monkey_business;

	//Five vector objects which will contain information about the 
	//progress and the dynamics of the game. 
	//
	//The "operation" vector will contain information about the way our 
	//worry level of an item changes under inspection by a specific 
	//monkey, so that the index corresponds to a monkey, and the operation 
	//is captured in the form of a string.
	//
	//The "test" vector will contain information on the criteria a 
	//specific monkey employs to decide which monkey to throw the recently 
	//inspected item to, such that they decide on the basis of whether the 
	//worry level of the inspected item is divisible by the size type at 
	//the index corresponding to this monkey.
	//
	//The "destinations" vector contains the names, as unsigned integers, 
	//of the monkeys items will be thrown to after inspection, so that, if 
	//the i-th monkey evaluates their test-criterion to true, it will 
	//throw the item to the monkey represented by the "2*i"-th element of 
	//this vector, while if they evaluate it to false, it will be thrown 
	//to the monkey represented by the "2*i + 1"-th element.
	//
	//The "inventories" vector will contain the dynamical inventories of 
	//each of the monkeys, stored as a deque of size types, such that each 
	//integer corresponds to our worry level about that item. We use a 
	//deque object for each inventory, because over the course of the game 
	//we need to add elements to the back and remove elements from the 
	//front of each inventory.
	//
	//The "activity" vector will contain size types representing the 
	//number of our items each monkey has inspected over the course of the 
	//game.
	std::vector<std::string> operation;
	VST test;
	VST destinations;
	std::vector<DST> inventories;
	VST activity;


	//Here we read the input .txt file per line.
	//
	//For each input line, we check whether the line specifies the monkey, 
	//the inventory, the operation, the test criterion, or the possible 
	//destinations, and depending on this we write the information to the 
	//relevant object defined above.
	while(std::getline(std::cin, line)) {

		if (line.length() > 1) {
		
			if (line.substr(0, 6) == "Monkey") {
				num_of_monkeys++;
			}

			else if (line.substr(2, 14) == "Starting items") {
				inventories.push_back(
					ConstructInventory(line.substr(18)));
			}

			else if (line.substr(2, 9) == "Operation") {
				operation.push_back(line.substr(13));
			}

			else if (line.substr(2, 4) == "Test") {
				test.push_back(stoi(line.substr(21)));
			}

			else if (line.substr(4, 7) == "If true") {
				destinations.push_back(stoi(line.substr(29)));
			}

			else if (line.substr(4, 8) == "If false") {
				destinations.push_back(stoi(line.substr(30)));
			}
		}
	}


	//We initialize the "activity" vector as a vector of zeros with size 
	//equal to the number of monkeys.
	for (unsigned int i = 0; i < num_of_monkeys; i++) {
		activity.push_back(0);
	}


	//We intilialize a size type which will contain the lcm of the 
	//integers in the "test" vector. Subsequently, we find this lcm 
	//iteratively, using "lcm(a, b, c) = lcm(lcm(a, b), c)"
	size_t lcm_test = test[0];
	for (unsigned int i = 1; i < num_of_monkeys; i++) {
		lcm_test = lcm(test[i], lcm_test);
	}


	//Here, we perform the game round by round.
	//
	//For each round, we iterate over the number of monkeys, so that each 
	//monkey gets one turn that round. For each monkey, we iterate over 
	//their inventory, change our worry level about each item in the 
	//specified way, and move the inspected item to the back of another 
	//monkey's inventory depending on the test criterion.
	for (unsigned int round = 1; round <= num_of_rounds; round++) {
	
		for (unsigned int monkey = 0; 
				monkey < num_of_monkeys; monkey++) {

			for (size_t worry_level : inventories[monkey]) {
				
				inventories[monkey][0] = 
					PerformOperation(operation[monkey], 
							worry_level);

				inventories[monkey][0] = 
					inventories[monkey][0] % lcm_test;

				activity[monkey]++;
				
				if (inventories[monkey][0] % 
						test[monkey] == 0) {
					
					inventories[destinations
						[monkey*2]].push_back(
						inventories[monkey][0]);
				}

				else {
				
					inventories[destinations
						[monkey*2 + 1]].push_back(
						inventories[monkey][0]);
				}

				inventories[monkey].pop_front();
			}
		}
	}


	VST temp = activity;

	sort(temp.begin(), temp.end());

	monkey_business = temp.back() * temp[temp.size() - 2];


	//Here we output the activity of each monkey, as well as the level of 
	//monkey business after the specified number of rounds.
	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	std::cout << "Monkey\t\tActivity" << '\n';

	for (unsigned int i = 0; i < num_of_monkeys; i++) {
		std::cout << i 
			<< "\t\t" 
			<< activity[i] 
			<< '\n';
	}
	
	std::cout << "\n\nThe level of monkey business (after " 
		<< num_of_rounds 
		<< " round of stuff-slinging\nsimian shenanigans) is " 
		<< monkey_business << '\n';

	std::cout << "\n=====================================================" 
		<< "==========================\n\n";

	return 0;
}
