CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent02_1 advent02_2

advent02_1: advent02_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent02_2: advent02_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent02_1 advent02_2
