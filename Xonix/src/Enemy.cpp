#include "Enemy.h"
#include "Field.h"
#include "time.h"


Enemy::Enemy(){}
Enemy::Enemy(const String path) {
	this->image = new GraphicalShell(path);
	x = 800;
	y = 600;
	dx = dy = -1;
	speed = 0.1;
	setPosition(x, y);	
}
Enemy::~Enemy() {
	delete this->image;
}


void Enemy::setPosition(const float x, const float y) {
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
}

void Enemy::update(const float time) {
	//srand(NULL);
	//dx = speed;
	//dy = speed;
	x += dx;
	y += dy;
	setPosition(x, y);
}

void Enemy::changeDirection(){	
	

	setPosition(x, y);
}





Sprite Enemy::getSprite() {
	return this->image->getSprite();
}


