#pragma once

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"

#define DEFAULT_MUSIC_FADE_TIME 2.0f

class ModuleAudio : public Module
{
public:
	// Constructor
	ModuleAudio(Application* app, bool start_enabled = true);

	//Destructor
	~ModuleAudio();

private:

	
};
