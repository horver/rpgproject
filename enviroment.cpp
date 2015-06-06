#include "enviroment.h"
#include "dialog.h"

Enviroment::Enviroment() {
	if (SDL_Init(SDL_INIT_EVERYTHING) !=0) {
		logSDL(std::cerr, "Init");
	} else {
		window = SDL_CreateWindow("The Mysterius Island", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			logSDL(std::cerr, "Window creation");
			SDL_Quit();
		} else {
			SDL_SetWindowIcon(window, IMG_Load("icon.png"));
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (!IMG_Init(IMG_INIT_PNG))
				logSDL(std::cerr, "IMG init");
			/*if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
				logSDL(std::cerr, "MIXER init");*/
			quit = false;
			if (renderer == NULL) {
				logSDL(std::cerr, "Renderer creation");
				SDL_DestroyWindow(window);
				SDL_Quit();
			}
		}
		/*backgroundMusic = Mix_LoadMUS("Folk Round.mp3");
		if (backgroundMusic == NULL) {
			logSDL(std::cerr, "Music load failed");
		}*/
	}
}

Enviroment::~Enviroment() {
	logSDL(std::cerr, "Destroy");
	/*Mix_FreeMusic(backgroundMusic);
	Mix_Quit();*/
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Renderer* Enviroment::getRenderer() {
	return renderer;
}

void Enviroment::render() {
	SDL_RenderClear(renderer);
	map->draw(renderer);
	for (std::vector<GameObject*>::iterator obj = objects.begin(); obj!=objects.end(); ++obj) {
		(*obj)->draw();
	}
	//diaTest->draw();
	SDL_RenderPresent(renderer);
	//SDL_RenderClear(renderer);
}
void Enviroment::run() {
	/*Dialog* diaTest = new Dialog("shit", 1);
	diaTest->loadFont("OpenSans-Regular.ttf");
	diaTest->createSprite(640, 64, "dialog.png", getRenderer());*/
	//Mix_PlayMusic(backgroundMusic, 1);
	while(!quit) {
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
			}
			//Handle input
			for (std::vector<GameObject*>::iterator obj = objects.begin(); obj!=objects.end(); ++obj) {
				for (std::vector<GameObject*>::iterator obj2 = objects.begin(); obj2!=objects.end(); ++obj2) {
					if (obj != obj2) {
						(*obj)->step(&event, (*obj)->checkCollision( (*obj)->getBoundBox(), (*obj2)->getBoundBox() ),*(*obj2));
				
					}
				}
			}
		}
		
		for (std::vector<GameObject*>::iterator obj = objects.begin(); obj!=objects.end(); ++obj) {
			(*obj)->move();
		}

		render();

	}
}

void Enviroment::addObject(GameObject* obj) {
	if (obj != NULL) {
		objects.push_back(obj);
	} else {
		std::cerr << "Can't add Character." << std::endl;
	}
}

void Enviroment::addMap(TileMap* m) {
	map = m;
}