#include "character.h"

Character::Character(int nx, int ny) {
	setX(nx);
	setY(ny);
	direction = DOWN;
	state = IDLE;
}

Character::~Character() {
}

void Character::addAnimation(Animation* anim, int type) {
	if (anim != NULL) {
		animations.insert(std::pair<int, Animation*>(type, anim));
	} else {
		std::cerr << "Cant create animation in Character." << std::endl;
	}
}

Animation* Character::getAnimation(int which) {
	return animations[which];
}

DIRECTIONS Character::getDirection() const {
	return direction;
}

STATES Character::getState() const {
	return state;
}

void Character::setDirection(DIRECTIONS dir) {
	direction = dir;
}

void Character::setState(STATES nstate) {
	state = nstate;
}

void Character::setMap(TileMap* tilemap) {
	map = tilemap;
}

TileMap* Character::getMap() {
	return map;
}

void Character::step(SDL_Event* event, bool collided, GameObject& other) {
}

void Character::move() {
	if (getState() == MOVING) {
		setBoundBox(getX(), getY());
	}
}

void Character::draw() {
	//SDL_RenderFillRect(getSprite()->getRenderer(), getBoundBox());
	animations[direction]->draw(getX()-getMap()->getCamera()->x, getY()-getMap()->getCamera()->y, state);
}