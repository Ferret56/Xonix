#include "Field.h"


Field::Field(const String path, const float x, const float y){
	this->start_x = x;
	this->start_y = y;
	field = new pair<int, Plate*>*[LINES];
	for (int i = 0; i < LINES; ++i) {
		field[i] = new pair<int, Plate*>[ROWS];
	}
	generateField(path,x,y);
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

pair<int, Plate*>** Field::getField(){
	return field;
}

int Field::getFieldPercentage() { return this->fieldPercentage; }

int Field::getStartX() { return this->start_x; }

int Field::getStartY(){return this->start_y;}



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
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			if (field[i][j].first == Plate::CAPTURE) {
				field[i][j].first = Plate::BORDER;
			}
		}
	}	
}

void Field::generateField(const String path, const float x, const float y) {	
	float x_position = x;
	float y_position = y;
	int status = Plate::FREE;
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < ROWS; ++j) {
			if (i == 0 || i == LINES - 1 || j == 0 || j == ROWS - 1)
				status = Plate::BORDER;						
			else
				status = Plate::FREE;
			field[i][j] = make_pair(status, new Plate(path, x_position, y_position));			
			x_position += 20;
		}
		x_position = x;  
		y_position += 20;
	}	
}




