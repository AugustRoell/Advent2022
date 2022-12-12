CXX = g++
CXXFLAGS = -std=c++17
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent08_1 advent08_2

advent08_1: advent08_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent08_2: advent08_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent08_1 advent08_2
