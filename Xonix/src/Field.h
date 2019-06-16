#pragma once
#include "GraphicalShell.h"
#include "Plate.h"
#include "String"
#include <vector>

#define LINES 25
#define ROWS 17

using namespace std;

class Field {
private:	
	pair<int, Plate*>   **field;
	
public:
	Field();
	void generateField();
	void draw(RenderWindow* window);
	pair <int, Plate*> getPlateByCoordinates(const int i, const int j);
	pair<int, Plate*>** getField();
	void update(const float time);

};