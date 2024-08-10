#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum{
    UP = -1,
    DOWN = 1,
    LEFT,
    RIGHT
}Direction;

typedef struct {
    SDL_Point* points;
    int numpoints;
    int lifetime;
    Direction d;
} Particles;


Particles* genParticles(int x, int y,int numParticles, Direction d, int lifetime);
void killParticles(Particles* p);
void drawParticles(SDL_Renderer* rnd, Particles* p, SDL_Color c);


#endif // UTILS_H_INCLUDED
