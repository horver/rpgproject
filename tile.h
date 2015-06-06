#ifndef _TILE_H__
#define _TILE_H__

#include "gameobject.h"
#include <fstream>
#include <algorithm> 
#include <vector>

enum DIRECTIONS {NONE, DOWN, LEFT, RIGHT, UP};
enum TileTYPE {FIELD, BLOCK, INTERACTIVE, PLAYER};

struct Tile {
	int numOfTile;
	TileTYPE type;
};

class TileMap {
	public:
		TileMap(int w, int h, const char* fname, SDL_Renderer* renderer, const char* mapfile, int layersNum);
		~TileMap();

		Tile* getTile(int x, int y, int layer) const;
		void setTile(int x, int y, int layer, TileTYPE type, GameObject* obj);
		int getLayers() const;
		int getWidth() const;
		int getHeight() const;
		void setCamera(int followX, int followY);
		SDL_Rect* getCamera();

		void draw(SDL_Renderer* renderer);

	private:
		int width;
		int height;
		Sprite* tiles;
		std::vector<Tile**> layers;
		SDL_Rect camera;
};

#endif