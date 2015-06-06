#ifndef _GAMEOBJECT_H__
#define _GAMEOBJECT_H__

#include "sprite.h"
#include "consts.h"

class GameObject {
	public:
		GameObject() : x(0), y(0) {};
		GameObject(int nx, int ny);
		virtual ~GameObject();

		Sprite* getSprite();
		int getX() const;
		int getY() const;
		int getTileX(int radius = 0) const;
		int getTileY(int radius = 0) const;
		void setX(int nx);
		void setY(int ny);
		SDL_Rect* getBoundBox();
		void setBoundBox(int x, int y);

		void createSprite(int w, int h, const char* fileName, SDL_Renderer* nrend);
		void destroySprite();
		bool checkCollision(SDL_Rect* a, SDL_Rect* b) const;
		virtual void draw();
		virtual void step(SDL_Event* event, bool collided, GameObject& other);
		virtual void move();
		virtual void interaction();

	private:
		Sprite* sprite;
		int x;
		int y;
		SDL_Rect boundBox;
};

#endif