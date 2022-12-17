#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(point1, point2, ShpGfxInfo);
}
bool Line::point_included(int x, int y) {
	double original_slope = (point2.y - point1.y) / (point2.x - point1.x);
	double new_slope= (y - point1.y) / (x - point1.x);
	if ( new_slope ==original_slope|| new_slope==-original_slope) {
		return true;
	}
	else { return false; }
}