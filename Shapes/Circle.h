#pragma once
#include "shape.h"

class Circle : public shape
{
private:
	Point point1;
	Point point2;
	bool Saved;
	

public:
	Circle(Point, Point ,GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	bool ShapeSaved() const; // returns if circle is saved or not
	void SetShapeSaved(bool s); // sets if the shape is saved or not
	
	virtual bool point_included(int x, int y);
	virtual void Save(ofstream& outfile) ;
	string shapeInfo(); 
	shape* duplicate(shape*);
	void resize(double) override;
	virtual void Rotate(GUI* pUI);
	virtual void Hidding(GUI* pUI);
};
