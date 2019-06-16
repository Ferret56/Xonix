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

	bool is_on_the_field;
public:
	Drawer(const String path, Field& field);
	void setPosition(const float x, const float y);
	void moveTo(const float x, const float y);
	void update(const float time);
	bool on_the_field();
	~Drawer();
	Sprite& getSprite();
	



	
};