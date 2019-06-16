#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicalShell.h"
#include "String"

class Plate {
private:
	GraphicalShell*    image;
	float              x;   // x position
	float              y;  // y position
	
	

public:
	enum Statuses { FREE, BORDER, CAPTURE };
	void setStatus(Statuses status);
	Plate(const String path, const float x, const float y);
	~Plate();
	Sprite getSprite();

private:
	Statuses status;
};