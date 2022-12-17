#include "Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a square on the screen	
	pUI->DrawSquare(Corner1, Corner2, ShpGfxInfo);
}
bool Square::point_included(int x, int y) {
	double length;
	
	length = sqrt(pow(x - Corner1.x, 2) + pow(y - Corner1.y, 2));
	if (x > Corner1.x && x<Corner1.x+length && y>Corner1.y && y < Corner1.y+length) 
		return true;

	else  
		return false;
}