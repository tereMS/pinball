#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct Player
{
	SDL_Texture* image; 
	PhysBody* b; 
	uint fx;
};

class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(Application* app, bool start_enabled = true);

	// Destructor
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	Player ball; 

	Player right_down_flipper;
	Player left_down_flipper;
	Player right_middle_flipper;
	Player left_middle_flipper;
	Player right_up_flipper;
	Player left_up_flipper;

	PhysBody* right_down_flipper_wheel;
	PhysBody* left_down_flipper_wheel;
	PhysBody* right_middle_flipper_wheel;
	PhysBody* left_middle_flipper_wheel;
	PhysBody* right_up_flipper_wheel;
	PhysBody* left_up_flipper_wheel;

	Player spring;

	PhysBody* spring_wheel;

};