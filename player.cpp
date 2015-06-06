#include "player.h"

float Player::getHealth() const {
	return health;
}

void Player::step(SDL_Event* event, bool collided, GameObject& other) {
	
	//const Uint8* keyState = SDL_GetKeyboardState(NULL); //YUNO WORK BITCH?!
	SDL_Keycode key = event->key.keysym.sym;

	if (key == SDLK_RIGHT) { //
		setDirection(RIGHT);
		setState(MOVING);
	}

	if (key == SDLK_LEFT) {
		setDirection(LEFT);
		setState(MOVING);
	}

	if (key == SDLK_UP) {
		setDirection(UP);
		setState(MOVING);
	}

	if (key == SDLK_DOWN) {
		setDirection(DOWN);
		setState(MOVING);
	}

	if (event->type == SDL_KEYUP) {
		setState(IDLE);
	}
	
	if (collided) {
		std::cout << "collided" << std::endl;
		setState(BLOCKED);
		if (key == SDLK_SPACE) {
			std::cout << "space" << std::endl;
			setState(INTERACT);
			other.interaction();
		}
	}
		
}

void Player::move() {
	
	int x = getX();
	int y = getY();
	int tileX = getTileX();
	int tileY = getTileY();

	if (getDirection() == RIGHT) {

		Tile* tileAtPos = getMap()->getTile(std::max(getTileX(speed), 0), tileY, getMap()->getLayers()-1);
			
		if (tileAtPos->type == FIELD) {
			x += speed;
		} 

		if (tileAtPos->type == BLOCK ) {
			setState(BLOCKED);			
		}

		if (tileAtPos->type == INTERACTIVE) {
			if (getState() == INTERACT) {
				std::cout << "interacted" << std::endl;
			}
		}
	}
	
	if (getDirection() == LEFT) {
		
		Tile* tileAtPos = getMap()->getTile(std::max((x-speed)/tileSize, 0), tileY, getMap()->getLayers()-1);
			
		if (tileAtPos->type == FIELD) {
			x -= speed;
		} 

		if (tileAtPos->type == BLOCK) {
			setState(BLOCKED);
		}
	}
	
	if (getDirection() == UP) {
			
		Tile* tileAtPos = getMap()->getTile(tileX, std::max((y-speed)/tileSize, 0), getMap()->getLayers()-1);
			
		if (tileAtPos->type == FIELD) {
			y -= speed;
		} 

		if (tileAtPos->type == BLOCK) {
			setState(BLOCKED);
		}

	}

	
	if (getDirection() == DOWN) {
		
		Tile* tileAtPos = getMap()->getTile(tileX, std::max((y+speed)/tileSize, 0), getMap()->getLayers()-1);
			
		if (tileAtPos->type == FIELD) {
			y += speed;
		} 
			
		if (tileAtPos->type == BLOCK) {
			setState(BLOCKED);
		}
	}

	if (getState() == INTERACT) {
		std::cout << "interacting" << std::endl;	
	}

	if (getState() == MOVING) {
		setX(x);
		setY(y);
		setBoundBox(getX(), getY());
		getMap()->setCamera(getX(), getY());
	}
}

void Player::draw() {
	Animation* tmp = getAnimation(getDirection());
	/*
	SDL_RenderFillRect(getSprite()->getRenderer(), getBoundBox());/**/
	//(getX()/32)*32, (getY()/32)*32, snap to grid
	tmp->draw(getX()-16-getMap()->getCamera()->x, getY()-32-getMap()->getCamera()->y, getState()==MOVING?1:0);
}