CXX = g++
CXXFLAGS = -std=c++17
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent11_1 advent11_2

advent11_1: advent11_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent11_2: advent11_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent11_1 advent11_2
