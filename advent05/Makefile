CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent05_1 advent05_2

advent05_1: advent05_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent05_2: advent05_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent05_1 advent05_2
