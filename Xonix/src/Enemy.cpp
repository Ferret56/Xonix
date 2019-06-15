#include "Enemy.h"
#include "Field.h"
#include "time.h"



Enemy::Enemy(const String path, Field& field) {
	this->image = new GraphicalShell(path);
	this->field = &field;
	x = 0;
	y = 0;
	speed = -0.04;
	dx = dy = speed;
	/*dirVector.x = -0.9f;
	dirVector.y = -1.2f;*/
	setPosition(x, y);	
}

Enemy::~Enemy() {
	delete this->image;
}


void Enemy::setPosition( float x1,  float y1) {
	this->x = x1;
	this->y = y1;	
	this->image->setPosition(600 + 20 * y1, 200 + 20 * x1);
}

void Enemy::update(const float time) {
	
	setPosition(x+1, y+1);
}

void Enemy::changeDirection(const float time){		
	//dirVector.x = -dirVector.x;
	//dirVector.y = 1;
}





Sprite Enemy::getSprite() {
	return this->image->getSprite();
}


