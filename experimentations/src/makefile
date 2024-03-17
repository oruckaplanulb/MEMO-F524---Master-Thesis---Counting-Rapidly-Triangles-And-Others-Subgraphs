# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11 -I"D:/msys64/OpenBLAS/include"
LDFLAGS := -L"D:/msys64/OpenBLAS/lib" -lopenblas

# Source files
SRCDIR := sources
SRCS := $(wildcard $(SRCDIR)/*.cpp)
EXEC := ../AAMain.exe

.PHONY: all clean optimize

# Default target
all: $(EXEC)

# Target to compile with -O3 optimization level
optimizeO3: CXXFLAGS += -O3
optimizeO3: $(EXEC)

optimizeO2: CXXFLAGS += -O2
optimizeO2: $(EXEC)

optimizeO1: CXXFLAGS += -O1
optimizeO1: $(EXEC)

# Compilation rule
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(EXEC)

