#include <Map.hpp>
#include <memory.h>

class Map {

	int width, height;
	unsigned char** cells;

	Map::Map(int w, int h) {
		width = w;
		height = h;
		//Gonna get kinda fucked up here, cells is a new array "width" long and 0-set each array within cells[x]
		cells = new unsigned char*[width];
		for (int x = 0; x < width; x++) {
			cells[x] = new unsigned char;
			memset(cells[x], 0, height);
		}
	}

	Map::~Map() {
		for (int x = 0; x < width; x++) {
			delete[] cells[x];
		}
		delete[] cells;
	}

	void Map::birthCell(int x, int y) {

		cells[x][y] |= 1;

		//Increment all neighboring cells neighbor counter if neighbor exists
		if (x < width)
			cells[x + 1][y] += 2;
		if (x > 0)
			cells[x - 1][y] += 2;
		if (y < height)
			cells[x][y + 1] += 2;
		if (y > 0)
			cells[x][y - 1] += 2;
		if (x < width && y < height)
			cells[x + 1][y + 1] += 2;
		if (x < width && y > 0)
			cells[x + 1][y - 1] += 2;
		if (x > 0 && y < height)
			cells[x - 1][y + 1] += 2;
		if (x > 0 && y > 0)
			cells[x - 1][y - 1] += 2;
	}


	void Map::killCell(int x, int y) {

		cells[x][y] &= ~1;

		//Increment all neighboring cells neighbor counter if neighbor exists
		if (x < width)
			cells[x + 1][y] -= 2;
		if (x > 0)
			cells[x - 1][y] -= 2;
		if (y < height)
			cells[x][y + 1] -= 2;
		if (y > 0)
			cells[x][y - 1] -= 2;
		if (x < width && y < height)
			cells[x + 1][y + 1] -= 2;
		if (x < width && y > 0)
			cells[x + 1][y - 1] -= 2;
		if (x > 0 && y < height)
			cells[x - 1][y + 1] -= 2;
		if (x > 0 && y > 0)
			cells[x - 1][y - 1] -= 2;
	}

	unsigned char Map::getCell(int x, int y) {
		return cells[x][y];
	}
};