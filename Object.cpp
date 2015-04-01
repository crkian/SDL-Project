#include "Object.h"
#include <SDL.h>

bool Object::collidesWith(Object* other)
{
	/*uses AABB intersection for colllision*/
	/*checks bounding boxes*/
	if(other-> x + other->sizeX < x) return false;
	if(other-> x > x+sizeX) return false;
	if(other->y + other->sizeY < y) return false;
	if(other->y > y+sizeY) return false;

	return true;
}