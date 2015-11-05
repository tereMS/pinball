#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"


// Constructor
ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
}

// Destructor
ModuleSceneIntro::~ModuleSceneIntro()
{

}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	// Music
	//App->audio->PlayMusic("pinball/Rhinoceros2.ogg", 0.0f);

	// Graphics
	graphics = App->textures->Load("pinball/pinball.png");

	//Sensor graphics
	ball_green_up_sensor.texture = ball_green_down_sensor.texture = App->textures->Load("pinball/Illuminated_greenball.png");

	ball_red_1_sensor.texture = ball_red_2_sensor.texture = ball_red_3_sensor.texture = ball_red_4_sensor.texture = ball_red_5_sensor.texture = ball_red_6_sensor.texture = ball_red_7_sensor.texture = ball_red_8_sensor.texture = App->textures->Load("pinball/Illuminated_redball.png");
	
	ball_grey_1_sensor.texture = ball_grey_2_sensor.texture = ball_grey_3_sensor.texture = ball_grey_4_sensor.texture = ball_grey_5_sensor.texture = ball_grey_6_sensor.texture = ball_grey_7_sensor.texture = App->textures->Load("pinball/Illuminated_red_ball.png");


	//Green balls

	ball_green_up_sensor.body = App->physics->CreateCircularObstacle(359, 242, 25, 0.0f, false, true);
	ball_green_up_sensor.body->listener = this;
	sensors.PushBack(ball_green_up_sensor);

	ball_green_down_sensor.body = App->physics->CreateCircularObstacle(263, 323, 25, 0.0f, false, true);
	ball_green_down_sensor.body->listener = this;
	sensors.PushBack(ball_green_down_sensor);


	PhysBody* ball_green_up = App->physics->CreateCircularObstacle(360, 243, 23, 2.0f, false, false);
	ball_green_up->listener = this;
	PhysBody* ball_green_down = App->physics->CreateCircularObstacle(264, 324, 23, 2.0f, false, false);
	ball_green_down->listener = this;


	//Red balls
	PhysBody* ball_red_1 = App->physics->CreateCircularObstacle(364, 48, 12, 0.0f, false, true);
	PhysBody* ball_red_2 = App->physics->CreateCircularObstacle(295, 48, 12, 0.0f, false, true);
	PhysBody* ball_red_3 = App->physics->CreateCircularObstacle(376, 186, 12, 0.0f, false, true);
	PhysBody* ball_red_4 = App->physics->CreateCircularObstacle(141, 157, 12, 0.0f, false, true);
	PhysBody* ball_red_5 = App->physics->CreateCircularObstacle(132, 219, 12, 0.0f, false, true);
	PhysBody* ball_red_6 = App->physics->CreateCircularObstacle(132, 251, 12, 0.0f, false, true);
	PhysBody* ball_red_7 = App->physics->CreateCircularObstacle(141, 375, 12, 0.0f, false, true);
	PhysBody* ball_red_8 = App->physics->CreateCircularObstacle(376, 323, 12, 0.0f, false, true);

	//Grey balls
	PhysBody* ball_grey_1 = App->physics->CreateCircularObstacle(365, 498, 8, 1.0f, true, false);
	PhysBody* ball_grey_2 = App->physics->CreateCircularObstacle(391, 154, 8, 1.0f, true, false);
	PhysBody* ball_grey_3 = App->physics->CreateCircularObstacle(370, 85, 8, 1.0f, true, false);
	PhysBody* ball_grey_4 = App->physics->CreateCircularObstacle(330, 41, 8, 1.0f, true, false);
	PhysBody* ball_grey_5 = App->physics->CreateCircularObstacle(279, 85, 8, 1.0f, true, false);
	PhysBody* ball_grey_6 = App->physics->CreateCircularObstacle(224, 87, 8, 1.0f, true, false);
	PhysBody* ball_grey_7 = App->physics->CreateCircularObstacle(135, 188, 8, 1.0f, true, false);


	int pinball_left_inside[128] = {
		163, 65,
		163, 68,
		164, 70,
		166, 71,
		168, 71,
		169, 70,
		169, 65,
		168, 59,
		167, 54,
		163, 46,
		158, 40,
		151, 33,
		141, 29,
		135, 28,
		129, 28,
		125, 29,
		119, 31,
		112, 36,
		106, 41,
		101, 47,
		98, 51,
		95, 56,
		94, 60,
		94, 64,
		94, 73,
		94, 95,
		95, 208,
		97, 365,
		97, 377,
		98, 384,
		101, 389,
		109, 398,
		112, 404,
		114, 410,
		115, 416,
		115, 471,
		115, 481,
		117, 484,
		119, 484,
		121, 483,
		121, 417,
		121, 410,
		119, 403,
		112, 393,
		105, 383,
		103, 374,
		125, 340,
		109, 312,
		122, 302,
		103, 267,
		101, 164,
		105, 164,
		108, 163,
		122, 125,
		124, 117,
		128, 115,
		110, 70,
		125, 64,
		150, 102,
		155, 99,
		155, 96,
		151, 86,
		158, 80,
		161, 73
	};


	PhysBody* pinball_left_inside_scenary = App->physics->CreateScenary(0, 0, pinball_left_inside, 128);

	int pinball_right_outside[88] = {
		251, 0,
		251, 37,
		253, 42,
		256, 43,
		259, 42,
		298, 10,
		371, 10,
		368, 13,
		369, 16,
		398, 40,
		401, 41,
		404, 40,
		404, 107,
		401, 107,
		395, 116,
		392, 118,
		374, 129,
		372, 133,
		374, 136,
		377, 138,
		382, 138,
		397, 129,
		401, 126,
		404, 123,
		404, 339,
		380, 380,
		379, 384,
		392, 391,
		375, 423,
		371, 428,
		361, 418,
		356, 421,
		355, 425,
		362, 432,
		373, 441,
		382, 453,
		393, 468,
		398, 480,
		401, 491,
		403, 503,
		403, 520,
		404, 680,
		415, 680,
		415, 0
	};

	PhysBody* pinball_right_outside_scenary = App->physics->CreateScenary(0, 0, pinball_right_outside, 88);

	int pinball_right_inside[34] = {
		281, 682,
		292, 672,
		376, 626,
		376, 516,
		376, 501,
		374, 491,
		369, 478,
		362, 467,
		345, 453,
		348, 446,
		358, 452,
		365, 457,
		373, 466,
		379, 477,
		384, 490,
		386, 505,
		385, 682
	};

	PhysBody* pinball_right_inside_scenary = App->physics->CreateScenary(0, 0, pinball_right_inside, 34);

	int pinball_left_outside[104] = {
		251, 0,
		251, 92,
		250, 96,
		247, 99,
		245, 100,
		242, 100,
		240, 98,
		231, 81,
		230, 81,
		226, 80,
		206, 70,
		204, 67,
		201, 67,
		200, 66,
		199, 55,
		196, 48,
		191, 38,
		185, 31,
		176, 23,
		161, 15,
		146, 10,
		134, 10,
		124, 10,
		114, 12,
		107, 15,
		100, 20,
		93, 26,
		86, 34,
		81, 42,
		78, 50,
		76, 55,
		75, 68,
		75, 228,
		74, 371,
		75, 381,
		78, 390,
		81, 398,
		86, 404,
		92, 412,
		95, 418,
		95, 427,
		95, 476,
		94, 483,
		91, 485,
		86, 480,
		70, 480,
		69, 480,
		69, 625,
		157, 672,
		166, 681,
		45, 681,
		45, 0
	};

	PhysBody* pinball_left_outside_scenary = App->physics->CreateScenary(0, 0, pinball_left_outside, 104);

	int pinball_flip_up_left[30] = {
		247, 110,
		251, 121,
		253, 125,
		256, 128,
		264, 134,
		274, 141,
		277, 141,
		283, 132,
		282, 129,
		274, 124,
		263, 117,
		261, 115,
		257, 108,
		255, 106,
		251, 107
	};

	PhysBody* pinball_flip_up_left_scenary = App->physics->CreateScenary(0, 0, pinball_flip_up_left, 30);

	int pinball_bouncer_left[10] = {
		157, 574,
		165, 568,
		131, 508,
		120, 512,
		124, 556
	};

	PhysBody* pinball_bouncer_left_scenary = App->physics->CreateScenary(0, 0, pinball_bouncer_left, 10);

	int pinball_bouncer_right[14] = {
		318, 509,
		328, 512,
		325, 552,
		324, 555,
		319, 559,
		290, 572,
		284, 564
	};

	PhysBody* pinball_bouncer_right_scenary = App->physics->CreateScenary(0, 0, pinball_bouncer_right, 14);

	int pinball_flip_down_left[30] = {
		158, 642,
		168, 627,
		117, 600,
		108, 594,
		103, 588,
		99, 577,
		97, 572,
		95, 572,
		92, 574,
		90, 580,
		90, 592,
		92, 598,
		97, 605,
		102, 610,
		113, 618
	};

	PhysBody* pinball_flip_down_left_scenary = App->physics->CreateScenary(0, 0, pinball_flip_down_left, 30);

	int pinball_flip_down_right[28] = {
		288, 641,
		280, 626,
		332, 597,
		338, 593,
		344, 587,
		348, 577,
		352, 574,
		354, 576,
		356, 582,
		356, 589,
		354, 597,
		350, 603,
		345, 610,
		335, 618
	};

	PhysBody*pinball_flip_down_right_scenary = App->physics->CreateScenary(0, 0, pinball_flip_down_right, 28);

	int grey_obstacle_1[14] = {
		128, 349,
		131, 352,
		131, 354,
		116, 370,
		115, 370,
		112, 369,
		112, 366
	};

	PhysBody*grey_obstacle_1_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_1, 14);

	int grey_obstacle_2[12] = {
		405, 337,
		401, 337,
		400, 336,
		400, 318,
		400, 315,
		405, 315
	};

	PhysBody*grey_obstacle_2_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_2, 12);

	int grey_obstacle_3[12] = {
		103, 266,
		106, 266,
		108, 265,
		108, 245,
		107, 244,
		103, 244
	};

	PhysBody*grey_obstacle_3_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_3, 12);

	int grey_obstacle_4[12] = {
		102, 234,
		106, 234,
		108, 233,
		108, 213,
		107, 212,
		102, 212
	};

	PhysBody*grey_obstacle_4_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_4, 12);

	int grey_obstacle_5[12] = {
		403, 200,
		401, 200,
		400, 199,
		400, 179,
		400, 177,
		404, 177
	};

	PhysBody*grey_obstacle_5_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_5, 12);

	int grey_obstacle_6[12] = {
		267, 36,
		269, 38,
		271, 39,
		287, 26,
		287, 25,
		284, 22
	};

	PhysBody*grey_obstacle_6_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_6, 12);

	int grey_obstacle_7[12] = {
		374, 19,
		370, 23,
		370, 24,
		387, 38,
		388, 38,
		392, 35
	};

	PhysBody*grey_obstacle_7_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_7, 12);

	int grey_obstacle_8[12] = {
		110, 160,
		112, 162,
		115, 162,
		123, 144,
		123, 141,
		117, 138
	};

	PhysBody*grey_obstacle_8_scenary = App->physics->CreateScenary(0, 0, grey_obstacle_8, 12);

	player_lose = App->physics->CreateRectangle(225, 669, 116, 14, b2_staticBody, 0.0f, false, true);
	player_lose->listener = this;

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->renderer->Blit(graphics, 45, 0);

	// Update title with score
	char header[50];
	sprintf_s(header, "Score: %06d     %s     Balls: %d", score, TITLE, lives/2);
	App->window->SetTitle(header);


	for (int i = 0; i < sensors.Count(); i++){
		if (sensors[i].on == true){
			App->renderer->Blit(sensors[i].texture, sensors[i].x, sensors[i].y);
		}
	}

	return UPDATE_CONTINUE;
}


void ModuleSceneIntro::OnCollision(PhysBody* body1, PhysBody* body2)
{
	bool life_less = false;
	
	for (int i = 0; i < sensors.Count(); i++){
		LOG("Collision");
		if (body1 == sensors[i].body){
			sensors[i].on = true;
			score += 100;
		}
	}
	
	/*
	if (ball_green_down_sensor.body == body1)
	{
		score += 100;
		LOG("Collided with green sensor");
		//App->audio->PlayFx(bouncer1.fx);
		return;
	}

	if (ball_green_down_sensor.body == body1)
	{
		score += 100;
		LOG("Collided with green sensor");
		//App->audio->PlayFx(bouncer1.fx);
		return;
	}
	*/

	if (player_lose == body1)
	{
		life_less = true;
		App->player->ball.b->body->SetTransform(b2Vec2(PIXEL_TO_METERS(400), PIXEL_TO_METERS(500)), 0.0f);
		App->player->ball.b->body->SetAngularVelocity(0);
		//App->player->ball.b->body->SetPosition(563, 582);
		

		if (lives == 0)
		{
			last_score = score;
			score = 0;
			lives = 6;
			//App->audio->PlayFx(player_restart_fx);
		}
		
		else
		{
			//App->audio->PlayFx(player_lose_fx);
		}
	}
	if (life_less == true){
		lives = lives - 1;
		life_less = false;
	}
		return;

}
