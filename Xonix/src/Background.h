#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicalShell.h"

class Background {
private:
	GraphicalShell* graphicalshell;
	



public:
	Background(const String file);
	~Background();

	Sprite getImage();
	


};