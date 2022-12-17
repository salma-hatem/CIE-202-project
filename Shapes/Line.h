#pragma once
#include "shape.h"

class Line : public shape
{
private:
	Point point1;
	Point point2;
<<<<<<< HEAD
=======
	bool Saved;
>>>>>>> origin/salma
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
<<<<<<< HEAD
	virtual bool point_included(int x, int y);
=======
	bool ShapeSaved() const; // returns if shape is saved or not
	void SetShapeSaved(bool s); // sets if the shape is saved or not
	void Save(ofstream& outfile);
>>>>>>> origin/salma
};

