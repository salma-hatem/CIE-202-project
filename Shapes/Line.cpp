#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
<<<<<<< HEAD
=======
	Saved = false;
>>>>>>> origin/salma
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(point1, point2, ShpGfxInfo);
}
<<<<<<< HEAD
bool Line::point_included(int x, int y) {
	if (x > point1.x && x<point2.x && y>point1.y && y < point2.y) {
		return true;
	}
	else { return false; }
=======

void Line::Save(ofstream& outfile) {
	outfile << "Line" << " Id " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << endl;
	SetShapeSaved(true);
	SetAllSaved(true);
}

bool Line::ShapeSaved() const {
	return Saved;
}

void Line::SetShapeSaved(bool s) {
	Saved = s;
>>>>>>> origin/salma
}