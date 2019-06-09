#include "GraphicalShell.h"

GraphicalShell::GraphicalShell(const String path){

	this->path = path;
	texture.loadFromFile(path);
	sprite.setTexture(texture);	
}

GraphicalShell::~GraphicalShell() {}

void GraphicalShell::setPosition(const float x, const float y) {
	this->sprite.setPosition(x, y);
}

Sprite GraphicalShell::getSprite() { return this->sprite; }


