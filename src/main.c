#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "display.h"

int main(int argc, char* argv[]) {
    Display* disp = newDisplay("Tower Defence", 800, 600);

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        clearDisplay(disp);
        SDL_RenderPresent(disp->rnd);

    }
    
    destroyDisplay(disp);
    SDL_Quit();
    return 0;
}