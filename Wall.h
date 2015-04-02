#ifndef WALL_H
#define WALL_H

#include "Object.h"

class Wall : public Object
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