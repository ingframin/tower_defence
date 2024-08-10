#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "particles.h"


Particles* genParticles(int x, int y,int numParticles, Direction d, int lifetime){
	SDL_Point *particles = (SDL_Point*) malloc(numParticles*sizeof(SDL_Point));
	for(int i=0;i<numParticles;i++){
		int signx = (d==RIGHT)?-1:1;
		int signy = (rand()%2)?-1:1;
		particles[i].x = x + signx*rand()%20;
		particles[i].y = y + signy*rand()%20;
	}
	Particles* p = (Particles*)malloc(sizeof(Particles));
	p->points = particles;
	p->d = d;
	p->numpoints = numParticles;
	p->lifetime = lifetime;
	return p;
}

void killParticles(Particles* p){
	free(p->points);
	free(p);
}

void drawParticles(SDL_Renderer* rnd, Particles* p, SDL_Color c){
	SDL_SetRenderDrawColor(rnd,c.r,c.g,c.b,c.a);
	
	SDL_RenderDrawPoints(rnd,p->points,p->numpoints);
	//direction should become a vector
	for(int i=0;i<p->numpoints;i++){
		p->points[i].x += (p->d == LEFT)?rand()%8:-rand()%8;
		p->points[i].y += (rand()%2)?rand()%8:-rand()%8;
	}
}