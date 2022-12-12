CXX = g++
CXXFLAGS = -std=c++17
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent04_1 advent04_2

advent04_1: advent04_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent04_2: advent04_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent04_1 advent04_2
