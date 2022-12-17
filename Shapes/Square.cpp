#include "Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Saved = false;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a square on the screen	
	pUI->DrawSquare(Corner1, Corner2, ShpGfxInfo);
}

void Square::Save(ofstream& outfile) {
	outfile << "SQU " << " id " << Corner1.x << "  " << Corner1.y << " " << Corner2.x << " " << Corner2.y << endl;
	SetShapeSaved(true);
	SetAllSaved(true);

}


bool Square::ShapeSaved() const {
	return Saved;
}

bool Square::point_included(int x, int y) {
	double length;
	length = sqrt(pow(Corner2.x - Corner1.x, 2) + pow(Corner2.y - Corner1.y, 2));
	if (x > Corner1.x && x<Corner1.x + length && y>Corner1.y && y < Corner1.y + length)
		return true;

	else
		return false;
}
void Square::SetShapeSaved(bool s) {
	Saved = s;
}