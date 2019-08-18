#include <SDL.h>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
	int screen_width = 1024, screen_height = 768;
	SDL_Window* main_window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event event = { 0 };
	bool should_quit = false;
	SDL_Rect box_destination = { 0 };
	int box_width = 0, box_height = 0;
	std::stringstream error;

	try {

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
			error << "Failed to initialize SDL: " << SDL_GetError();
			throw(error.str());
		}

		if ((main_window = SDL_CreateWindow("Use the arrow keys!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, 0)) == 0) {
			error << "Failed to create a window: " << SDL_GetError();
			throw(error.str());
		}

		if ((renderer = SDL_CreateRenderer(main_window, -1, 0)) == 0) {
			error << "Failed to create the renderer: " << SDL_GetError();
			throw(error.str());
		}

		// CONFIGURE THE BOX / PLAYER, IT'S INITIAL LOCATION AND SIZE:
		box_width = 100;
		box_height = 100;
		box_destination.x = (screen_width / 2) - (box_width / 2);
		box_destination.y = (screen_height / 2) - (box_height / 2);
		box_destination.w = box_width;
		box_destination.h = box_height;

		// Initial beforeTime, convert the performance counter value into 
		// something more meaningful using the performance frequency (convert 
		// to miliseconds):
		double beforeTime = SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
		double speed = 1.0f; /* pixels per second of movement */

		// PRIMARY & EVENT LOOP:
		while (!should_quit) {
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					should_quit = 1;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						should_quit = 1;
						break;
					}
					break;
				}
			}

			// CALCULATE DELTA TIME:
			// Get the current time by querying the performance counter and 
			// using the performance frequency to give it meaning (convert it
			// to miliseconds)
			double currentTime = (double) SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
			double deltaTime = (currentTime - beforeTime) * 1000.0 /* Convert to seconds so speed is pixels per second... */;
			beforeTime = currentTime; /* Prime beforeTime for the next frame */

			// CHECK THE KEYBOARD STATE FOR MOVEMENT KEYS:
			// If you had used events for this instead (SDL_KEYDOWN/UP) you 
			// would have only been able to act on one key press at a time.

			const Uint8 *state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_LEFT]) {
				if (box_destination.x > 0) box_destination.x -= static_cast<int>(speed * deltaTime);
			}
			if (state[SDL_SCANCODE_RIGHT]) {
				if (box_destination.x + box_width < screen_width) box_destination.x += static_cast<int>(speed * deltaTime);
			}
			if (state[SDL_SCANCODE_UP]) {
				if (box_destination.y > 0) box_destination.y -= static_cast<int>(speed * deltaTime);
			}
			if (state[SDL_SCANCODE_DOWN]) {
				if (box_destination.y + box_height < screen_height) box_destination.y += static_cast<int>(speed * deltaTime);
			}

			// RENDERING:

			// Clear the background:
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderClear(renderer);

			// Render the box:
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(renderer, &box_destination);

			// Show on screen:
			SDL_RenderPresent(renderer);

			// REMOVE THIS IF YOU'RE DRAWING ANYTHING WORTHWHILE:
			// This should not be necessary, but since we're only drawing a
			// single square on the screen, the frame-rate is way too fast and 
			// it hits that event loop too much so you'll get jerky motion.
			SDL_Delay(1);
		}

	}
	catch (std::string error_str) {
		std::cout << error_str << std::endl;
	}

	if (renderer) SDL_DestroyRenderer(renderer);
	if (main_window) SDL_DestroyWindow(main_window);
	SDL_Quit();

	return 0;
}
