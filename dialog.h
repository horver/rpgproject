#ifndef _DIALOG_H__
#define _DIALOG_H__

#include "gameobject.h"
#include <SDL_ttf.h>
#include <string>

const int dialogPosX = 32;
const int dialogPosY = 384;

class Dialog : public GameObject {
	public:
		Dialog(const char* fname, int numOfText);
		~Dialog();

		int getTextNum() const;

		void loadFont(const char* fname);
		void draw();

	private:
		int textNum;
		int currentText;
		std::string* text;
		TTF_Font* font;
};

#endif