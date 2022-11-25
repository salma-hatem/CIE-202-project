#pragma once
#include "shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
};

