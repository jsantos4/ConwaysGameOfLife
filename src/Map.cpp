#include <Map.hpp>
#include <memory.h>
#include <stdio.h>

int width, height;
unsigned char** currentGen;

Map::Map(int w, int h) {
	width = w;
	height = h;
	//Gonna get kinda fucked up here, currentGen is a new array "width" long and 0-set each array within currentGen[x]
	currentGen = new unsigned char*[width];
	for (int x = 0; x < width; x++) {
		currentGen[x] = new unsigned char;
		memset(currentGen[x], 0, height);
	}
}

Map::~Map() {
	for (int x = 0; x < width; x++) {
		delete[] currentGen[x];
	}
	delete[] currentGen;
}

void Map::birthCell(int x, int y) {

	currentGen[x][y] |= 1;

	//Increment all neighboring currentGen neighbor counter if neighbor exists
		//Check up-center and down-center for boundaries
	if (y < height)
		currentGen[x][y + 1] += 2;
	if (y > 0)
		currentGen[x][y - 1] += 2;
		
		//Check  left and right columns for boundaries
	if (x < width){
		currentGen[x + 1][y] += 2;
		
		if (y < height)
			currentGen[x + 1][y + 1] += 2;
		if (y > 0)
			currentGen[x + 1][y - 1] += 2;
	}

	if (x > 0) {
		currentGen[x - 1][y] += 2;

		if (y < height)
			currentGen[x - 1][y + 1] += 2;
		if (y > 0)
			currentGen[x - 1][y - 1] += 2;
	}
}


void Map::killCell(int x, int y) {

	currentGen[x][y] &= ~1;

	//Decrement all neighboring currentGen neighbor counter if neighbor exists
		//Check up-center and down-center for boundaries
	if (y < height)
		currentGen[x][y + 1] -= 2;
	if (y > 0)
		currentGen[x][y - 1] -= 2;
		
		//Check  left and right columns for boundaries
	if (x < width){
		currentGen[x + 1][y] -= 2;
		
		if (y < height)
			currentGen[x + 1][y + 1] -= 2;
		if (y > 0)
			currentGen[x + 1][y - 1] -= 2;
	}

	if (x > 0) {
		currentGen[x - 1][y] -= 2;

		if (y < height)
			currentGen[x - 1][y + 1] -= 2;
		if (y > 0)
			currentGen[x - 1][y - 1] -= 2;
	}
}

bool Map::getCell(int x, int y) {
	return currentGen[x][y] % 2 == 1;
}

void Map::printMap(bool state) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			state ? printf("%d ", this->getCell(i, j)) : printf("%u ", currentGen[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

Map Map::advanceGeneration() {
	Map nextGen(width, height);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (currentGen[i][j] % 2 != 0) {
				if ((currentGen[i][j] >> 1) < 2 || (currentGen[i][j] >> 1) > 3)
					nextGen.killCell(i, j);			
			} else {
				if ((currentGen[i][j] >> 1) == 2 || (currentGen[i][j] >> 1) == 3)
					nextGen.birthCell(i, j);		
			}
		}
	}

	return nextGen;
}