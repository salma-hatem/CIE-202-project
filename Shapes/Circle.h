#pragma once
#include "shape.h"

class Circle : public shape
{
private:
	Point point1;
	Point point2;
	Point OG_point1;
	Point OG_point2;
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
	void scrambleShape() override;
	void scrambleShape(Point,int,int) override;
	void calculateWH() override;
	double getfactor(int col, int row) override;
	virtual void Hidding(GUI* pUI);
	virtual string shapename();

	virtual void Move(int& x, int& y);
	virtual void UnMove();
};
