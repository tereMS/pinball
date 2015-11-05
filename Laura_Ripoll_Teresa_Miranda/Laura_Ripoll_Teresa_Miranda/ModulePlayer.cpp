#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"




// Constructor
ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

// Destructor
ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start(){

	/////////////////// BALL /////////////////////////////////////////////////////////////////////////////////////
	ball.image = App->textures->Load("pinball/ball.png");


	ball.b = App->physics->CreateCircle(400, 500, 6);
	ball.b->listener = this;

	///////////////// FLIPPER 1 //////////////////////////////////////////////////////////////////////////////////////////

	right_down_flipper.image = App->textures->Load("pinball/right_down_flipper.png");
	int flipper_right_down[16] = {
		244, 631,
		272, 627,
		279, 630,
		279, 639,
		274, 643,
		242, 638,
		236, 633,
		240, 631
	};

	b2Vec2 v1_frd(244, 631);
	b2Vec2 v2_frd(272, 627);
	b2Vec2 v3_frd(279, 630);
	b2Vec2 v4_frd(279, 639);
	b2Vec2 v5_frd(274, 643);
	b2Vec2 v6_frd(242, 638);
	b2Vec2 v7_frd(236, 633);
	b2Vec2 v8_frd(240, 631);

	right_down_flipper.b = App->physics->CreatePolygon(0, 0, v1_frd, v2_frd, v3_frd, v4_frd, v5_frd, v6_frd, v7_frd, v8_frd);
	//right_down_flipper.b = App->physics->CreateScenary(0, 0, flipper_right_down, 16);
	right_down_flipper_wheel = App->physics->CreateCircularObstacle(270 + 5, 632 + 5, 7, 0.0f, true, false);


	b2RevoluteJointDef rjdef;
	rjdef.bodyA = right_down_flipper.b->body;
	rjdef.bodyB = right_down_flipper_wheel->body;

	rjdef.localAnchorA.Set(PIXEL_TO_METERS(270 + 7), PIXEL_TO_METERS(632 + 7));
	rjdef.localAnchorB.Set(PIXEL_TO_METERS(277 + 7), PIXEL_TO_METERS(639 + 7));

	//limits fipper 1

	rjdef.enableLimit = true;
	rjdef.upperAngle = (5 * PI / 6); //150º
	rjdef.lowerAngle = (7 * PI / 6); //210º

	App->physics->WorldGetter()->CreateJoint(&rjdef);


	////////////////// FLIPPER 2 /////////////////////////////////////////////////////////////////////////////////////

	left_down_flipper.image = App->textures->Load("pinball/left_down_flipper.png");
	int flipper_left_down[16] = {
		174, 627,
		205, 631,
		209, 634,
		208, 638,
		173, 642,
		165, 639,
		165, 632,
		166, 627
	};

	b2Vec2 v1_fld(174, 627);
	b2Vec2 v2_fld(205, 631);
	b2Vec2 v3_fld(209, 634);
	b2Vec2 v4_fld(208, 638);
	b2Vec2 v5_fld(173, 642);
	b2Vec2 v6_fld(165, 639);
	b2Vec2 v7_fld(165, 632);
	b2Vec2 v8_fld(166, 627);

	left_down_flipper.b = App->physics->CreatePolygon(0, 0, v1_fld, v2_fld, v3_fld, v4_fld, v5_fld, v6_fld, v7_fld, v8_fld);
	//left_down_flipper.b = App->physics->CreateScenary(0, 0, flipper_left_down, 16);
	left_down_flipper_wheel = App->physics->CreateCircularObstacle(168 + 5, 632 + 5, 7, 0.0f, true, false);

	b2RevoluteJointDef rjdef2;
	rjdef2.bodyA = left_down_flipper.b->body;
	rjdef2.bodyB = left_down_flipper_wheel->body;

	rjdef2.localAnchorA.Set(168 + 17, 632 + 17);
	rjdef2.localAnchorB.Set(175 + 7, 638 + 7);

	//limits fipper 2

	rjdef2.enableLimit = true;
	rjdef2.upperAngle = (5 * PI / 6); //150º
	rjdef2.lowerAngle = (7 * PI / 6); //210º

	App->physics->WorldGetter()->CreateJoint(&rjdef2);



	/////////////////// FLIPPER 3 /////////////////////////////////////////////////////////////////////////////////////
	right_middle_flipper.image = App->textures->Load("pinball/right_middle_flipper.png");
	int flipper_right_middle[16] = {
		352, 391,
		377, 388,
		382, 390,
		382, 396,
		379, 398,
		354, 397,
		350, 396,
		351, 392
	};

	b2Vec2 v1_frm(352, 391);
	b2Vec2 v2_frm(377, 388);
	b2Vec2 v3_frm(382, 390);
	b2Vec2 v4_frm(382, 396);
	b2Vec2 v5_frm(379, 398);
	b2Vec2 v6_frm(354, 397);
	b2Vec2 v7_frm(350, 396);
	b2Vec2 v8_frm(351, 392);

	right_middle_flipper.b = App->physics->CreatePolygon(0, 0, v1_frm, v2_frm, v3_frm, v4_frm, v5_frm, v6_frm, v7_frm, v8_frm);
	//right_middle_flipper.b = App->physics->CreateScenary(0, 0, flipper_right_middle, 16);
	right_middle_flipper_wheel = App->physics->CreateCircularObstacle(375 + 2, 390 + 2, 2, 0.0f, true, false);

	b2RevoluteJointDef rjdef3;
	rjdef3.bodyA = right_middle_flipper.b->body;
	rjdef3.bodyB = right_middle_flipper_wheel->body;

	rjdef3.localAnchorA.Set(30 + 6, 50 + 6);
	rjdef3.localAnchorB.Set(32 + 2, 52 + 2);

	//limits fipper 3

	rjdef3.enableLimit = true;
	rjdef3.upperAngle = (5 * PI / 6); //150º
	rjdef3.lowerAngle = (7 * PI / 6); //210º

	App->physics->WorldGetter()->CreateJoint(&rjdef3);



	/////////////////// FLIPPER 4 /////////////////////////////////////////////////////////////////////////////////////
	left_middle_flipper.image = App->textures->Load("pinball/left_middle_flipper.png");
	int flipper_left_middle[16] = {
		119, 306,
		145, 310,
		148, 312,
		148, 315,
		120, 318,
		116, 316,
		115, 310,
		117, 307
	};

	b2Vec2 v1_flm(119, 306);
	b2Vec2 v2_flm(145, 310);
	b2Vec2 v3_flm(148, 312);
	b2Vec2 v4_flm(148, 315);
	b2Vec2 v5_flm(120, 318);
	b2Vec2 v6_flm(116, 316);
	b2Vec2 v7_flm(115, 310);
	b2Vec2 v8_flm(117, 307);


	left_middle_flipper.b = App->physics->CreatePolygon(0, 0, v1_flm, v2_flm, v3_flm, v4_flm, v5_flm, v6_flm, v7_flm, v8_flm);
	//left_middle_flipper.b = App->physics->CreateScenary(0, 0, flipper_left_middle, 16);
	left_middle_flipper_wheel = App->physics->CreateCircularObstacle(115 + 5, 310 + 5, 5, 0.0f, true, false);

	b2RevoluteJointDef rjdef4;
	rjdef4.bodyA = left_middle_flipper.b->body;
	rjdef4.bodyB = left_middle_flipper_wheel->body;

	rjdef4.localAnchorA.Set(30 + 15, 50 + 15);
	rjdef4.localAnchorB.Set(35 + 5, 55 + 5);

	//limits fipper 4

	rjdef4.enableLimit = true;
	rjdef4.upperAngle = (5 * PI / 6); //150º
	rjdef4.lowerAngle = (7 * PI / 6); //210º

	App->physics->WorldGetter()->CreateJoint(&rjdef4);


	/////////////////// FLIPPER 5 /////////////////////////////////////////////////////////////////////////////////////
	right_up_flipper.image = App->textures->Load("pinball/right_middle_flipper.png");
	int flipper_right_up[16] = {
		341, 137,
		364, 133,
		370, 136,
		370, 142,
		366, 144,
		343, 143,
		339, 142,
		339, 139
	};


	b2Vec2 v1_fru(341, 137);
	b2Vec2 v2_fru(364, 133);
	b2Vec2 v3_fru(370, 136);
	b2Vec2 v4_fru(370, 142);
	b2Vec2 v5_fru(366, 144);
	b2Vec2 v6_fru(343, 143);
	b2Vec2 v7_fru(339, 142);
	b2Vec2 v8_fru(339, 139);

	right_up_flipper.b = App->physics->CreatePolygon(0, 0, v1_fru, v2_fru, v3_fru, v4_fru, v5_fru, v6_fru, v7_fru, v8_fru);
	//right_up_flipper.b = App->physics->CreateScenary(0, 0, flipper_right_up, 16);
	right_up_flipper_wheel = App->physics->CreateCircularObstacle(365 + 5, 134 + 5, 5, 0.0f, true, false);

	b2RevoluteJointDef rjdef5;
	rjdef5.bodyA = right_up_flipper.b->body;
	rjdef5.bodyB = right_up_flipper_wheel->body;

	rjdef5.localAnchorA.Set(30 + 15, 50 + 15);
	rjdef5.localAnchorB.Set(35 + 5, 55 + 5);

	//limits fipper 5

	rjdef5.enableLimit = true;
	rjdef5.upperAngle = (5 * PI / 6); //150º
	rjdef5.lowerAngle = (7 * PI / 6); //210º

	App->physics->WorldGetter()->CreateJoint(&rjdef5);



	/////////////////// FLIPPER 6 /////////////////////////////////////////////////////////////////////////////////////
	left_up_flipper.image = App->textures->Load("pinball/left_middle_flipper.png");
	int flipper_left_up[16] = {
		286, 134,
		312, 137,
		315, 139,
		315, 142,
		311, 144,
		286, 144,
		283, 141,
		283, 137
	};

	b2Vec2 v1_flu(286, 134);
	b2Vec2 v2_flu(312, 137);
	b2Vec2 v3_flu(315, 139);
	b2Vec2 v4_flu(315, 142);
	b2Vec2 v5_flu(311, 144);
	b2Vec2 v6_flu(286, 144);
	b2Vec2 v7_flu(283, 141);
	b2Vec2 v8_flu(283, 137);

	left_up_flipper.b = App->physics->CreatePolygon(0, 0, v1_flu, v2_flu, v3_flu, v4_flu, v5_flu, v6_flu, v7_flu, v8_flu);
	//left_up_flipper.b = App->physics->CreateScenary(0, 0, flipper_left_up, 16);
	left_up_flipper_wheel = App->physics->CreateCircularObstacle(282 + 5, 134 + 5, 5, 0.0f, true, false);

	b2RevoluteJointDef rjdef6;
	rjdef6.bodyA = left_up_flipper.b->body;
	rjdef6.bodyB = left_up_flipper_wheel->body;

	rjdef6.localAnchorA.Set(30 + 15, 50 + 15);
	rjdef6.localAnchorB.Set(35 + 5, 55 + 5);

	//limits fipper 6

	rjdef6.enableLimit = true;
	rjdef6.upperAngle = (5 * PI / 6); //150º
	rjdef6.lowerAngle = (7 * PI / 6); //210º

	App->physics->WorldGetter()->CreateJoint(&rjdef6);


	//SPRING
	spring.image = App->textures->Load("pinball/spring.png");
	spring.b = App->physics->CreateRectangle(395, 600, 20, 20, b2_dynamicBody, 0.2f, true, false); //We'll put a low coefficient of restitution to simulate an small collision when the ball falls down to the spring
	spring.b->listener = this;
	spring_wheel = App->physics->CreateRectangle(395, 625, 20, 20, b2_staticBody, 0.0f, true, false);
	App->physics->CreateLineJoint(spring.b, spring_wheel, 10, 10, 10, 10, 10.0f, 0.0f);

	return true;
}

update_status ModulePlayer::Update(){


	if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_UP)
	{
		b2Vec2 vector(0.0f, -400.0f);
		ball.b->body->ApplyForceToCenter(vector, true);
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
	{

		//App->audio->PlayFx(flipper1.fx);
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		left_down_flipper.b->body->ApplyAngularImpulse(-2 * PI, true);
		left_middle_flipper.b->body->ApplyAngularImpulse(-2 * PI, true);
		left_up_flipper.b->body->ApplyAngularImpulse(-2 * PI, true);
	}

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{

		right_down_flipper.b->body->ApplyAngularImpulse(2 * PI, true);
		right_middle_flipper.b->body->ApplyAngularImpulse(2 * PI, true);
		right_up_flipper.b->body->ApplyAngularImpulse(2 * PI, true);

	}

	float spring_push = 0.0f;
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		spring_push += 175.0f;
		b2Vec2 vector1(0, spring_push);
		spring.b->body->ApplyForceToCenter(vector1, true);
	}
	else {
		spring_push = 0.0f;
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP)
	{
		//App->audio->PlayFx(spring.fx);
	}

	//////////////////////////BALL BLIT///////////////////////////////
	int x, y;
	ball.b->GetPosition(x, y);
	App->renderer->Blit(ball.image, x, y, NULL, 1.0f);

	//////////////////////////SPRING BLIT///////////////////////////////
	int x_spring, y_spring;
	spring.b->GetPosition(x_spring, y_spring);
	App->renderer->Blit(spring.image, x_spring, y_spring, NULL, 1.0f);

	//////////////////////////FLIPPERS BLIT///////////////////////////////
	int x_right_down, y_right_down;
	right_down_flipper.b->GetPosition(x_right_down, y_right_down);
	App->renderer->Blit(right_down_flipper.image, PIXEL_TO_METERS(x_right_down + 227), PIXEL_TO_METERS(y_right_down + 609), NULL, 1.0f, (right_down_flipper.b->body->GetAngle()), 0, 0);

	int x_left_down, y_left_down;
	left_down_flipper.b->GetPosition(x_left_down, y_left_down);
	App->renderer->Blit(left_down_flipper.image, PIXEL_TO_METERS(x_left_down + 200), PIXEL_TO_METERS(y_left_down + 609), NULL, 1.0f, (left_down_flipper.b->body->GetAngle()), 0, 0);

	int x_right_middle, y_right_middle;
	right_middle_flipper.b->GetPosition(x_right_middle, y_right_middle);
	App->renderer->Blit(right_middle_flipper.image, PIXEL_TO_METERS(x_right_middle + 345), PIXEL_TO_METERS(y_right_middle + 381), NULL, 1.0f, (right_middle_flipper.b->body->GetAngle()), 0, 0);

	int x_left_middle, y_left_middle;
	left_middle_flipper.b->GetPosition(x_left_middle, y_left_middle);
	App->renderer->Blit(left_middle_flipper.image, PIXEL_TO_METERS(x_left_middle + 115), PIXEL_TO_METERS(y_left_middle + 304), NULL, 1.0f, (left_middle_flipper.b->body->GetAngle()), 0, 0);

	int x_right_up, y_right_up;
	right_up_flipper.b->GetPosition(x_right_up, y_right_up);
	App->renderer->Blit(right_up_flipper.image, PIXEL_TO_METERS(x_right_up + 337), PIXEL_TO_METERS(y_right_up + 135), NULL, 1.0f, (right_up_flipper.b->body->GetAngle()), 0, 0);

	int x_left_up, y_left_up;
	left_up_flipper.b->GetPosition(x_left_up, y_left_up);
	App->renderer->Blit(left_up_flipper.image, PIXEL_TO_METERS(x_left_up + 282), PIXEL_TO_METERS(y_left_up + 132), NULL, 1.0f, (left_up_flipper.b->body->GetAngle()), 0, 0);


	return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp(){

	//Unloading textures
	App->textures->Unload(ball.image);


	//Destroying bodies
	App->physics->DestroyBody(ball.b);
	App->physics->DestroyBody(right_down_flipper.b);
	App->physics->DestroyBody(left_down_flipper.b);
	App->physics->DestroyBody(right_middle_flipper.b);
	App->physics->DestroyBody(left_middle_flipper.b);
	App->physics->DestroyBody(right_up_flipper.b);
	App->physics->DestroyBody(left_up_flipper.b);
	App->physics->DestroyBody(spring.b);

	return true;
}


