#ifndef ADVENT9_1_HPP
#define ADVENT9_1_HPP


#include <utility>
#include <string>
#include <iostream>


class Knot {

	public:
		Knot(const int x = 0, const int y = 0) :
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

	friend class Head;
	friend class Tail;
};

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

class Tail : public Knot {

	public:
		void follow(Head const& head) {

			if (x_ - head.x_ < -2 ||
				x_ - head.x_ > 2) {
					
				std::cout 
					<< "ERROR: " 
					<< "Planck Length exceeded " 
					<< "along x-axis!" 
					<< '\n';
			
			}

			if (y_ - head.y_ < -2 ||
				y_ - head.y_ > 2) {
					
				std::cout 
					<< "ERROR: " 
					<< "Planck Length exceeded " 
					<< "along y-axis!" 
					<< '\n';
			}

			if ((x_ - head.x_ <= -2 || 
				x_ - head.x_ >= 2) && 
				(y_ - head.y_ <= -2 || 
				 y_ - head.y_ >= 2)) {
			
				std::cout
					<< "ERROR: "
					<< "Planck Length exceeded "
					<< "along the diagonal!"
					<< '\n';
			}

			else if (x_ == head.x_) {

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
				
				if (y_ == head.y_ - 2) {
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
