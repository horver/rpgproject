#ifndef _BASEITEM_H__
#define _BASEITEM_H__

#include "sprite.h"
#include <string>

class BaseItem {
	public:
		BaseItem(const std::string& nName, const std::string& nDesc, int nWeight);

		void createSprite(const char* fname, SDL_Renderer* renderer);

	private:
		std::string name;
		std::string desc;
		int weight;
		Sprite* spr;
};

#endif