#ifndef _PLAYER_H__
#define _PLAYER_H__

#include "character.h"

class Player : public Character {
	public:

		Player(int nx, int ny, int nspeed) : Character(nx, ny), speed(nspeed) {};

		float getHealth() const;

		void step(SDL_Event* event, bool collided, GameObject& other);
		void move();
		void draw();

	private:
		float health;
		int speed;
};

#endif