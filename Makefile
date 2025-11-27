CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

SRC = main.cpp
HDR = FuncionesJuegoGato.h

OUT = juego_gato

all: $(OUT)

$(OUT): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
