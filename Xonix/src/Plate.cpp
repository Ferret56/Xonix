#include "Plate.h"


Plate::Plate(const String path, const float x, const float y){
	image = new GraphicalShell(path);
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
	this->status = FREE;
}

Sprite Plate::getSprite() {
	return this->image->getSprite();
}

void Plate::setStatus(Statuses status) {
	this->status = status;
}


