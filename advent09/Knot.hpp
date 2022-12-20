#ifndef ADVENT9_1_HPP
#define ADVENT9_1_HPP


#include <utility>
#include <string>
#include <iostream>

typedef std::pair<int, int> P;


//A super class that contains basic member for accessing the relevant 
//information. Each "Knot" object is represented by a pair of integers, 
//which can be accessed in the form of a pair, representing the coordinates 
//of the knot with respect to the origin on the square lattice.
class Knot {

	public:
		Knot(const int x = 0, const int y = 0) :
			x_(x), y_(y) {}

		P get_position() {
			P position = std::make_pair(x_, y_);
			return position;
		}

		void print_position() {
			std::cout << "(" << x_ << ", " << y_ << ")\n";
		}

	private:
		int x_;
		int y_;

	friend class Head;
	friend class Tail;
};


//A derived class representing the head knot on the rope. Its position can be 
//changed in steps of one along the axes of the lattice.
class Head : public Knot {

	public:
		void change_position(const char direction) {
		
			if (direction == 'U') {
				y_++;
			}

			else if (direction == 'R') {
				x_++;
			}

			else if (direction == 'D') {
				y_--;
			}

			else if (direction == 'L') {
				x_--;
			}

			else {
				std::cout 
					<< "ERROR: The input character " 
					<< "was none of U,R,D,L\n";
			}	
		}

	friend class Tail;
};


//A derived class representing a knot that follows the movement of the knot 
//ahead of it.
class Tail : public Knot {

	public:
		void follow(Knot const& head) {

			if (x_ == head.x_) {

				if (y_ == head.y_ - 2) {
					y_++;
				}

				else if (y_ == head.y_ + 2) {
					y_--;
				}
			}

			else if (y_ == head.y_) {
			
				if (x_ == head.x_ - 2) {
					x_++;
				}

				else if (x_ == head.x_ + 2) {
					x_--;
				}
			}

			else {
				if (x_ == head.x_ - 2 && 
						y_ == head.y_ - 2) {
					
					x_++;
					y_++;
				}

				else if (x_ == head.x_ - 2 && 
						y_ == head.y_ + 2) {
				
					x_++;
					y_--;
				}

				else if (x_ == head.x_ + 2 && 
						y_ == head.y_ + 2) {
				
					x_--;
					y_--;
				}

				else if (x_ == head.x_ + 2 && 
						y_ == head.y_ - 2) {
				
					x_--;
					y_++;
				}

				else if (y_ == head.y_ - 2) {
					y_++;
					x_ = head.x_;
				}

				else if (y_ == head.y_ + 2) {
					y_--;
					x_ = head.x_;
				}

				else if (x_ == head.x_ - 2) {
					x_++;
					y_ = head.y_;
				}

				else if (x_ == head.x_ + 2) {
					x_--;
					y_ = head.y_;
				}
			}
		}
};


#endif
