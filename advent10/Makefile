CXX = g++
CXXFLAGS = -std=c++17
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent10_1 advent10_2

advent10_1: advent10_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent10_2: advent10_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent10_1 advent10_2
