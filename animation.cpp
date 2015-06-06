#include "animation.h"

Animation::Animation(Sprite* nspr, int srcX, int srcY, int nframeWidth, int nframeHeight, int nframeNumber, float nanimationSpeed) {
	spr = nspr;
	frameWidth = nframeWidth;
	frameHeight = nframeHeight;
	frameNumber = nframeNumber;
	animationSpeed = nanimationSpeed;
	clips = new SDL_Rect[nframeNumber];
	for (int i = 0; i < nframeNumber; ++i) {
		clips[i].w = nframeWidth;
		clips[i].h = nframeHeight;
		clips[i].x = srcX + nframeWidth*i;
		clips[i].y = srcY;
	}
	currentFrame = 0;
	startTime = 0;
	deltaTime = 0;
}

Animation::~Animation() {
	delete [] clips;
}

int Animation::getFrameNumber() const {
	return frameNumber;
}

int Animation::getCurrentFrame() const {
	return currentFrame;
}

void Animation::setCurrentFrame(int num) {
	currentFrame = num;
}

void Animation::tick() {
	deltaTime = SDL_GetTicks() - startTime;
	if (deltaTime >= (animationSpeed*1000)) {
		currentFrame = (currentFrame+1)%frameNumber;
		deltaTime = 0;
		startTime = SDL_GetTicks();
	}
	/*if (currentFrame >= frameNumber) {
		currentFrame = 0;
	}*/
}

void Animation::draw(int x, int y, int isPlaying, float angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = frameWidth;
	dst.h = frameHeight;
	SDL_RenderCopyEx(spr->getRenderer(), spr->getTexture(), &clips[currentFrame], &dst, angle, center, flip);
	if (isPlaying) {
		this->tick();
	} else {
		currentFrame = 0;
	}
}