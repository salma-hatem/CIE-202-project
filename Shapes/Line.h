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
	virtual bool point_included(int x, int y);
	virtual void Save(ofstream& outfile);
	string shapeInfo();
	shape* duplicate(shape*);
	void resize(double) override;
	virtual void Rotate(GUI* pUI);
<<<<<<< HEAD
	virtual void Hidding(GUI* pUI);
	virtual string shapename();
=======
	void scrambleShape() override;
	void scrambleShape(Point, int, int) override;
	void calculateWH() override;
	double getfactor(int col, int row) override;
>>>>>>> origin/salma
};

