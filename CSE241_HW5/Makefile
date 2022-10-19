target : test

test: main.cpp AbstractHex.cpp AbstractHex.h HexVector.h HexVector.cpp HexArray1D.h HexArray1D.cpp HexAdapter.h HexAdapter.cpp functions.cpp functions.h
	g++ main.cpp -std=c++11 AbstractHex.cpp HexVector.cpp HexArray1D.cpp HexAdapter.cpp functions.cpp -o test
	./test
