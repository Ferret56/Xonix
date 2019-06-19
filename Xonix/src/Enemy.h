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
	Field *           field;        //field 

	bool is_alive;

public:
	Enemy(const String path,  Field& field);	
	void setPosition(const float x, const float y);
	void update();	
	bool is_enemy_alive();
	~Enemy();
	Sprite& getSprite();
};