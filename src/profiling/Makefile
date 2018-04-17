CXX=g++-7
CXXFLAGS= -pg -g -Wall -Wextra -pthread -std=c++17

all:
	$(CXX) $(CXXFLAGS) ../math/Number.cpp profiling.cpp -o profiling -lm
    
generate:
	$(CXX) filegen.cpp -o filegen
