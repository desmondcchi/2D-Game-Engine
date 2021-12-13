#include "Game.h"

SDL_Texture *playerTexture;
SDL_Rect srcRect;
SDL_Rect destinationRect;

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen) {
	int flags = 0;
	
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		}

		isRunning = true;
	}

	SDL_Surface *tempSurface = IMG_Load("assets/player.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
}

void Game::handleEvents() {
	SDL_Event event;

	SDL_PollEvent(&event);

	switch(event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	count++;

	destinationRect.w = 16 * 6;
	destinationRect.h = 16 * 6;
	destinationRect.x = count;
	destinationRect.y = count;

	std::cout << count << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, playerTexture, NULL, &destinationRect);

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}