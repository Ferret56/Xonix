#pragma once

class Point2D {
private:
	float x;    // x coordinte
	float y;   // y coordinate

public:
	Point2D(const float x, const float y);
	void setX(const float x);
	void setY(const float y);
	void setPoint2D(const float x, const float y);
	float getX();
	float getY();
	

};