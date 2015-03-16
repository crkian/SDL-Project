#include "ResourceManager.h"
#include "Game.h"
// We will impliment the constructor

ResourceManager::ResourceManager(Game* game)
{
	this->game = game; // pass game as it has pointer to renderer and we need it
}

/* next the cleanup, calls quit function of gamestate using delete. The hash table can't be looped through
*/

ResourceManager::~ResourceManager()
{
	std::map<std::string,SDL_Texture*>::iterator i;
	for(i=textures.begin(); i != textures.end(); i++)
	{
		SDL_DestroyTexture(i->second);
	}
	textures.clear();
}


// Next loads the texture, img_loadtextureloads. Its a pointer and why game was needed. If image doesnt load its NULL. 

void ResourceManager::loadTexture(std::string filename)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(game->getRenderer(), filename.c_str());
	if(texture == NULL)
		throw std::runtime_error("Error while loading texture: "+ filename);
	
	//std paid is a single row in the table mentioned before

	textures.insert(std::pair<std::string, SDL_Texture*>(filename, texture));
}

//code to fetch the texture from hash table needan iterator as std map find returns std map iterator


SDL_Texture* ResourceManager::getTexture(std::string filename)
{
	SDL_Texture* texture = NULL;
	std::map<std::string, SDL_Texture*>::iterator i;
	//seachesthe hash map for the ket specified it it fails it ends

	i=textures.find(filename);
	//next assigns the value of the pair to texture

	texture = i->second;

	return texture;
}

// no error handling but thats ok for now