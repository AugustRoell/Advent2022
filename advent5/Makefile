CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent5_1 advent5_2

advent5_1: advent5_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent5_2: advent5_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent5_1 advent5_2
