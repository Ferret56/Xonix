#include "Enemy.h"
#include "Field.h"
#include "time.h"
#include <iostream>

Enemy::Enemy(const String path, Field& field) {
	this->image = new GraphicalShell(path);
	this->field = &field;
	x = ROWS - 2;
	y = LINES - 2;	
	dx = dy = -1;	
	setPosition(x, y);
	is_alive = true;
}

Enemy::~Enemy() {
	delete this->image;
	delete this->field;
}


void Enemy::setPosition(const float x1, const float y1){
	this->image->setPosition(field->getStartX() + 20 * x1, field->getStartY() + 20 * y1);
	this->x = x1;
	this->y = y1;	
}

void Enemy::update(){
	setPosition(x + dx/10 , y);

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
		is_alive = false;
}

bool Enemy::is_enemy_alive() { return this->is_alive; }
Sprite& Enemy::getSprite() {return this->image->getSprite();}


