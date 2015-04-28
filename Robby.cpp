#include "Robby.h"

void Robby::Init(Game* game, ResourceManager*rm)
{
this->game = game;
this->rm = rm;

/*this puts the sprite in the middle of the screen*/
x= 160 - 16;
y= 120 - 32;

/*match the frame size*/
sizeX = 16;
sizeY = 32;

dirX = 0.0f;
dirY = 0.0f;

sheet_row = 0.0f;
sheet_column = 0.0f;
sheet_animSpeed = 6.0f;

/*movement speed*/

move_speed = 32.0f;

sheet=rm->getTexture("Data/character.png");
}

/*movement from state_gameplay, changes if the key press is left right up down with the character facing move*/

void Robby::Update(float deltaTime)
{
	/*do the walking movement if not stood still*/
	if(dirX != 0 || dirY != 0)
	{
		sheet_row += sheet_animSpeed*deltaTime;
		if((int)sheet_row >= 4)
			sheet_row = 0.0f;
	}
	else
		sheet_row = 0.0f;

	/*page column is set here depending which way character is facing*/

	if(dirX > 0)
		sheet_column = 3;
	if(dirX < 0)
		sheet_column = 2;
	if(dirY < 0)
		sheet_column = 1;
	if(dirY > 0)
		sheet_column = 0;

	/*each frames movement depending on direction and if moving*/

	x += dirX * move_speed * deltaTime;
	y += dirY * move_speed * deltaTime;

	/*the rectangle coordinates for the sprite sheet*/

	source_rect.x = sizeX * (int)sheet_column;
	source_rect.y = sizeY * (int)sheet_row;
	source_rect.w = sizeX;
	source_rect.h = sizeY;

	/*size and position on screen*/

	dest_rect.x = x;
	dest_rect.y = y;
	dest_rect.w = sizeX;
	dest_rect.h = sizeY;

	/*reset direction for next frame*/

	dirX = 0.0f;
	dirY = 0.0f;

}

void Robby::Render()
{
	SDL_RenderCopy(game->getRenderer(), sheet, &source_rect, &dest_rect);
}

void Robby::Move(int dx, int dy)
{
	dirX += dx;
	dirY += dy;
}