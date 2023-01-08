#include "Circle.h"
#include <math.h>

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	Saved = false;
	OG_point1 = P1;
	OG_point2 = P2;
}


Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pUI->DrawCircle(point1, point2, ShpGfxInfo);
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

	text = "Area of the circle is " + to_string(area) ;
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
//
//void Circle::Hide(GUI* pUI) {
//	double radius = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
//	pUI->getwind()->DrawImage("images\\MenuIcons\\card.jpg", point1.x+radius, point1.y+radius, (2*radius), (2*radius));
//
//}

void Circle::Hidding(GUI* pUI) {
	double radius = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
	Point newpoint1 ;
	newpoint1.x = point1.x - radius;
	newpoint1.y = point1.y - radius;
	
	//Call Output::DrawCircle to draw a circle on the screen	
	if (getcurrenthidden() == true) {

		// call the function that draw an image on the circle
		pUI->getwind()->DrawImage("images\\card.jpg", newpoint1.x, newpoint1.y, 2 * radius, 2 * radius);
	}
	else {
		pUI->DrawCircle(point1, point2, ShpGfxInfo);
	}
	
}
string Circle::shapename() {
	string name = "circle";
	return name;
}



void Circle::scrambleShape()
{
	int diffX = point2.x - point1.x;
	int diffY = point2.y - point1.y;
	point1 = randPoint();
	point2.x = point1.x + diffX;
	point2.y = point1.y + diffY;
}


void Circle::calculateWH()
{
	width = abs(2 * (point1.x - point2.x));
	height = width;
}

void Circle::scrambleShape(Point p,int col, int row)
{
	int diffX = point2.x - point1.x;
	int diffY = point2.y - point1.y;
	int x = col / 2; int y = row / 2;
	point1.x = x+p.x; point1.y = y+p.y;
	point2.x = point1.x + diffX;
	point2.y = point1.y + diffY;
}

double Circle::getfactor(int col, int row)
{
	double f1=1; 
	if(width > row) f1= double(row) / width;

	double f2=1; 
	if (height > col) f2 = double(col) / height;
	if (f1 < f2) return f1;
	else return f2;
}

void Circle::UnMove() {

	//pUI->DrawCircle(OG_point1, OG_point2, ShpGfxInfo);
	point1.x = OG_point1.x;
	point1.y = OG_point1.y;
	point2.x = OG_point2.x;
	point2.y = OG_point2.y;


}


void Circle::Save(ofstream& outfile) {

	string draw = ShpGfxInfo.DrawClr_s;
	string fill = ShpGfxInfo.FillClr_s;
	int pen_Width = ShpGfxInfo.BorderWdth;
	outfile << "Circle " << "ID" << " " << point1.x - point2.x << " " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << " ";
	outfile << draw << " " << fill << " " << pen_Width << endl;

	//outfile << "Circle " << " Id (can't think of one)" << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << endl;
	//outfile << ShpGfxInfo.DrawClr.ucGreen << ShpGfxInfo.BorderWdth << endl;
	SetShapeSaved(true);
	SetAllSaved(true);
}


void Circle::Move(int& x, int& y) {
	/* double c = radius;
	 point2.y = point1.y - c;
	 point2.x = sqrt(pow(c, 2) - pow(point2.y - y, 2)) + x;*/

	 //point1.x = x;
	 //point1.y = y;

	 ///
	int radius = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));

	int diff_x = x - point1.x;
	int diff_y = y - point1.y;

	point1.x = point1.x + diff_x;
	point1.y = point1.y + diff_y;
	point2.x = point1.x + radius;
	point2.y = point1.y;


}