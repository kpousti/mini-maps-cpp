CXX=g++
CXXFLAGS=-std=c++17 -O2 -Wall -Wextra

all: mini_maps

mini_maps: main.cpp
$(CXX) $(CXXFLAGS) main.cpp -o mini_maps

run: mini_maps
./mini_maps < examples/sample_input.txt

clean:
rm -f mini_maps *.o
