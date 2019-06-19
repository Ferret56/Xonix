#pragma once
#include "GraphicalShell.h"
#include "Plate.h"
#include "String"
#include <vector>
using namespace std;

#define LINES 25
#define ROWS 17

class Field{
private:	
	pair<int, Plate*>     **field;
	int                   fieldPercentage;
	float                 start_x;
	float                 start_y;
	
public:
	Field(const String path,const float x, const float y);
	void generateField(const String path, const float x, const float y);
	void draw(RenderWindow* window);
	pair <int, Plate*> getPlateByCoordinates(const int i, const int j);
	pair<int, Plate*>** getField();
	int getFieldPercentage();
	int getStartX();
	int getStartY();
	void updatePercentage();
	void update(const float time);

};