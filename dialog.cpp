#include "dialog.h"

Dialog::Dialog(const char* fname, int numOfText) {
	setX(dialogPosX);
	setY(dialogPosY);
	if (TTF_Init () == -1) {
		logSDL(std::cerr, "TTF init");
	}
}

Dialog::~Dialog() {
	TTF_CloseFont(font);
	TTF_Quit();
	destroySprite();
	delete [] text;
}

int Dialog::getTextNum() const {
	return textNum;
}

void Dialog::loadFont(const char* fname) {
	font = TTF_OpenFont(fname, 28);
}

void Dialog::draw() {
	SDL_Color textColor;
	textColor.r = 255;
	textColor.g = 255;
	textColor.b = 255;
	textColor.a = 1;
	SDL_Rect dest;
	dest.x = 32;
	dest.y = 384;
	dest.w = 640;
	dest.h = 32;
	SDL_SetTextureAlphaMod(getSprite()->getTexture(), 164);
	getSprite()->draw(dest.x-32, dest.y);
	SDL_Texture* text = SDL_CreateTextureFromSurface(getSprite()->getRenderer(), TTF_RenderText_Solid(font, "Árvíztürõ tükörfúrógép", textColor));
	SDL_RenderCopy(getSprite()->getRenderer(), text, NULL, &dest);
}