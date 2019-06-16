#include "Enemy.h"
#include "Field.h"
#include "time.h"
#include <iostream>



Enemy::Enemy(const String path, Field& field) {
	this->image = new GraphicalShell(path);
	this->field = &field;
	x = 15;
	y = 23;
	speed = 0.04;
	dx = dy = -1;
	/*dirVector.x = -0.9f;
	dirVector.y = -1.2f;*/
	setPosition(x, y);	
}

Enemy::~Enemy() {
	delete this->image;
}


void Enemy::setPosition(const float x1, const float y1) {
	this->image->setPosition(600 + 20 * x1, 200 + 20 * y1);
	this->x = x1;
	this->y = y1;	
}

void Enemy::update(const float time) {	
	setPosition(x + dx/10, y);
	std::cout << "\t\t" << x << " " << y << std::endl;
	if (field->getPlateByCoordinates(y, x).first == Plate::BORDER) {
		dx = -dx;
		setPosition(x + dx/10, y);
	}
	setPosition(x, y + dy/10);
	if (field->getPlateByCoordinates(y, x).first == Plate::BORDER) {
		dy = -dy;
		setPosition(x, y + dy/10);
	}

	if (field->getPlateByCoordinates(y, x).first == Plate::CAPTURE)
		setPosition(0, 0);
	
}




void Enemy::changeDirection(const float time){		
	//dirVector.x = -dirVector.x;
	//dirVector.y = 1;
}

void Enemy::moveTo(const float x, const float y) {
	this->image->moveTo(600 + 20 * x, 200 + 20 * y);
}


	



Sprite& Enemy::getSprite() {
	return this->image->getSprite();
}


