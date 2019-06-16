#include "Field.h"


Field::Field(){
	field = new pair<int, Plate*>*[LINES];
	for (int i = 0; i < LINES; ++i) {
		field[i] = new pair<int, Plate*>[ROWS];
	}
	generateField();
	this->fieldPercentage = 100;
}

void Field::draw(RenderWindow* window) {
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			if (field[i][j].first == Plate::FREE) 
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

int Field::getFieldPercentage() { return this->fieldPercentage; }

void Field::updatePercentage() {
	int count = 0;
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			if (field[i][j].first == Plate::FREE)
				count++;
		}
	}
	this->fieldPercentage = (count * 100) / ((ROWS * LINES) - (ROWS * 2 + LINES * 2 - 4));
}




void Field::update(const float time) {
	//TODO

	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			if (field[i][j].first == Plate::CAPTURE) {
				field[i][j].first = Plate::BORDER;
			}
		}
	}	
}



/*1 for the border
0 for the field*/
void Field::generateField() {	
	float x_position = 600;
	float y_position = 200;
	int status = Plate::FREE;
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			if (i == 0 || i == LINES - 1 || j == 0 || j == ROWS - 1)
				status = Plate::BORDER;						
			else
				status = Plate::FREE;
			field[i][j] = make_pair(status, new Plate("src/images/field/solid.png", x_position, y_position));			
			x_position += 20;
		}
		x_position = 600;  
		y_position += 20;
	}
	
}




