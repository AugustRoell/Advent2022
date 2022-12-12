CXX = g++
CXXFLAGS = -std=c++17
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent06_1 advent06_2

advent06_1: advent06_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent06_2: advent06_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent06_1 advent06_2
