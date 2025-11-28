CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

OUT = juego_gato

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(OUT)

clean:
	rm -f $(OBJ) $(OUT)
