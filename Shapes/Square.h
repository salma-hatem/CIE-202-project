#pragma once
#include "shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
	bool Saved;
public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual bool point_included(int x, int y);
	bool ShapeSaved() const; // returns if shape is saved or not
	void SetShapeSaved(bool s); // sets if the shape is saved or not
	virtual void Save(ofstream& outfile);
	string shapeInfo();
	shape* duplicate(shape*);
	void resize(double) override;
	virtual void Rotate(GUI* pUI);
<<<<<<< HEAD
	virtual void Hidding(GUI* pUI);
	virtual string shapename();
=======
	void scrambleShape();
	void scrambleShape(Point, int, int) override;
	void calculateWH() override;
	double getfactor(int col, int row) override;
>>>>>>> origin/salma
};