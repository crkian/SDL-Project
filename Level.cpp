#include "Level.h"



//Basic adding of tile depending on width and height, uses to for loops

Level::Level(Game* game, ResourceManager* rm)
{
	this->game = game;
	this->rm=rm;
	tile=NULL;
}

void Level::Init()
{
	tile=rm->getTexture("tile_01.png");
}

void Level::Render()
{
	for(int y=0; y<LEVEL_HEIGHT; y++)
		for(int x=0; x<LEVEL_WIDTH; x++)
		{
			SDL_Rect rect;
			rect.x=x*TILE_SIZE;
			rect.y=y*TILE_SIZE;
			rect.w=TILE_SIZE;
			rect.h=TILE_SIZE;

			SDL_RenderCopy(game->getRenderer(), tile, NULL, &rect);
		}
}