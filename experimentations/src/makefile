CXX = g++
CXXFLAGS = -std=c++11

SRCS = Main.cpp GraphAdjacencyListBased.cpp GraphAdjacencyMatrixBased.cpp Matrix.cpp GraphFiller.cpp
EXEC = ../Main.exe

all: $(EXEC)

$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

clean:
	rm -f $(EXEC)
