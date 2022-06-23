#include <stdio.h>
#include <SDL2/SDL.h>
#include "vector.h"

int run = 1;

int main() {
	// Init SDL2
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL Error during initialization: %s", SDL_GetError());
		return 1;
	}

	// Create a window
	SDL_Window *window = SDL_CreateWindow(
		"Test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		0);

	// Create a renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	//Null check the window and renderer
	if (window == NULL || renderer == NULL) {
		printf("Window or Renderer error: %s", SDL_GetError());
		return 1;
	}

	// centered rect
	SDL_Rect rectangle = {
		.x = 480,
		.y = 900,
		.w = 100,
		.h = 100
	};
	
	IntVector2 vec = {
		.x = 1,
		.y = 3
	};
	printf("Total: %d", IntVector2Total(vec));

	while (run) {
		if (rectangle.y <= 1600)
			rectangle.y += 1;
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

		SDL_RenderFillRect(renderer, &rectangle);
		SDL_RenderPresent(renderer);
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
	}
	
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}