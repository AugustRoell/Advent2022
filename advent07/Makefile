CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent07_1 advent07_2

advent07_1: advent07_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent07_2: advent07_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent07_1 advent07_2
