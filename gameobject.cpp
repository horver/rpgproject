#include "gameobject.h"

GameObject::GameObject(int nx, int ny) {
	x = nx;
	y = ny;
}

GameObject::~GameObject() {
	if (sprite != NULL)
		delete sprite;
}

Sprite* GameObject::getSprite() {
	return sprite;
}

int GameObject::getX() const {
	return x;
}

int GameObject::getY() const {
	return y;
}

int GameObject::getTileX(int radius) const {
	return (x+radius)/tileSize;
}

int GameObject::getTileY(int radius) const {
	return (y+radius)/tileSize;
}

void GameObject::setX(int nx) {
	x = nx;
}

void GameObject::setY(int ny) {
	y = ny;
}

SDL_Rect* GameObject::getBoundBox() {
	return &boundBox;
}

void GameObject::setBoundBox(int x, int y) {
	boundBox.x = x - 16;
	boundBox.y = y - 49/2;
}

void GameObject::createSprite(int w, int h, const char* fileName, SDL_Renderer* nrend) {
	sprite = new Sprite(w, h);
	sprite->setRenderer(nrend);
	sprite->loadImage(fileName);
	boundBox.x = x;
	boundBox.y = y;
	boundBox.w = 32;
	boundBox.h = 49;
}

void GameObject::destroySprite() {
	if (sprite != NULL)
		delete sprite;
}


bool GameObject::checkCollision(SDL_Rect* a, SDL_Rect* b) const {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a->x;
	rightA = a->x + a->w;
	topA = a->y;
	bottomA = a->y + a->h;

	leftB = b->x;
	rightB = b->x + b->w;
	topB = b->y;
	bottomB = b->y + b->h;

	if (topA >= bottomB) {
		return false;
	}

	if (bottomA <= topB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}
	
	return true;
}


void GameObject::draw() {
	sprite->draw(x, y);
}

void GameObject::interaction() {
}

void GameObject::step(SDL_Event* event, bool collided, GameObject& other) {
}

void GameObject::move() {
}