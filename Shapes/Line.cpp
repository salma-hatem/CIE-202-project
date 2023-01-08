#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	Saved = false;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(point1, point2, ShpGfxInfo);
}

void Line::Save(ofstream& outfile) {

	string draw = ShpGfxInfo.DrawClr_s;
	string fill = ShpGfxInfo.FillClr_s;
	int pen_Width = ShpGfxInfo.BorderWdth;
	
	outfile << "Line " << "ID " << point1.x - point2.x << " " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y;
	outfile << draw << " " << "No-Fill" << " " << pen_Width << endl;

	SetShapeSaved(true);
	SetAllSaved(true);
}



void Line::SetShapeSaved(bool s)
{
	Saved = s;
}

bool Line::point_included(int x, int y) {
	double original_slope = (point2.y - point1.y) / (point2.x - point1.x);
	double new_slope = (y - point1.y) / (x - point1.x);
	if (new_slope == original_slope || new_slope == -original_slope) {
		return true;
	}
	else { return false; }
}
 
void Line::Rotate(GUI* pUI) {
	Point c;
	c.x = (point1.x + point2.x) / 2;
	c.y = (point1.y + point2.y) / 2;
	double sparx1 = point1.x;
	double sparx2 = point2.x;
	double spary1 = point1.y;
	double spary2 = point2.y;
	
	point1.x = -spary1 + c.y + c.x;
	point1.y = sparx1 - c.x + c.y;
	point2.x = -spary2 + c.y + c.x;
	point2.y = sparx2 - c.x + c.y;

	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(point1, point2, ShpGfxInfo);
}
string Line::shapeInfo()
{
	double length= sqrt(pow(point1.x-point2.x,2)+pow(point1.y - point2.y, 2));
	string text;


	text = "the length of the line is " + to_string(length);
	return text;
}

shape* Line::duplicate(shape* ptr)
{
	Line* PTR = (Line*)ptr;
	Point p1, p2;
	p1 = pointshift(point1);
	p2 = pointshift(point2);
	Line* C = new Line(p1, p2, ShpGfxInfo);
	C->SetSelected(false);
	C->SetAllSaved(false);
	SetSelected(false);
	return C;
}

void Line::resize(double factor)
{
	int diffX = point1.x - point2.x;
	int diffY = point1.y - point2.y;
	point2.x = point1.x + -diffX * factor;
	point2.y = point1.y + -diffY * factor;
}

<<<<<<< HEAD
void Line::Hidding(GUI* pUI) {
	Point newpoint;
	if (point1.x > point2.x) {
		newpoint.x = point2.x;
	}
	else {
		newpoint.x = point1.x;
	}
	if (point1.y > point2.y) {
		newpoint.y = point2.y;
	}
	else {
		newpoint.y = point1.y;
	}
	if (gethidden()== true) {
		

		pUI->getwind()->DrawImage("images\\MenuIcons\\card.jpg",newpoint.x, newpoint.y, abs(point1.x - point2.x), abs(point1.y - point2.y));
	}
	else{}
}
string Line::shapename() {
	string name = "line";
	return name;
=======
void Line::scrambleShape()
{
	int diffX = point2.x - point1.x;
	int diffY = point2.y - point1.y;
	point1 = randPoint();
	point2.x = point1.x + diffX;
	point2.y = point1.y + diffY;
}



void Line::calculateWH()
{
	width = abs(point1.x - point2.x);
	height = abs(point1.y - point2.y);
}

void Line::scrambleShape(Point p, int col, int row)
{
	/*
	int diffX = point2.x - point1.x;
	int diffY = point2.y - point1.y;
	if (point2.x > point1.x && point2.y > point1.y)
	{
		
		point1.x = 5 + p.x; point1.y = 5 + p.y;
		point2.x = point1.x + diffX;
		point2.y = point1.y + diffY;
	}
	else if(point2.x < point1.x && point2.y < point1.y)
	{
		int diffX = point1.x - point2.x;
		int diffY = point1.y - point2.y;
		point2.x = 5 + p.x; point2.y = 5 + p.y;
		point1.x = point2.x + diffX;
		point1.y = point2.y + diffY;
	}*/
	Point* pminX; Point* pminY;
	Point* pmaxX; Point* pmaxY;
	if (point1.x < point2.x)
	{
		pminX = &point1;
		pmaxX = &point2;
	}
	else
	{
		pminX = &point2;
		pmaxX = &point1;
	}

	if (point1.y < point2.y)
	{
		pminY = &point1;
		pmaxY = &point2;
	}
	else
	{
		pminY = &point2;
		pmaxY = &point1;
	}

	int w = (*pmaxX).x - (*pminX).x;
	int h = (*pmaxY).y - (*pminY).y;
	int cx = (*pmaxX).x - w / 2;
	int cy = (*pmaxY).y - h / 2;

	int diffX1 = point1.x - cx; int diffY1 = point1.y - cy;
	int diffX2 = point2.x - cx; int diffY2 = point2.y - cy;

	int cardcx = p.x + col / 2;
	int cardcy = p.y + row / 2;
	cx = cardcx; cy = cardcy;
	point1.x = cx + diffX1; point1.y = cy + diffY1;
	point2.x = cx + diffX2; point2.y = cy + diffY2;
}

double Line::getfactor(int col, int row)
{
	double f1 = 1;
	if (width > row) f1 = double(row) / width;

	double f2 = 1;
	if (height > col) f2 = double(col) / height;
	if (f1 < f2) return f1;
	else return f2;
>>>>>>> origin/salma
}