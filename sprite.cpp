#include "sprite.h"

void logSDL(std::ostream& os, const std::string& msg) {
	os << msg << " got error: " << SDL_GetError() << std::endl;
}

Sprite::Sprite(int w, int h) {
	width = w;
	height = h;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

void Sprite::loadImage(const char* fname) {
	if (renderer != NULL) {
		SDL_Surface* tmpSurface = IMG_Load(fname);
		if (tmpSurface == NULL) {
			logSDL(std::cerr, "Image load failed");
		} else {
			texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
			imgWidth = tmpSurface->w;
			imgHeight = tmpSurface->h;
			if (texture == NULL) {
				logSDL(std::cerr, "Image texture create");
			}
			SDL_FreeSurface(tmpSurface);
		}
	} else {
		std::cerr << "Sprite has null renderer." << std::endl;
	}
}

void Sprite::draw(int x, int y, float angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = width;
	dst.h = height;
	SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle, center, flip);
}

void Sprite::draw(int x, int y, int srcX, int srcY, int size, float angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect dst;
	SDL_Rect src;
	dst.x = x;
	dst.y = y;
	dst.w = size;
	dst.h = size;
	src.x = srcX;
	src.y = srcY;
	src.w = size;
	src.h = size;
	SDL_RenderCopyEx(renderer, texture, &src, &dst, angle, center, flip);
}

int Sprite::getWidth() const {
	return width;
}

int Sprite::getHeight() const {
	return height;
}
int Sprite::getImgWidth() const {
	return imgWidth;
}

int Sprite::getImgHeight() const {
	return imgHeight;
}

void Sprite::setWidth(int w) {
	width = w;
}

void Sprite::setHeight(int h) {
	height = h;
}

SDL_Texture* Sprite::getTexture() {
	return texture;
}

void Sprite::setRenderer(SDL_Renderer* nrend) {
	renderer = nrend;
}

SDL_Renderer* Sprite::getRenderer() {
	return renderer;
}