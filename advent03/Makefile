CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent03_1 advent03_2

advent03_1: advent03_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent03_2: advent03_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent03_1 advent03_2
