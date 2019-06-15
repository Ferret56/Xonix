#pragma once
#include "GraphicalShell.h"
#include "Field.h"
#include "String"

class Enemy {
private:	
	GraphicalShell*   image;
	float             x;	            // x position
	float             y;               // y position
	float             dx;             // x offset
	float             dy;            // y offset
	float             speed;        //Enemy's speed
	Vector2f          dirVector;   //Vector of the direction
	Field *           field;      //field 

public:
	Enemy(const String path,  Field& field);	
	void setPosition( float x,  float y);
	void update(const float time);
	void changeDirection(const float time);	
	~Enemy();
	Sprite getSprite();
};