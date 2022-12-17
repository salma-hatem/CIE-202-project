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
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawSquare(Corner1, Corner2, ShpGfxInfo);
}

void Square::Save(ofstream& outfile) {
	outfile << "SQU " << "ID " << Corner1.x - Corner2.x <<" " << Corner1.x << "  " << Corner1.y << " " << Corner2.x << " " << Corner2.y << endl;
	SetShapeSaved(true);
	SetAllSaved(true);

}

bool Square::ShapeSaved() const {
	return Saved;
}

void Square::SetShapeSaved(bool s) {
	Saved = s;
}