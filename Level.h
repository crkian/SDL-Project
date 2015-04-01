#ifndef LEVEL_H
#define LEVEL_H

/*makes it so the game can be bigger or smaller*/
#define TILE_SIZE 16
#define LEVEL_WIDTH 20
#define LEVEL_HEIGHT 15

#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"
#include "ResourceManager.h"


class Level
{
private:
	SDL_Texture* tile;

	Game* game;
	ResourceManager* rm;

public:
	Level(Game* game, ResourceManager* rm);

	void Init();
	void Render();
};

#endif
