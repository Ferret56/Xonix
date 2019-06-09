#include "Drawer.h"

Drawer::Drawer(const String path){
	this->image = new GraphicalShell(path);
	x = y = 500;
	setPosition(x, y);
	
}

void Drawer::setPosition(const float x, const float y){
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
}

void Drawer::update() {

}




Sprite Drawer::getSprite() { return this->image->getSprite(); }


