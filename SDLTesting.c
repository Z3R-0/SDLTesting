#include <stdio.h>
#include <SDL2/SDL.h>

void clear(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void draw(SDL_Renderer *renderer, SDL_Rect *rect) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(renderer, rect);
	SDL_RenderPresent(renderer);
}

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

	SDL_Surface *surface = SDL_GetWindowSurface(window);

	// centered rect
	SDL_Rect rectangle = {
		.x = 0,
		.y = 900,
		.w = 100,
		.h = 100
	};

	while (1) {
		rectangle.x += 1;
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);

		SDL_RenderFillRect(renderer, &rectangle);
		SDL_RenderPresent(renderer);
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
	}

	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
}