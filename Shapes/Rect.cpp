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
	string draw = ShpGfxInfo.DrawClr_s;
	string fill = ShpGfxInfo.FillClr_s;
	int pen_Width = ShpGfxInfo.BorderWdth;

	outfile << "Rect " << "ID " << Corner1.x - Corner2.x << " " << Corner1.x << "  " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	outfile << draw << " " << fill << " " << pen_Width << endl;

	SetShapeSaved(true);
	SetAllSaved(true);
}
bool Rect::ShapeSaved() const {
	return Saved;
}

void Rect::SetShapeSaved(bool s) {
	Saved = s;
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

	text = "Area of the recrangle is " + to_string(area);
	return text;
}

shape* Rect::duplicate(shape* ptr)
{
	Rect* PTR = (Rect*)ptr;
	Point p1, p2;
	p1 = pointshift(Corner1);
	p2 = pointshift(Corner2);
	Rect* C = new Rect(p1, p2, ShpGfxInfo);
	C->SetSelected(false);
	C->SetAllSaved(false);
	SetSelected(false);
	return C;
}


void Rect::resize(double factor)
{
	int diffX = Corner1.x - Corner2.x;
	int diffY = Corner1.y - Corner2.y;
	Corner2.x = Corner1.x + -diffX * factor;
	Corner2.y = Corner1.y + -diffY * factor;
}

void Rect::Rotate(GUI* pUI) {
	Point c;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y = (Corner1.y + Corner2.y) / 2;
	double sparx1 = Corner1.x;
	double sparx2 = Corner2.x;
	double spary1 = Corner1.y;
	double spary2 = Corner2.y;

	Corner1.x = -spary1 + c.y + c.x;
	Corner1.y = sparx1 - c.x + c.y;
	Corner2.x = -spary2 + c.y + c.x;
	Corner2.y = sparx2 - c.x + c.y;
		
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);

}
<<<<<<< HEAD
<<<<<<< HEAD
=======

void Rect::scrambleShape()
{
	int diffX = Corner2.x - Corner1.x;
	int diffY = Corner2.y - Corner1.y;
	Corner1 = randPoint();
	Corner2.x = Corner1.x + diffX;
	Corner2.y = Corner1.y + diffY;
}




void Rect::calculateWH()
{
	width = abs(Corner1.x - Corner2.x);
	height = width;
}

void Rect::scrambleShape(Point p, int col, int row)
{
	/*
	Point* pmin;
	Point* pmax;
	if (Corner1.x < Corner2.x)
	{
		pmin = &Corner1;
		pmax = &Corner2;
	}
	else
	{
		pmin = &Corner2;
		pmax = &Corner1;
	}
	if (Corner1.y < Corner2.y)
	{
		int diffX = (*pmax).x - (*pmin).x;
		int diffY = (*pmax).y - (*pmin).y;

		(*pmin).x = 5 + p.x; (*pmin).y = 5 + p.y;
		(*pmax).x = (*pmin).x + diffX;
		(*pmax).y = (*pmin).y + diffY;
	}
	else
	{
		int diffX = -(*pmax).x + (*pmin).x;
		int diffY = (*pmax).y - (*pmin).y;

		(*pmin).x = row-5 + p.x; (*pmin).y = row - 5 + p.y;
		(*pmax).x = (*pmin).x + diffX;
		(*pmax).y = (*pmin).y + diffY;
	}*/
	Point* pminX; Point* pminY;
	Point* pmaxX; Point* pmaxY;
	if (Corner1.x < Corner2.x)
	{
		pminX = &Corner1;
		pmaxX = &Corner2;
	}
	else
	{
		pminX = &Corner2;
		pmaxX = &Corner1;
	}

	if (Corner1.y < Corner2.y)
	{
		pminY = &Corner1;
		pmaxY = &Corner2;
	}
	else
	{
		pminY = &Corner2;
		pmaxY = &Corner1;
	}

	int w = (*pmaxX).x - (*pminX).x;
	int h = (*pmaxY).y - (*pminY).y;
	int cx = (*pmaxX).x - w / 2;
	int cy = (*pmaxY).y - h / 2;

	int diffX1 = Corner1.x - cx; int diffY1 = Corner1.y - cy;
	int diffX2 = Corner2.x - cx; int diffY2 = Corner2.y - cy;

	int cardcx = p.x + col / 2;
	int cardcy = p.y + row / 2;
	cx = cardcx; cy = cardcy;
	Corner1.x = cx + diffX1; Corner1.y = cy + diffY1;
	Corner2.x = cx + diffX2; Corner2.y = cy + diffY2;
}

double Rect::getfactor(int col, int row)
{
	double f1 = 1;
	if (width > row) f1 = double(row) / width;

	double f2 = 1;
	if (height > col) f2 = double(col) / height;
	if (f1 < f2) return f1;
	else return f2;
}

>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
void Rect::Hidding(GUI* pUI)  {
	Point newpoint;
	if (Corner1.x > Corner2.x) {
		newpoint.x = Corner2.x;
	}
	else {
		newpoint.x = Corner1.x;
	}
	if (Corner1.y > Corner2.y) {
		newpoint.y = Corner2.y;
	}
	else {
		newpoint.y = Corner1.y;
	}
	double width, height;
	width = abs(Corner1.x - Corner2.x);
	height = abs(Corner1.y - Corner2.y);
	if (getcurrenthidden() == true) {

		// call the function that draw an image on the circle
		pUI->getwind()->DrawImage("images\\MenuIcons\\card.jpg", newpoint.x,newpoint.y, width, height);
	}
	else {
		pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
	}
}
string Rect::shapename() {
	string name = "rect";
	return name;
=======

void Rect::scrambleShape()
{
	int diffX = Corner2.x - Corner1.x;
	int diffY = Corner2.y - Corner1.y;
	Corner1 = randPoint();
	Corner2.x = Corner1.x + diffX;
	Corner2.y = Corner1.y + diffY;
}




void Rect::calculateWH()
{
	width = abs(Corner1.x - Corner2.x);
	height = width;
}

void Rect::scrambleShape(Point p, int col, int row)
{
	/*
	Point* pmin;
	Point* pmax;
	if (Corner1.x < Corner2.x)
	{
		pmin = &Corner1;
		pmax = &Corner2;
	}
	else
	{
		pmin = &Corner2;
		pmax = &Corner1;
	}
	if (Corner1.y < Corner2.y)
	{
		int diffX = (*pmax).x - (*pmin).x;
		int diffY = (*pmax).y - (*pmin).y;

		(*pmin).x = 5 + p.x; (*pmin).y = 5 + p.y;
		(*pmax).x = (*pmin).x + diffX;
		(*pmax).y = (*pmin).y + diffY;
	}
	else
	{
		int diffX = -(*pmax).x + (*pmin).x;
		int diffY = (*pmax).y - (*pmin).y;

		(*pmin).x = row-5 + p.x; (*pmin).y = row - 5 + p.y;
		(*pmax).x = (*pmin).x + diffX;
		(*pmax).y = (*pmin).y + diffY;
	}*/
	Point* pminX; Point* pminY;
	Point* pmaxX; Point* pmaxY;
	if (Corner1.x < Corner2.x)
	{
		pminX = &Corner1;
		pmaxX = &Corner2;
	}
	else
	{
		pminX = &Corner2;
		pmaxX = &Corner1;
	}

	if (Corner1.y < Corner2.y)
	{
		pminY = &Corner1;
		pmaxY = &Corner2;
	}
	else
	{
		pminY = &Corner2;
		pmaxY = &Corner1;
	}

	int w = (*pmaxX).x - (*pminX).x;
	int h = (*pmaxY).y - (*pminY).y;
	int cx = (*pmaxX).x - w / 2;
	int cy = (*pmaxY).y - h / 2;

	int diffX1 = Corner1.x - cx; int diffY1 = Corner1.y - cy;
	int diffX2 = Corner2.x - cx; int diffY2 = Corner2.y - cy;

	int cardcx = p.x + col / 2;
	int cardcy = p.y + row / 2;
	cx = cardcx; cy = cardcy;
	Corner1.x = cx + diffX1; Corner1.y = cy + diffY1;
	Corner2.x = cx + diffX2; Corner2.y = cy + diffY2;
}

double Rect::getfactor(int col, int row)
{
	double f1 = 1;
	if (width > row) f1 = double(row) / width;

	double f2 = 1;
	if (height > col) f2 = double(col) / height;
	if (f1 < f2) return f1;
	else return f2;
>>>>>>> origin/salma
}