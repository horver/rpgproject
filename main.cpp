#include <iostream>
#include "enviroment.h"
#include "player.h"

int main (int argc, char **argv) {
	Enviroment env;
	TileMap tile(40, 40, "tileset.png", env.getRenderer(), "map3.txt", 2);

	Player player(256, 144, 2);
	player.setMap(&tile);
	player.createSprite(130, 192, "spritexb-1462.png", env.getRenderer());
	Animation walkDown(player.getSprite(), 0, 0, 32, 48, 4, 0.25);
	Animation walkLeft(player.getSprite(), 0, 48, 32, 48, 4, 0.25);
	Animation walkRight(player.getSprite(), 0, 96, 32, 48, 4, 0.25);
	Animation walkUp(player.getSprite(), 0, 144, 32, 48, 4, 0.25);
	player.addAnimation(&walkDown, DOWN);
	player.addAnimation(&walkLeft, LEFT);
	player.addAnimation(&walkRight, RIGHT);
	player.addAnimation(&walkUp, UP);
	
	Character test(150,150);
	test.setMap(&tile);
	test.createSprite(128,192, "steampunk_f8.png", env.getRenderer());
	Animation walkDownt(test.getSprite(), 0, 0, 32, 48, 4, 0.25);
	Animation walkLeftt(test.getSprite(), 0, 48, 32, 48, 4, 0.25);
	Animation walkRightt(test.getSprite(), 0, 96, 32, 48, 4, 0.25);
	Animation walkUpt(test.getSprite(), 0, 144, 32, 48, 4, 0.25);
	test.addAnimation(&walkDownt, DOWN);
	test.addAnimation(&walkLeftt, LEFT);
	test.addAnimation(&walkRightt, RIGHT);
	test.addAnimation(&walkUpt, UP);

	
	//TileMap tile(20, 15, "tile.png", env.getRenderer(), "map.txt", 2);
	env.addMap(&tile);
	env.addObject(&test);
	env.addObject(&player);
	env.run();
	
	return 0;
}