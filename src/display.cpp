#include "display.h"
#include <SDL2/SDL.h>


Display::Display(int x, int y, int w, int h) {
    window = SDL_CreateWindow("tdwindow", x, y, w, h, SDL_WINDOW_SHOWN);
}


Display::~Display() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


int Display::getWidth() {
    return SDL_GetWindowSurface(window)->w;
}


int Display::getHeight() {
    return SDL_GetWindowSurface(window)->h;
}   


SDL_Window* Display::getWindow() {
    return window;
}

SDL_Renderer* Display::getRenderer() {
    return SDL_GetRenderer(window);
}

void Display::clear() {
    SDL_RenderClear(getRenderer());
}

void Display::present() {
    SDL_RenderPresent(getRenderer());
}


