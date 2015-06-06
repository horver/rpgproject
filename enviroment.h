#ifndef _ENVIROMENT_H__
#define _ENVIROMENT_H__

#include "gameobject.h"
#include "tile.h"
#include <vector>
#include <SDL_mixer.h>

class Enviroment {
	public:
		Enviroment();
		~Enviroment();

		SDL_Renderer* getRenderer();

		void run();
		void render();
		void addObject(GameObject* obj);
		void addMap(TileMap* m);
	
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Event event;
		std::vector<GameObject*> objects;
		Mix_Music* backgroundMusic;
		TileMap* map;
		bool quit;
};



#endif