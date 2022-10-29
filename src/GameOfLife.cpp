#include <stdio.h>

#include <Map.hpp>

int main(int argc, char const *argv[]) {
    Map m(5, 5);
	m.birthCell(2, 2);
	m.printMap(false);
	m = m.advanceGeneration();
	m.printMap(false);
    return 0;
}
