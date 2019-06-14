#pragma once
#include <SFML/Graphics.hpp>
#include "String"
using namespace sf;

class GraphicalShell{
private:
	String  path;			//the path to the file
	Texture texture;	   //GraphicalShell texture
	Sprite  sprite;       //GraphicalShell sprite
	

public:
	GraphicalShell(const String path);
	~GraphicalShell();
	void setPosition(const float x, const float y);
	void moveTo(const float x, const float y);

	Sprite getSprite();
};