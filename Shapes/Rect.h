#pragma once
#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;
	Point Corner2;
	bool Saved;
	Point Corner3;
	Point OG_Corner1;
	Point OG_Corner2;
	Point OG_Corner3;
	double l;
	double w;
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual bool point_included(int x, int y);
	bool ShapeSaved() const; // returns if Shape is saved or not
	void SetShapeSaved(bool s); // sets if the shape is saved or not
	virtual void Save(ofstream& outfile);
	string shapeInfo();
	shape* duplicate(shape*);
	void resize(double) override;
	virtual void Rotate(GUI* pUI);
	void scrambleShape();
	void scrambleShape(Point, int, int) override;
	void calculateWH() override;
	double getfactor(int col, int row) override;
	virtual void Hidding(GUI* pUI);
	virtual string shapename();
	virtual void Move(int& x, int& y);
	virtual void UnMove();
};

