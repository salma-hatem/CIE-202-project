#include "Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	Saved = false;

}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a Line on the screen	
	pUI->DrawCircle(point1, point2, ShpGfxInfo);
}

void Circle::Save(ofstream& outfile) {
	
	//GUI* pSr;
	//pSr->getCrntDrawColor();
	outfile << "Circle " << "ID " <<point1.x-point1.x << " " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << endl;
	

	SetShapeSaved(true);
	SetAllSaved(ShapeSaved());
}

bool Circle::ShapeSaved() const {
	return Saved;
}

void Circle::SetShapeSaved(bool s) {
	Saved = s;
}