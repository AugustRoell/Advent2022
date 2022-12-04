CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent4_1 advent4_2

advent4_1: advent4_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent4_2: advent4_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent4_1 advent4_2
