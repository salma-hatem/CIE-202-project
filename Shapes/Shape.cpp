#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	AllSaved = false;
}

void shape::SetSelected(bool s)
<<<<<<< HEAD
{
	ShpGfxInfo.isSelected = s;
}

bool shape::IsSelected() const
{
	return ShpGfxInfo.isSelected;
}

void shape::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}

void shape::ChngFillClr(color Fclr)
{
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr;
=======
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected;}

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
>>>>>>> origin/salma
}

bool shape::IsAllSaved() const {
	return AllSaved;
}

void shape::InitializeAllSaved() {
	AllSaved = true;

}
void shape::SetAllSaved(bool s) {

	AllSaved = AllSaved && s;

}