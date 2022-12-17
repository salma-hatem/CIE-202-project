#include "Triangle.h"

Triangle::Triangle(Point P1, Point P2,Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
	Saved = false;
}

Triangle::~Triangle()
{}


void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Triangle on the screen	
	pUI->DrawTriangle(point1, point2, point3, ShpGfxInfo);
}
double Triangle::trianglearea(int x1, int x2, int x3, int y1, int y2, int y3) {
	double triangle_area = abs(x1 * (y2 - y3) - y1 * (x2 - x3) + ((x2 * y3) - (y2 * x3))) / 2;
	return triangle_area;
}

void Triangle::Save(ofstream& outfile) {
	//char info[100];
	outfile << "TRI " << "ID " << point1.x - point1.x << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << " " << point3.x << " " << point3.y << endl;
	SetShapeSaved(true);
	SetAllSaved(true);
}

bool Triangle::point_included(int x, int y) {
	double triangle_area = trianglearea(point1.x, point2.x, point3.x, point1.y, point2.y, point3.y);
	double area1, area2, area3;
	area1 = trianglearea(x, point2.x, point3.x, y, point2.y,point3.y);
	area2 = trianglearea(point1.x, x, point3.x, point1.y, y, point3.y);
	area3 = trianglearea(point1.x, point2.x, x, point1.y, point2.y, y);

	if (triangle_area == area1 + area2 + area3) 
		return true;
	
	else
		return false;
}
bool Triangle::ShapeSaved() const {
	return Saved;
}
	
}
string Triangle::shapeInfo()
{
	string text;
	double triangle_area = trianglearea(point1.x, point2.x, point3.x, point1.y, point2.y, point3.y);
	
	text = "Area of the recrangle is " + to_string(triangle_area);
	return text;
}
void Triangle::SetShapeSaved(bool s) {
	Saved = s;
}