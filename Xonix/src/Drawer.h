#pragma once
#include "GraphicalShell.h"
#include "String"

class Drawer {
private:
	GraphicalShell* image;
	float x;	      // x position
	float y;         // y position
	float dx;       // x offset
	float dy;      // y offset
	float speed;  //Drawer's speed


public:
	Drawer(const String path);
	void setPosition(const float x, const float y);
	void moveTo(const float x, const float y);
	void update(const float time);
	~Drawer();
	Sprite getSprite();



	
};