#pragma once
#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL.h"

class ModuleTextures : public Module
{
public:
	// Constructor
	ModuleTextures(Application* app, bool start_enabled = true);

	// Destructor
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	SDL_Texture* const Load(const char* path);
	void Unload(SDL_Texture* texture);

public:

	p2List<SDL_Texture*> textures;

};