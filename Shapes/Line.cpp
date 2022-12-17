#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	Saved = false;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(point1, point2, ShpGfxInfo);
}

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
}