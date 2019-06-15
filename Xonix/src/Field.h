#pragma once
#include "GraphicalShell.h"
#include "Plate.h"
#include "String"
#include <vector>

#define MAX_HEIGHT 25
#define MAX_WIDTH 17

using namespace std;

class Field {
private:	
	pair<int, Plate*>   **field;
	
public:
	Field();
	void generateField();
	void draw(RenderWindow* window);
	void update(const float time);

};