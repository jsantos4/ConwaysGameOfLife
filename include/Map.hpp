#ifndef MAP_H
#define MAP_H

class Map {
	private:
		int width, height;
		unsigned char **currentGen, **lastGen;
	public:
		Map(int width, int height);
		~Map();
		void birthCell(int x, int y);
		void killCell(int x, int y);
		void printMap(bool state);
		void advanceGeneration();
};

#endif