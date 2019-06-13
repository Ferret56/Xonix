#include "Plate.h"

Plate::Plate(const String path, const float x, const float y) {
	image = new GraphicalShell(path);
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
}

Sprite Plate::getSprite() {
	return this->image->getSprite();
}


