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
	string draw = ShpGfxInfo.DrawClr_s;
	string fill = ShpGfxInfo.FillClr_s;
	int pen_Width = ShpGfxInfo.BorderWdth;
	outfile << "SQU " << "ID " << Corner1.x - Corner2.x << " " << Corner1.x << "  " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

	outfile << draw << " " << fill << " " << pen_Width << endl;

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
string Square::shapeInfo()
{
	int area;
	Point center;
	string text;

	area = abs(Corner2.x - Corner1.x) * abs(Corner2.y - Corner1.y);
	center.x = abs(Corner1.x - Corner2.x) / 2;
	center.y = abs(Corner1.y - Corner2.y) / 2;

	text = "Area of the square is " + to_string(area) + " The center is at (" + to_string(center.x) + "," + to_string(center.y) + ")";
	return text;
}
void Square::SetShapeSaved(bool s) {
	Saved = s;
}



shape* Square::duplicate(shape* ptr)
{
	Square* PTR = (Square*)ptr;
	Point p1, p2;
	p1 = pointshift(Corner1);
	p2 = pointshift(Corner2);
	shape* C = new Square(p1, p2, ShpGfxInfo);
	C->SetSelected(false);
	C->SetAllSaved(false);
	SetSelected(false);
	return C;
}


void Square::resize(double factor)
{
	int diffX = Corner1.x - Corner2.x;
	int diffY = Corner1.y - Corner2.y;
	Corner2.x = Corner1.x - diffX * factor;
	Corner2.y = Corner1.y - diffY * factor;
}

void Square::Rotate(GUI* pUI) {
	// it will change nothing in the square 
	pUI->DrawSquare(Corner1, Corner2, ShpGfxInfo);

}


void Square::scrambleShape()
{
	int diffX = Corner2.x - Corner1.x;
	int diffY = Corner2.y - Corner1.y;
	Corner1 = randPoint();
	Corner2.x = Corner1.x + diffX;
	Corner2.y = Corner1.y + diffY;
}



void Square::calculateWH()
{
	width = abs(Corner1.x - Corner2.x);
	height = width;
}

void Square::scrambleShape(Point p, int col, int row)
{
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

		(*pmin).x = row - 5 + p.x; (*pmin).y = row - 5 + p.y;
		(*pmax).x = (*pmin).x + diffX;
		(*pmax).y = (*pmin).y + diffY;
	}
}

double Square::getfactor(int col, int row)
{
	double f1 = 1;
	if (width > row) f1 = double(row) / width;

	double f2 = 1;
	if (height > col) f2 = double(col) / height;
	if (f1 < f2) return f1;
	else return f2;
}