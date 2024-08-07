#ifndef DISPLAY_H
#define DISPLAY_H

#include <cstdint>
#include <SDL2/SDL.h>

class Display {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    int width;
    int height;

public:
    Display(int x, int y, int w, int h);
    ~Display(); 

    int getWidth();
    int getHeight();
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    void clear();
    void present();
};

#endif