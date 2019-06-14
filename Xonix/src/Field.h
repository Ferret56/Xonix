#pragma once
#include "GraphicalShell.h"
#include "Plate.h"
#include "Enemy.h"
#include "String"
#include <vector>

#define MAX_WIDTH 25
#define MAX_HEIGHT 17
using namespace std;

class Field {
private:	
	pair<int, Plate*>   **field;
	Enemy* enemy;

	
public:
	Field();
	void generateField();
	void draw(RenderWindow* window);
	void update(const float time);

};