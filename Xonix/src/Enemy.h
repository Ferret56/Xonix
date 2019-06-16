#pragma once
#include "GraphicalShell.h"
#include "Field.h"
#include "String"

class Enemy {
private:	
	GraphicalShell*   image;
	float             x;	            // x position on the field(from (0) to LINES)
	float             y;               // y position in the field(from (0) to ROWS)
	float             dx;             // x offset
	float             dy;            // y offset
	float             speed;        //Enemy's speed
	Vector2f          dirVector;   //Vector of the direction
	Field *           field;      //field 

public:
	Enemy(const String path,  Field& field);	
	void setPosition(const float x, const float y);
	void update(const float time);
	void changeDirection(const float time);	
	void moveTo(const float x, const float y);
	~Enemy();
	Sprite& getSprite();
};