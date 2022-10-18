#include <memory.h>
#include <stdio.h>

#include <Map.hpp>

int main(int argc, char const *argv[]) {
    Map m(5, 5);
	m.birthCell(0, 0);
	printf("%u the\n", m.getCell(0,0));
	m.birthCell(1, 1);
	printf("%u the\n", m.getCell(0,0));
    return 0;
}
