/* Resource manager handles game states,loads a texture and stores it
in a hash map, if somethign goes wrong an exception is created and that is shown in game
Hash maps use two columns first is a key and the second is where the keys are stored
Using std::string the hash map returns value assignedto key or NULL if nothing
std::map for the hash table
*/

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include <map>
#include <iterator>
#include <string>

class Game

	//each state has a resourcemanger and each takes care of its own data, including freeing

	class ResourceManager
	{
	private:
		std::map<std::string, SDL_Texture*> textures;

		Game* game;
	public:
// no default constructor the pointer is passed to instance of game to the rosourcemanager

		ResourceManager(Game* game);
//deleting instance takes textures from memory
		~ResourceManager();

		void loadTexture(std::string filename);

		//if no texture return null

		SDL_Texture* getTexture(std::string filename);
	};
#endif

