#ifndef _CHARACTER_H__
#define _CHARACTER_H__

#include "animation.h"
#include "gameobject.h"
#include "tile.h"
#include "dialog.h"
#include <map>

enum STATES {IDLE, MOVING, BLOCKED, INTERACT};

class Character : public GameObject {
	public:
		Character(int nx, int ny);
		virtual ~Character();

		void addAnimation(Animation* anim, int type);
		Animation* getAnimation(int which);
		DIRECTIONS getDirection() const;
		STATES getState() const;
		void setDirection(DIRECTIONS dir);
		void setState(STATES nstate);
		void setMap(TileMap* tilemap);
		TileMap* getMap();

		virtual void step(SDL_Event* event, bool collided, GameObject& other);
		virtual void move();
		virtual void draw();

	private:
		std::map<int, Animation*> animations;
		DIRECTIONS direction;
		STATES state;
		TileMap* map;
};

#endif