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
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		dx = 1;
		dy = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		dx = -1;
		dy = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		dx = 0;
		dy = -1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		dx = 0;
		dy = 1;
	}

	x += dx;
	y += dy;

	setPosition(x, y);

}




Sprite Drawer::getSprite() { return this->image->getSprite(); }


