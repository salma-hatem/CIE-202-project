#pragma once
#include "shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
<<<<<<< HEAD
=======
	bool Saved;
>>>>>>> origin/salma
public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
<<<<<<< HEAD
	virtual bool point_included(int x, int y);
};
=======
	bool ShapeSaved() const; // returns if shape is saved or not
	void SetShapeSaved(bool s); // sets if the shape is saved or not
	void Save(ofstream& outfile);
};

>>>>>>> origin/salma
