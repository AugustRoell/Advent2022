CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent09_1 advent09_2

advent09_1: advent09_1.cpp Knot.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

advent09_2: advent09_2.cpp Knot.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

.PHONY: clean
clean:
	rm -f advent09_1 advent09_2
