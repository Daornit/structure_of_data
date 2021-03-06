#include "SDL.h"
//gcc cube.c `pkg-config --cflags --libs sdl2`
int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(500, 500, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
                SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
                SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
	while(running)
		{
		    while(SDL_PollEvent(&event)) // check to see if an event has happened
		    {
		        switch(event.type)
		        {
			   case SDL_QUIT:
			       running = false;
			       break;
			   case SDL_MOUSEBUTTONDOWN: // if the event is mouse click
			       if(event.mouse.x >= 100)  // check if it is in the desired area
			       {
				  printf("Mouse is buttoned");  
			       }
		        }
		    }
		}
    }
    SDL_Quit();
    return 0;
}
