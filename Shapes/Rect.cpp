#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Saved = false;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
void Rect::Save(ofstream& outfile) {
	outfile << "Rect " << "ID " << Corner1.x - Corner2.x<<" " << Corner1.x << "  " << Corner1.y << " " << Corner2.x << " " << Corner2.y << endl;
	SetShapeSaved(true);
	SetAllSaved(true);
}
bool Rect::ShapeSaved() const {
	return Saved;
}

void Rect::SetShapeSaved(bool s) {
	Saved = s;
}