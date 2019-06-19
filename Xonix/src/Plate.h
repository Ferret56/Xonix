#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicalShell.h"
#include "String"

//Single plate class
class Plate{
private:
	GraphicalShell*    image;
	float              x;   // x position
	float              y;  // y position

public:	
	Plate(const String path, const float x, const float y);
	~Plate();
	enum Statuses { FREE, BORDER, CAPTURE };
	void setStatus(Statuses status);
	Sprite getSprite();
private:
	Statuses status;
};