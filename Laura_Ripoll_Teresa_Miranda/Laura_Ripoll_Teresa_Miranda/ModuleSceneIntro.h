#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "SDL\include\SDL.h"

#define BOUNCER_TIME 200


enum lightTypes
{
	one,
	two,
	three
};

class ModuleSceneIntro;

struct Sensor
{
	Sensor() : body(NULL), texture(NULL), on(false), turn_off(false), fx(0)
	{}

	Sensor(ModuleSceneIntro* physics, int x, int y);// , lightTypes type);

	//lightTypes type;
	PhysBody* body;
	SDL_Texture* texture;
	bool on;
	bool turn_off;
	uint fx;
	int x, y;
};

class ModuleSceneIntro : public Module
{
public:
	//Constructor
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	
	//Destructor
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(PhysBody* body1, PhysBody* body2);

public:

	SDL_Texture* graphics;
	PhysBody* background;

	//Green balls sensors
	Sensor ball_green_up_sensor;
	Sensor ball_green_down_sensor;

	//Red balls sensors
	Sensor ball_red_1_sensor;
	Sensor ball_red_2_sensor;
	Sensor ball_red_3_sensor;
	Sensor ball_red_4_sensor;
	Sensor ball_red_5_sensor;
	Sensor ball_red_6_sensor;
	Sensor ball_red_7_sensor;
	Sensor ball_red_8_sensor;

	//Grey balls sensors
	Sensor ball_grey_1_sensor;
	Sensor ball_grey_2_sensor;
	Sensor ball_grey_3_sensor;
	Sensor ball_grey_4_sensor;
	Sensor ball_grey_5_sensor;
	Sensor ball_grey_6_sensor;
	Sensor ball_grey_7_sensor;

	SDL_Texture* one_light;
	SDL_Texture* two_lights;
	SDL_Texture* three_lights;
	/*
	uint fx_light_tiny;
	uint fx_light_medium;
	uint fx_light_big;
	*/
	p2DynArray<Sensor> sensors;

	PhysBody* player_lose;

	uint player_lose_fx;
	uint player_restart_fx;
	uint last_score = 0;
	uint score = 0;
	uint lives = 6;
};
