#pragma once
#include "shape.h"

class Triangle : public shape
{
private:
	Point point1;
	Point point2;
	Point point3;
	Point OG_point1;
	Point OG_point2;
	Point OG_point3;
	bool Saved;
public:
	Triangle(Point, Point,Point, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;
	double trianglearea(int, int, int, int, int, int);
	virtual bool point_included(int x, int y);
	bool ShapeSaved() const; // returns if shape is saved or not
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

//#pragma once
