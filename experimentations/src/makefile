# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11

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
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

# Clean rule
clean:
	rm -f $(EXEC)

