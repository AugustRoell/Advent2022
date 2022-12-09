#ifndef ADVENT9_1_HPP
#define ADVENT9_1_HPP


#include<utility>
#include <string>
#include <iostream>


class Knot {

	public:
		knot(const int x = 0, const int y = 0) :
			x_(x), y_(y) {}

		std::pair<int, int> get_position() {
			std::pair<int, int> position = std::make_pair(x_, y_);
			return position;
		}

		void print_position() {
			std::cout << "(" << x_ << ", " << y_ << ")\n";
		}

	private:
		int x_;
		int y_;

		friend class Head, Tail;
};

class Head : Knot {

	public:
		void change_positon(const char direction, 
				const unsigned int amount) {
		
			if (direction == 'U') {
				y_ += amount;
			}

			else if (direction == 'R') {
				x_ += amount;
			}

			else if (direction == 'D') {
				y_ -= amount;
			}

			else if (direction == 'L') {
				x_ -= amount;
			}

			else {
				std::cout 
					<< "ERROR: The input character " 
					<< "was none of U,R,D,L\n"
			}	
		}
};

class Tail : Knot {

	public:
		void follow(Head const& head) {

			if (x_ - head.get_position()[0] < -2 ||
				x_ - head.get_position()[0] > 2) {
					
				std::cout 
					<< "ERROR: " 
					<< "Planck Length exceeded " 
					<< "along x-axis!" 
					<< '\n';
			
			}

			if (y_ - head.get_position()[1] < -2 ||
				y_ - head.get_position()[1] > 2) {
					
				std::cout 
					<< "ERROR: " 
					<< "Planck Length exceeded " 
					<< "along y-axis!" 
					<< '\n';
			}

			if ((x_ - head.get_position()[0] <= -2 || 
				x_ - head.get_position()[0] >= 2) && 
				(y_ - head.get_position()[1] <= -2 || 
				 y_ - head.get_position()[1] >= 2)) {
			
				std::cout
					<< "ERROR: "
					<< "Planck Length exceeded "
					<< "along the diagonal!"
					<< '\n';
			}

			else if (x_ == head.get_position()[0]) {

				if (y_ == head.get_position()[1] - 2) {
					y_++;
				}

				else if (y_ == head.get_position()[1] + 2) {
					y_--;
				}
			}

			else if (y_ == head.get_position()[1]) {
			
				if (x_ == head.get_position()[0] - 2) {
					x_++;
				}

				else if (x_ == head.get_position()[0] + 2) {
					x_--;
				}
			}

			else {
				
				if (y_ == head.get_position()[1] - 2) {
					y_++;
					x_ = head.get_position()[0];
				}

				else if (y_ == head.get_position()[1] + 2) {
					y_--;
					x_ = head.get_position()[0];
				}

				else if (x_ == head.get_position()[0] - 2) {
					x_++;
					y_ = head.get_position()[1];
				}

				else if (x_ == head.get_position()[0] + 2) {
					x_--;
					y_ = head.get_position()[1];
				}
			}
		}
};


#endif
