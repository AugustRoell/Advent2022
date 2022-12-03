CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent3_1 advent3_2

advent3_1: advent3_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent3_2: advent3_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent3_1 advent3_2
