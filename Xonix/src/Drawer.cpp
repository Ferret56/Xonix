#include "Drawer.h"
#include "iostream"
using namespace std;



Drawer::Drawer(const String path, Field& field){
	this->image = new GraphicalShell(path);		
	this->field = &field;
	x = 500;
	y = 200;
	dx = dy = 0;
	speed = 0.1;
	setPosition(x, y);	
}

void Drawer::setPosition(const float x, const float y){
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
}

void Drawer::moveTo(const float x, const float y) {
	this->x = x;
	this->y = y;
	this->image->moveTo(x, y);
}


void Drawer::update(const float time) {	
	
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		dx = speed;
		dy = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		dx = -speed;
		dy = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		dx = 0;
		dy = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		dx = 0;
		dy = speed;
	}

	x += dx * time;
	y += dy * time;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	
	

	std::cout << x <<"   "<< y << std::endl;	
	setPosition(x, y);

	pair<int, Plate*>** field = this->field->getField();
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			Vector2f vec = field[i][j].second->getSprite().getPosition();
			if (this->image->getSprite().getGlobalBounds().contains(vec.x+10, vec.y+10)) {
				field[i][j].first = 1;
				break;
			}

		}
	}
	
	//moveTo(x, y);

}




Sprite& Drawer::getSprite() { return this->image->getSprite(); }





