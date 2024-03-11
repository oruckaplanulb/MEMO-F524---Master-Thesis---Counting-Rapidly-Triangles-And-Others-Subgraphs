# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11 -I"D:/msys64/OpenBLAS/include"
LDFLAGS := -L"D:/msys64/OpenBLAS/lib" -lopenblas

# Source files
SRCDIR := sources
SRCS := $(wildcard $(SRCDIR)/*.cpp)
EXEC := ../Main.exe

.PHONY: all clean optimize

# Default target
all: $(EXEC)

# Target to compile with -O3 optimization level
optimize: CXXFLAGS += -O3
optimize: $(EXEC)

# Compilation rule
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(EXEC)

