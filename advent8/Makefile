CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent8_1 advent8_2

advent8_1: advent8_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent8_2: advent8_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent8_1 advent8_2
