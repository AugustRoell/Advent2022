CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent2_1 advent2_2

advent2_1: advent2_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent2_2: advent2_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent2_1 advent2_2
