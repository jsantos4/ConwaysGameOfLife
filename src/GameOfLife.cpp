#include <stdio.h>

#include <Map.hpp>

int main(int argc, char const *argv[]) {
    Map m(5, 5);
	m.birthCell(2, 1);
	m.birthCell(2, 2);
	m.birthCell(2, 3);
	m.printMap(true);
	m.advanceGeneration();
	m.printMap(true);
	m.advanceGeneration();
	m.printMap(true);
    return 0;
}
