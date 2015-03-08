#ifndef COIN_H
#define COIN_H

#include "Object.h"

class Coin:public Object
{
private:
	SDL_Texture* texture;

public:
	void Init(Game* game, ResourceManager* rm);
	void Update(float deltaTime);
	void Render();
	void Relocate();
};

#endif