#include "Field.h"


Field::Field(){
	field = new pair<int, Plate*>*[MAX_WIDTH];
	for (int i = 0; i < MAX_WIDTH; ++i) {
		field[i] = new pair<int, Plate*>[MAX_HEIGHT];
	}
	generateField();
	enemy = new Enemy("src/images/drawers/enemy.png");
}

void Field::draw(RenderWindow* window) {
	for (int i = 0; i < MAX_WIDTH; ++i) {
		for (int j = 0; j < MAX_HEIGHT; ++j) {		
				window->draw(field[i][j].second->getSprite());
			}
		}
	window->draw(this->enemy->getSprite());
}

void Field::update(const float time) {
	//TODO
	this->enemy->update(time);
	for (int i = 0; i < MAX_WIDTH; ++i) {
		for (int j = 0; j < MAX_HEIGHT; ++j) {
			if (field[i][j].second->getSprite().getGlobalBounds().intersects(this->enemy->getSprite().getGlobalBounds())
			&& field[i][j].first == 1) {
				this->enemy->changeDirection();
			}
		}
	}	
}



/*1 for the border
0 for the field*/
void Field::generateField() {
	float x_position = 600;
	float y_position = 200;
	int type = 0;
	for (int i = 0; i < MAX_WIDTH; ++i) {
		for (int j = 0; j < MAX_HEIGHT; ++j) {
			if (i == 0 || i == MAX_WIDTH - 1 || j == 0 || j == MAX_HEIGHT - 1)
				type = 1;
			else
				type = 0;
			field[i][j] = make_pair(type, new Plate("src/images/field/solid.png", x_position, y_position));
			x_position += 20;
		}
		x_position = 600;  
		y_position += 20;
	}
}



