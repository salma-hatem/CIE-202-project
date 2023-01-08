#include "shape.h"
#include <time.h>

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


Point shape::randPoint()
{
	srand(time(0));
	int randNumX[100];
	for (int i = 0; i < 100;i++) randNumX[i] = rand() % 900 + 150;
	int randNumY[100];
	for (int i = 0; i < 100;i++) randNumY[i] = rand() % 300 + 150;
	static int c=0;
	int xrand = randNumX[c];
	int yrand = randNumY[c];
	Point p;
	p.x = xrand; p.y = yrand;
	c++;
	return p;
}
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