CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent7_1 advent7_2

advent7_1: advent7_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent7_2: advent7_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent7_1 advent7_2
