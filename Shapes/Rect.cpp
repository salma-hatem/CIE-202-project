#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
bool Rect::point_included(int x, int y) {

	if ((Corner1.x < Corner2.x && Corner1.y < Corner2.y) && (x > Corner1.x && x<Corner2.x && y>Corner1.y && y < Corner2.y)) {
		return true;
	}
	else if ((Corner1.x < Corner2.x && Corner1.y > Corner2.y) && (x > Corner1.x && x<Corner2.x && y>Corner2.y && y < Corner1.y)) {
		return true;
	}
	else if ((Corner1.x > Corner2.x && Corner1.y < Corner2.y) && (x > Corner2.x && x<Corner1.x && y>Corner1.y && y < Corner2.y))
		return true;
	else if ((Corner1.x > Corner2.x && Corner1.y > Corner2.y) && (x > Corner2.x && x<Corner1.x && y>Corner2.y && y < Corner1.y))
		return true;
	else
		return false;
}
string Rect::shapeInfo()
{
	int area;
	Point center;
	string text;

	area = abs(Corner2.x - Corner1.x) * abs(Corner2.y - Corner1.y);
	center.x = abs(Corner1.x - Corner2.x) / 2;
	center.y = abs(Corner1.y - Corner2.y) / 2;

	text = "Area of the recrangle is " + to_string(area) + " The center is at (" + to_string(center.x) + "," + to_string(center.y) + ")";
	return text;
}