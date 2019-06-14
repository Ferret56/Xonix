#include "Drawer.h"
#include "iostream"
using namespace std;

Drawer::Drawer(const String path){
	this->image = new GraphicalShell(path);
	x = y = 500;
	dx = dy = 0;
	setPosition(x, y);
	
}

void Drawer::setPosition(const float x, const float y){
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
}

void Drawer::update() {	
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		dx = 2;
		dy = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		dx = -2;
		dy = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		dx = 0;
		dy = -2;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		dx = 0;
		dy = 2;
	}

	x += dx;
	y += dy;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	
	std::cout << x << std::endl;

	setPosition(x, y);

}




Sprite Drawer::getSprite() { return this->image->getSprite(); }


