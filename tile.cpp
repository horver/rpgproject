#include "tile.h"

TileMap::TileMap(int w, int h, const char* fname, SDL_Renderer* renderer, const char* mapfile, int layersNum) {
	int maxTiles = std::max(w/tileSize, h/tileSize);
	std::ifstream file(mapfile);
	
	width = w;
	height = h;
	camera.x = 0;
	camera.y = 0;
	camera.w = screenWidth;
	camera.h = screenHeight;

	tiles = new Sprite(w*tileSize, h*tileSize);
	tiles->setRenderer(renderer);
	tiles->loadImage(fname);

	if (file.is_open()) {
		while (file.good()) {
			for (int layer = 0; layer < layersNum; ++layer) {
				Tile** map = new Tile*[h];
				for (int i = 0; i < h; ++i) {
					map[i] = new Tile[w];
				}
				for (int i = 0; i < h; ++i) {
					for (int j = 0; j < w; ++j) {
						file >> map[i][j].numOfTile;
						if (map[i][j].numOfTile > 15) {
							map[i][j].type = BLOCK;
							if (map[i][j].numOfTile == 8)
								map[i][j].type = INTERACTIVE;
						} else {
							map[i][j].type = FIELD;
						}
					}
				}
				layers.push_back(map);
			}
		}
	} else {
		std::cerr << "Cant open map file." << std::endl;
	}
}

TileMap::~TileMap() {
	for (std::vector<Tile**>::iterator map = layers.begin(); map != layers.end(); ++map) {
		for (int i = 0; i < height; ++i) {
			delete [] (*map)[i];
		}
		delete [] (*map);
	}
}

Tile* TileMap::getTile(int x, int y, int layer) const {
	Tile** tmpmap = layers[layer];
	return &tmpmap[y][x];
}

int TileMap::getLayers() const {
	return layers.size();
}

int TileMap::getWidth() const {
	return width;
}

int TileMap::getHeight() const {
	return height;
}

void TileMap::setCamera(int followX, int followY) {
	//I dunno wai, but its works! \o/
	camera.x = (followX + 32/2) - screenWidth/2;
	camera.y = (followY + 49/2) - screenWidth/2;

	if (camera.x < 0) {
		camera.x = 0;
	}

	if (camera.y < 0) {
		camera.y = 0;
	}
	
	if (camera.x > width*tileSize - camera.w) {
		camera.x = width*tileSize - camera.w;
	}

	if (camera.y > height*tileSize - camera.h) {
		camera.y = height*tileSize - camera.h;
	}
}

SDL_Rect* TileMap::getCamera() {
	return &camera;
}

void TileMap::draw(SDL_Renderer* renderer) {
	for (std::vector<Tile**>::iterator map = layers.begin(); map != layers.end(); ++map) {
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				Tile tmpTile = (*map)[i][j];
				int srcX = ((tmpTile.numOfTile)%(tiles->getImgWidth()/tileSize))*tileSize;
				int srcY =  ((tmpTile.numOfTile)/(tiles->getImgWidth()/tileSize))*tileSize;
				tiles->draw(j*tileSize - camera.x, i*tileSize - camera.y, srcX, srcY, 32);
			}
		}
	}
}