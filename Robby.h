#ifndef ROBBY_H
#define ROBBY_H

#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>


class Robby : public Object
{
private:
	/*adjusts speed, variable rather than constant incase needed elsewhere*/
	float move_speed;

	/*pointer to the texture from resource manager*/
	SDL_Texture* sheet;

	/*set up for the texture page with row and column*/
	float sheet_row;
	float sheet_column;
	float sheet_animSpeed;

	/* moves the page along on the texture*/
	float dirX, dirY;

public:
	void Init(Game* game, ResourceManager* rm);
	void Update(float deltaTime);
	void Render();

	/* sets dirX and dirY */
	void Move (int dx, int dy);
};

#endif