#include "Drawer.h"
#include "iostream"
using namespace std;

Drawer::Drawer(const String path, Field& field){
	this->image = new GraphicalShell(path);		
	this->field = &field;
	this->is_on_the_field = false;	
	this->image->getSprite().setOrigin(15, 10);
	this->target = 10;
	x = field.getStartX() - 200;
	y = field.getStartY() + 200;
	dx = dy = 0;
	speed = 0.09;
	setPosition(x, y);	
	is_win = false;
}

Drawer::~Drawer() {
	delete this->image;
	delete this->field;
}

void Drawer::setPosition(const float x, const float y){
	this->x = x;
	this->y = y;
	this->image->setPosition(x, y);
}

void Drawer::processEvents() {
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
}

void Drawer::update(const float time){
	x += dx  * time;
	y += dy * time;

	if (x <= 0) x = 0;
	if (y <= 0) y = 0;
	if (x >= 1500) x = 1500;
	if (y >= 850) y = 850;

	setPosition(x, y);

	pair<int, Plate*>** field = this->field->getField();
	bool found_it = false;	
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {			
				Vector2f vec = field[i][j].second->getSprite().getPosition();
				if (this->image->getSprite().getGlobalBounds().contains(vec.x + 10, vec.y + 10)){
					field[i][j].first = Plate::CAPTURE;
					found_it = true;
					this->is_on_the_field = true;							
			}
		}
	}

	if (found_it == false)
		this->is_on_the_field = false;

	if (this->target == (100 - this->field->getFieldPercentage()))
		is_win = true;
}

bool Drawer::on_the_field() { return this->is_on_the_field; }

int Drawer::getTarget() { return this->target;}
Sprite& Drawer::getSprite() { return this->image->getSprite();}
bool Drawer::is_drawer_win() { return this->is_win;}






