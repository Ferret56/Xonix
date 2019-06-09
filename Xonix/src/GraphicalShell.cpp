#include "GraphicalShell.h"

GraphicalShell::GraphicalShell(const String path){

	this->path = path;
	texture.loadFromFile(path);
	sprite.setTexture(texture);	
}

GraphicalShell::~GraphicalShell() {}

Sprite GraphicalShell::getSprite() { return this->sprite; }


