#include "Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
<<<<<<< HEAD
=======
	Saved = false;
>>>>>>> origin/salma
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a Line on the screen	
	pUI->DrawCircle(point1, point2, ShpGfxInfo);
}
<<<<<<< HEAD
bool Circle::point_included(int x, int y) {

	double radius = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
	double d = sqrt(pow(x - point1.x, 2) + pow(y - point2.y, 2));	 //distance formula for the circle
	if (d <= radius)
		return true;
	else
		return false;
}
=======

void Circle::Save(ofstream& outfile) {

	//GUI* pSr;
	//pSr->getCrntDrawColor();
	outfile << "Circle " << " Id (can't think of one)" << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << endl;
	//outfile << ShpGfxInfo.DrawClr.ucGreen << ShpGfxInfo.BorderWdth << endl;
	SetShapeSaved(true);
	SetAllSaved(ShapeSaved());
}

bool Circle::ShapeSaved() const {
	return Saved;
}

void Circle::SetShapeSaved(bool s) {
	Saved = s;
}
>>>>>>> origin/salma
