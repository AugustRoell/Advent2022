CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent6_1 advent6_2

advent6_1: advent6_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent6_2: advent6_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent6_1 advent6_2
