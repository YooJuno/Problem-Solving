CXX = g++
CXXFLAGS = -std=c++17 -O2

main: main.o solution.o
	$(CXX) $(CXXFLAGS) -o main main.o solution.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

solution.o: solution.cpp
	$(CXX) $(CXXFLAGS) -c solution.cpp

clean:
	rm -f *.o main
