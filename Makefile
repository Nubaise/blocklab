CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = src/main.cpp \
      src/frontend/shell.cpp \
      src/core/engine.cpp

all: blocklab

blocklab:
	$(CXX) $(CXXFLAGS) $(SRC) -o blocklab

clean:
	rm -f blocklab
