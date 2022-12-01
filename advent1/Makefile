CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent1_1 advent1_2

advent1_1: advent1_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent1_2: advent1_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent1_1 advent1_2
