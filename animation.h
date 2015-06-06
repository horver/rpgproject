#ifndef _ANIMATION_H__
#define _ANIMATION_H__

#include "sprite.h"

class Animation {
	public:
		Animation(Sprite* nspr, int srcX, int srcY, int nframeWidth, int nframeHeight, int nframeNumber, float nanimationSpeed);
		~Animation();

		int getFrameNumber() const;
		int getCurrentFrame() const;
		void setCurrentFrame(int num);

		void tick();
		void draw(int x, int y, int isPlaying, float angle = 0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	private:
		Sprite* spr;
		SDL_Rect* clips;
		int frameWidth;
		int frameHeight;
		int frameNumber;
		int currentFrame;
		float animationSpeed;
		int startTime;
		int deltaTime;
};

#endif
