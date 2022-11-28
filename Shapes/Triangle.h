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
};

#pragma once
