#pragma once
#include "GraphicalShell.h"
#include "String"
#include "Field.h"

class Drawer {
private:
	GraphicalShell* image;
	float        x;	            // x position
	float        y;            // y position
	float        dx;          // x offset
	float        dy;         // y offset
	float        speed;     //Drawer's speed
	Field*       field;    //Field
	int          target;  // Àmount of field to be deleted(%)
	
	bool is_on_the_field;
	bool is_win;
public:
	Drawer(const String path, Field& field);
	void setPosition(const float x, const float y);
	void moveTo(const float x, const float y);
	void update(const float time);
	bool on_the_field();
	int getTarget();
	~Drawer();
	Sprite& getSprite();
	bool is_drawer_win();
	



	
};