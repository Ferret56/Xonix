#include "Field.h"


Field::Field(){
	field = new pair<int, Plate*>*[LINES];
	for (int i = 0; i < LINES; ++i) {
		field[i] = new pair<int, Plate*>[ROWS];
	}
	generateField();
}

void Field::draw(RenderWindow* window) {
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
				if(field[i][j].first == 0)
				     window->draw(field[i][j].second->getSprite());
			}
		}	
}

pair<int, Plate*> Field::getPlateByCoordinates(const int i, const int j) {
	return this->field[i][j];
}

pair<int, Plate*>** Field::getField() {
	return field;
}



void Field::update(const float time) {
	//TODO

	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			
		}
	}	
}



/*1 for the border
0 for the field*/
void Field::generateField() {	
	float x_position = 600;
	float y_position = 200;
	int type = 0;
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			if (i == 0 || i == LINES - 1 || j == 0 || j == ROWS - 1)
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




