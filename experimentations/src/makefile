# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11

# Source files
SRCS := Main.cpp GraphAdjListVL.cpp GraphAdjListVUS.cpp GraphAdjMatrixVV.cpp Matrix.cpp GraphFiller.cpp
EXEC := ../Main.exe

.PHONY: all clean optimize

# Default target
all: $(EXEC)

# Target to compile with -O3 optimization level
optimize: CXXFLAGS += -O3
optimize: $(EXEC)

# Compilation rule
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

# Clean rule
clean:
	rm -f $(EXEC)
