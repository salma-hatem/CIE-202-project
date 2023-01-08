#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{  
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	AllSaved = false;
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected;}

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

bool shape::IsAllSaved() const {
	return AllSaved;
}

void shape::InitializeAllSaved() {
	AllSaved = true;

}

void shape::SetAllSaved(bool s) {

	AllSaved = s;

}

Point shape::pointshift(Point p)
{
	p.x += 20;p.y += 20;
	return p;
}

void shape::currenthidden(bool t) {
		ShpGfxInfo.isHidden = t;
}
bool shape::getcurrenthidden() {
	return ShpGfxInfo.isHidden;
}
void shape::prevhidden(bool t) {
	ShpGfxInfo.isunhidden = t;
}
bool shape::getprevhidden() {
	return ShpGfxInfo.isunhidden;
}