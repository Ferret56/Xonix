#include "Point2D.h"

Point2D::Point2D(const float x, const float y) {
	this-> x = x;
	this-> y = y;
}

void Point2D::setX(const float x) { this->x = x; }


void Point2D::setY(const float y){ this->y = y; }

void Point2D::setPoint2D(const float x, const float y) {
	setX(x);
	setY(y);
}

float Point2D::getX() { return this->x; }
float Point2D::getY() { return this->y; }



