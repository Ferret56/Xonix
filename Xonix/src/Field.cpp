#include "Field.h"


Field::Field(){
	field = new pair<int, Plate*>*[MAX_HEIGHT];
	for (int i = 0; i < MAX_HEIGHT; ++i) {
		field[i] = new pair<int, Plate*>[MAX_WIDTH];
	}
	generateField();
}

void Field::draw(RenderWindow* window) {
	for (int i = 0; i < MAX_HEIGHT; ++i) {
		for (int j = 0; j < MAX_WIDTH; ++j) {		
				window->draw(field[i][j].second->getSprite());
			}
		}	
}

void Field::update(const float time) {
	//TODO

	for (int i = 0; i < MAX_HEIGHT; ++i) {
		for (int j = 0; j < MAX_WIDTH; ++j) {
			
		}
	}	
}



/*1 for the border
0 for the field*/
void Field::generateField() {
	float x_position = 600;
	float y_position = 200;
	int type = 0;
	for (int i = 0; i < MAX_HEIGHT; ++i) {
		for (int j = 0; j < MAX_WIDTH; ++j) {
			if (i == 0 || i == MAX_HEIGHT - 1 || j == 0 || j == MAX_WIDTH - 1)
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




