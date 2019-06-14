#include "Enemy.h"
#include "Field.h"
#include "time.h"


Enemy::Enemy(){}
Enemy::Enemy(const String path) {
	this->image = new GraphicalShell(path);
	x = 800;
	y = 600;
	dx = dy = -1;
	setPosition(x, y);
	angle = 135;
}
Enemy::~Enemy() {
	delete this->image;
}


void Enemy::setPosition(const float x, const float y) {
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
}

void Enemy::update() {
	//srand(NULL);
	x += dx;
	y += dy;	

	setPosition(x, y);
}

void Enemy::changeDirection(){	
	if (angle >= 90 && angle <= 180) {
		angle = rand() % 90;
		dx = 1;
		dy = -1;
		x += dx;
		y += dy;
		setPosition(x, y);
		return;
	}

	if (angle >= 180 && angle <= 270) {
		angle = rand() % 270;
		dx = -1;
		dy = 1;
		x += dx;
		y += dy;
		setPosition(x, y);
		return;

	}

	setPosition(x, y);
}





Sprite Enemy::getSprite() {
	return this->image->getSprite();
}


