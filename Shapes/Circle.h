#pragma once
#include "shape.h"

class Circle : public shape
{
private:
	Point point1;
	Point point2;
public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual bool point_included(int x, int y);
};
