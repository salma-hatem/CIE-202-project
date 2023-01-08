#pragma once
#include "shape.h"

class Line : public shape
{
private:
	Point point1;
	Point point2;
	bool Saved;
	Point OG_point1;
	Point OG_point2;
	double line_length;
	int COO_X_change;
	int COO_y_change;
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
	void scrambleShape() override;
	void scrambleShape(Point, int, int) override;
	void calculateWH() override;
	double getfactor(int col, int row) override;
	virtual void Hidding(GUI* pUI);
	virtual string shapename();
	virtual void UnMove();
	virtual void Move(int& x, int& y);
};

