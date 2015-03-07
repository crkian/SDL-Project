#ifndef OBJECT_H
#define OBJECT_H

#include "Game.h"
#include "ResourceManager.h"

class Object
{
protected:
	//position in world
	float x, y;

	//size in pixels
	float sizeX, sizeY;

	//pointers for renderer and textures
	Game* game;
	ResourceManager* rm;
	
	SDL_Rect source_rect;
	SDL_Rect dest_rect;

public:
	virtual void Init(Game* game, ResourceManager* rm) =0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render()=0;
};

#endif