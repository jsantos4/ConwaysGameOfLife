#include <Map.hpp>
#include <memory.h>
#include <stdio.h>

int width, height;
unsigned char **currentGen, **lastGen;

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
	if (y < height - 1)
		currentGen[x][y + 1] += 2;
	if (y > 0)
		currentGen[x][y - 1] += 2;
			
		//Check  left and right columns for boundaries
	if (x < width - 1){
		currentGen[x + 1][y] += 2;
		
		if (y < height - 1)
			currentGen[x + 1][y + 1] += 2;
		if (y > 0)
			currentGen[x + 1][y - 1] += 2;
	}

	if (x > 0) {
		currentGen[x - 1][y] += 2;

		if (y < height - 1)
			currentGen[x - 1][y + 1] += 2;
		if (y > 0)
			currentGen[x - 1][y - 1] += 2;
	}
}


void Map::killCell(int x, int y) {

	currentGen[x][y] &= ~1;

	//Decrement all neighboring currentGen neighbor counter if neighbor exists
		//Check up-center and down-center for boundaries
	if (y < height - 1)
		currentGen[x][y + 1] -= 2;
	if (y > 0)
		currentGen[x][y - 1] -= 2;
		
		//Check  left and right columns for boundaries
	if (x < width - 1){
		currentGen[x + 1][y] -= 2;
		
		if (y < height - 1)
			currentGen[x + 1][y + 1] -= 2;
		if (y > 0)
			currentGen[x + 1][y - 1] -= 2;
	}

	if (x > 0) {
		currentGen[x - 1][y] -= 2;

		if (y < height - 1)
			currentGen[x - 1][y + 1] -= 2;
		if (y > 0)
			currentGen[x - 1][y - 1] -= 2;
	}
}

void Map::printMap(bool state) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			state ? printf("%d ", currentGen[i][j] & 1) : printf("%d ", currentGen[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void Map::advanceGeneration() {
	lastGen = currentGen;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (lastGen[i][j] % 2 != 0) {
				if ((lastGen[i][j] >> 1) < 2 || (lastGen[i][j] >> 1) > 3)
					killCell(i, j);		
			} else {
				if ((lastGen[i][j] >> 1) == 3)
					birthCell(i, j);
			}
		}
	}
}