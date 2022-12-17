#pragma once
#include "shape.h"

class Triangle : public shape
{
private:
	Point point1;
	Point point2;
	Point point3;
public:
	Triangle(Point, Point,Point, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;
	double trianglearea(int, int, int, int, int, int);
	virtual bool point_included(int x, int y);
	string shapeInfo();
};

#pragma once
