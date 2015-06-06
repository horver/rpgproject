#ifndef _SPRITE_H__
#define _SPRITE_H__

#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

void logSDL(std::ostream& os, const std::string& msg);

class Sprite {
	public:
		Sprite(int w, int h);
		~Sprite();

		void loadImage(const char* fname);
		void draw(int x, int y, float angle = 0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void draw(int x, int y, int srcX, int srcY, int size, float angle = 0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
		
		int getWidth() const;
		int getHeight() const;
		int getImgWidth() const;
		int getImgHeight() const;
		void setWidth(int w);
		void setHeight(int h);
		void setRenderer(SDL_Renderer* nrend);
		SDL_Renderer* getRenderer();
		SDL_Texture* getTexture();

	private:
		SDL_Texture* texture;
		SDL_Renderer* renderer;
		int width;
		int height;
		int imgWidth;
		int imgHeight;
};

#endif