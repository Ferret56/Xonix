#include "Background.h"

Background::Background(const String file){
	graphicalshell = new GraphicalShell(file);
}

Background::~Background(){
	delete graphicalshell;
}

Sprite Background::getImage() { return this->graphicalshell->getSprite();}

