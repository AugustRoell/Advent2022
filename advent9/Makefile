CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent9_1 advent9_2

advent9_1: advent9_1.cpp Knot.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

advent9_2: advent9_2.cpp Knot.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

.PHONY: clean
clean:
	rm -f advent9_1 advent9_2
