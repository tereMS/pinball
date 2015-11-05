#pragma once
#include "Module.h"
#include "Globals.h"
#include "Box2D/Box2D/Box2D.h"

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f // if touched change METER_PER_PIXEL too
#define METER_PER_PIXEL 0.02f // this is 1 / PIXELS_PER_METER !

#define METERS_TO_PIXELS(m) ((int) floor(PIXELS_PER_METER * m))
#define PIXEL_TO_METERS(p)  ((float) METER_PER_PIXEL * p)

// Small class to return to other modules to track position and rotation of physics bodies
class PhysBody
{
public:
	PhysBody() : listener(NULL), body(NULL)
	{}
	void GetPosition(int& x, int &y) const;
	bool Contains(int x, int y) const;
public:
	int width, height;
	b2Body* body; 
	Module* listener;
};

// Module --------------------------------------
class ModulePhysics : public Module, public b2ContactListener
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();
	void DestroyBody(PhysBody* body);

	PhysBody* CreateRectangle(int x, int y, int width, int height, b2BodyType type, float restitution, bool bullet, bool sensor);
	PhysBody* CreateCircle(int x, int y, int radius);
	PhysBody* CreatePolygon(int x, int y, b2Vec2 point1, b2Vec2 point2, b2Vec2 point3, b2Vec2 point4, b2Vec2 point5, b2Vec2 point6, b2Vec2 point7, b2Vec2 point8);
	PhysBody* CreateCircularObstacle(int x, int y, int radius, float restitution, bool bullet, bool sensor);
	PhysBody* CreateChain(int x, int y, int* points, int size);
	PhysBody* CreateScenary(int x, int y, int* points, int size);

	void CreateLineJoint(PhysBody* body_1, PhysBody* body_2, int x_pivot_1, int y_pivot_1, int x_pivot_2, int y_pivot_2, float frequency, float damping);
	void BeginContact(b2Contact* contact);
	b2World* WorldGetter(){ return world; }

	b2Body* ground;
	b2MouseJoint* mouse_joint;
	b2Body* click;
	b2Vec2 mouse_position;
private:
	
	bool debug;
	p2List<PhysBody*> bodies;
	b2World* world;
	
};