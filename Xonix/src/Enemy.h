#pragma once
#include "GraphicalShell.h"
//#include "Field.h"
#include "String"

class Enemy {
private:	
	GraphicalShell*   image;
	float             x;	   // x position
	float             y;      // y position
	float             dx;    // x offset
	float             dy;   // y offset
	float             angle;
	
public:
	Enemy(const String path);
	Enemy();
	void setPosition(const float x, const float y);
	void update();
	void changeDirection();
	~Enemy();
	Sprite getSprite();
};