#include "Circle.h"
#include <math.h>

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
	//string draw = ShpGfxInfo.DrawClr_s;
	//string fill=  ShpGfxInfo.FillClr_s;
	//int pen_Width= ShpGfxInfo.BorderWdth;
	outfile << "Circle " << "ID " << point1.x - point2.x << " " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y;
	//outfile << draw << " " << fill <<" "<< pen_Width << endl;
	

	
	//outfile << "Circle " << " Id (can't think of one)" << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << endl;
	//outfile << ShpGfxInfo.DrawClr.ucGreen << ShpGfxInfo.BorderWdth << endl;
	SetShapeSaved(true);
	SetAllSaved(true);
}

bool Circle::ShapeSaved() const {
	return Saved;
}

void Circle::SetShapeSaved(bool s) {
	Saved = s;
}

bool Circle::point_included(int x, int y) {

	double radius = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
	double d = sqrt(pow(x - point1.x, 2) + pow(y - point1.y, 2));	 //distance formula for the circle
	if (d <= radius)
		return true;
	else
		return false;
}

string Circle::shapeInfo()
{
	int area;
	Point center;
	string text;
	const double pi = 3.14;
	double radius = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
	
	area = pi * pow(radius, 2);
	center.x = abs(point1.x - point2.x) / 2;
	center.y = abs(point1.y - point2.y) / 2;

	text = "Area of the circle is " + to_string(area) + " The center is at (" + to_string(center.x) + "," + to_string(center.y) + ")";
	return text;
}


shape* Circle::duplicate(shape* ptr)
{
	Circle* PTR = (Circle*)ptr;
	Point p1, p2;
	p1 = pointshift(point1);
	p2 = pointshift(point2);
	shape* C = new Circle(p1, p2, ShpGfxInfo);
	C->SetSelected(false);
	C->SetAllSaved(false);
	SetSelected(false);
	return C;
}

void Circle::resize(double factor)
{
	int diffX = point1.x - point2.x;
	int diffY = point1.y - point2.y;
	point2.x = point1.x + diffX * factor;
	point2.y = point1.y + diffY * factor;
}

void Circle::Rotate(GUI* pUI) {
	
	//Call Output::Draw the same circle because the rotation will change nothing in it
	pUI->DrawCircle(point1, point2, ShpGfxInfo);

}

void Circle::scrambleShape()
{
	int diffX = point2.x - point1.x;
	int diffY = point2.y - point1.y;
	point1 = randPoint();
	point2.x = point1.x + diffX;
	point2.y = point1.y + diffY;
}