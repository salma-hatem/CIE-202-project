#pragma once
#include "shape.h"

class Line : public shape
{
private:
	Point point1;
	Point point2;
	bool Saved;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	bool ShapeSaved() const; // returns if shape is saved or not
	void SetShapeSaved(bool s); // sets if the shape is saved or not
	void Save(ofstream& outfile);
	virtual bool point_included(int x, int y);
};
