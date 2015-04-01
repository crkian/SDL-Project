#include "Coin.h"
#include "Random.h"

void Coin::Init(Game* game, ResourceManager* rm)
{
	this->game = game;
	this->rm = rm;

	Relocate();
	sizeX = 16;
	sizeY = 16;

	texture = rm->getTexture("Data/item.png");
}
void Coin::Update(float deltaTime)
{	
	source_rect.x = 0;
	source_rect.y = 0;
	source_rect.w = sizeX;
	source_rect.h = sizeY;

	dest_rect.x = x;
	dest_rect.y = y;
	dest_rect.w = sizeX;
	dest_rect.h = sizeY;	
}
void Coin::Render()
{
	SDL_RenderCopy(game->getRenderer(), texture, &source_rect, &dest_rect);
}
void Coin::Relocate()
{
	x = Random::Int(4, 320 - 16 - 4);
	y = Random::Int(4, 240 - 16 - 4);
}