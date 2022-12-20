CXX = g++
CXXFLAGS = -std=c++17
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3 -march=native

.PHONY: all
all : advent12_1 advent12_2

advent12_1: advent12_1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

advent12_2: advent12_2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f advent12_1 advent12_2
