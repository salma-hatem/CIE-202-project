#include "Triangle.h"

Triangle::Triangle(Point P1, Point P2,Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
	Saved = false;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Triangle on the screen	
	pUI->DrawTriangle(point1, point2, point3, ShpGfxInfo);
}

void Triangle::Save(ofstream& outfile) {
	//char info[100];
	outfile << "TRI" << " Id " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << " " << point3.x << " " << point3.y << endl;
	SetShapeSaved(true);
	SetAllSaved(true);

}
bool Triangle::ShapeSaved() const {
	return Saved;
}

void Triangle::SetShapeSaved(bool s) {
	Saved = s;
}