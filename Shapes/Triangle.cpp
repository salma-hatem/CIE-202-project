#include "Triangle.h"

Triangle::Triangle(Point P1, Point P2,Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Triangle on the screen	
	pUI->DrawTriangle(point1, point2, point3, ShpGfxInfo);
}