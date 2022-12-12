CXX = g++
CXXFLAGS = -std=c++17
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent01_1 advent01_2

advent01_1: advent01_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent01_2: advent01_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent01_1 advent01_2
