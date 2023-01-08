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

	string draw = ShpGfxInfo.DrawClr_s;
	string fill = ShpGfxInfo.FillClr_s;
	int pen_Width = ShpGfxInfo.BorderWdth;
	outfile << "TRI " << "ID" << " " << point1.x - point2.x << " " << point1.x << " " << point1.y << " " << point2.x << " " << point2.y << " " << point3.x << " " << point3.y << " ";

	outfile << draw << " " << fill << " " << pen_Width << endl;

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
	
string Triangle::shapeInfo()
{
	string text;
	double triangle_area = trianglearea(point1.x, point2.x, point3.x, point1.y, point2.y, point3.y);
	
	text = "Area of the Triangle is " + to_string(triangle_area);
	return text;
}
void Triangle::SetShapeSaved(bool s) {
	Saved = s;
}


shape* Triangle::duplicate(shape* ptr)
{
	Triangle* PTR = (Triangle*)ptr;
	Point p1, p2,p3;
	p1 = pointshift(point1);
	p2 = pointshift(point2);
	p3 = pointshift(point3);
	shape* C = new Triangle(p1, p2, p3 , ShpGfxInfo);
	C->SetSelected(false);
	C->SetAllSaved(false);
	SetSelected(false);
	return C;
}


void Triangle::resize(double factor)
{
	int diffX1 = point1.x - point2.x;
	int diffY1 = point1.y - point2.y;
	point2.x = point1.x - diffX1 * factor;
	point2.y = point1.y - diffY1 * factor;
	int diffX2 = point1.x - point3.x;
	int diffY2 = point1.y - point3.y;
	point3.x = point1.x - diffX2 * factor;
	point3.y = point1.y - diffY2 * factor;
}

void Triangle::Rotate(GUI* pUI) {
	Point c;
	c.x = (point1.x + point2.x+ point3.x) / 3;
	c.y = (point1.y + point2.y+ point3.y) / 3;
	double sparx1 = point1.x;
	double sparx2 = point2.x;
	double spary1 = point1.y;
	double spary2 = point2.y;
	double sparx3 = point3.x;
	double spary3 = point3.y;

	point1.x = -spary1 + c.y + c.x;
	point1.y = sparx1 - c.x + c.y;
	point2.x = -spary2 + c.y + c.x;
	point2.y = sparx2 - c.x + c.y;
	point3.x = -spary3 + c.y + c.x;
	point3.y = sparx3 - c.x + c.y;

	pUI->DrawTriangle(point1, point2,point3, ShpGfxInfo);
}

void Triangle::scrambleShape()
{
	int diffX1 = point2.x - point1.x;
	int diffY1 = point2.y - point1.y;

	int diffX2 = point3.x - point1.x;
	int diffY2 = point3.y - point1.y;

	point1 = randPoint();
	point2.x = point1.x + diffX1;
	point2.y = point1.y + diffY1;

	point3.x = point1.x + diffX2;
	point3.y = point1.y + diffY2;

}


void Triangle::calculateWH()
{
	Point* pminX; Point* pminY;
	Point* pmaxX; Point* pmaxY;
	if (point1.x < point2.x && point1.x < point3.x)
	{
		pminX = &point1;
		if (point2.x < point3.x) pmaxX = &point3;
		else pmaxX = &point2;
	}
	else if (point2.x < point3.x)
	{
		 pminX = &point2;
		 if (point1.x < point3.x) pmaxX = &point3;
		 else pmaxX = &point1;
	}
	else 
	{ 
		pminX = &point3;
		if (point1.x < point2.x) pmaxX = &point2;
		else pmaxX = &point1;
	}
	

	if (point1.y < point2.y && point1.y < point3.y)
	{
		pminY = &point1;
		if (point2.y < point3.y) pmaxY = &point3;
		else pmaxY = &point2;
	}
	else if (point2.y < point3.y)
	{
		pminY = &point2;
		if (point1.y < point3.y) pmaxY = &point3;
		else pmaxY = &point1;
	}
	else
	{
		pminY = &point3;
		if (point1.y < point2.y) pmaxY = &point2;
		else pmaxY = &point1;
	}

	width = abs((*pmaxX).x - (*pminX).x);
	height = abs((*pmaxY).y - (*pminY).y);
}

void Triangle::scrambleShape(Point p, int col, int row)
{
	Point* pminX; Point* pminY;
	Point* pmaxX; Point* pmaxY;
	if (point1.x < point2.x && point1.x < point3.x)
	{
		pminX = &point1;
		if (point2.x < point3.x) pmaxX = &point3;
		else pmaxX = &point2;
	}
	else if (point2.x < point3.x)
	{
		pminX = &point2;
		if (point1.x < point3.x) pmaxX = &point3;
		else pmaxX = &point1;
	}
	else
	{
		pminX = &point3;
		if (point1.x < point2.x) pmaxX = &point2;
		else pmaxX = &point1;
	}


	if (point1.y < point2.y && point1.y < point3.y)
	{
		pminY = &point1;
		if (point2.y < point3.y) pmaxY = &point3;
		else pmaxY = &point2;
	}
	else if (point2.y < point3.y)
	{
		pminY = &point2;
		if (point1.y < point3.y) pmaxY = &point3;
		else pmaxY = &point1;
	}
	else
	{
		pminY = &point3;
		if (point1.y < point2.y) pmaxY = &point2;
		else pmaxY = &point1;
	}
	int w = (*pmaxX).x - (*pminX).x;
	int h = (*pmaxY).y - (*pminY).y;
	int cx = (*pmaxX).x - w / 2;
	int cy = (*pmaxY).y - h / 2;

	int diffX1 = point1.x - cx; int diffY1 = point1.y - cy;
	int diffX2 = point2.x - cx; int diffY2 = point2.y - cy;
	int diffX3 = point3.x - cx; int diffY3 = point3.y - cy;

	int cardcx = p.x + col / 2;
	int cardcy = p.y + row / 2;
	cx = cardcx; cy = cardcy;
	point1.x = cx + diffX1; point1.y = cy + diffY1;
	point2.x = cx + diffX2; point2.y = cy + diffY2;
	point3.x = cx + diffX3; point3.y = cy + diffY3;
}

double Triangle::getfactor(int col, int row)
{
	double f1 = 1;
	if (width > row) f1 = double(row) / width;

	double f2 = 1;
	if (height > col) f2 = double(col) / height;
	if (f1 < f2) return f1;
	else return f2;
}
void Triangle::Hidding(GUI* pUI) {

	Point newpoint;
	// if statments to calculate the starting point of the image
	if (point1.x < point2.x && point1.x< point3.x){
		newpoint.x = point1.x;
	}
	else if (point2.x < point1.x && point2.x < point3.x) {
		newpoint.x = point2.x;
	}
	else if (point3.x < point2.x && point3.x < point1.x) {
		newpoint.x = point3.x;
	}
	if (point1.y < point2.y && point1.y < point3.y) {
		newpoint.y = point1.y;
	}
	else if (point2.y < point1.y && point2.y < point3.y) {
		newpoint.y = point2.y;
	}
	else if (point3.y < point2.y && point3.y < point1.y) {
		newpoint.y = point3.y;
	}

	// if statements to calculate the height and width of the image
	static double width=0, height=0;
	if (abs(point1.x - point2.x) > abs(point1.x - point3.x) && abs(point1.x - point2.x) > abs(point2.x - point3.x))
		width = abs(point1.x - point2.x);
	else if (abs(point2.x - point3.x) > abs(point1.x - point3.x) && abs(point2.x - point3.x) > abs(point1.x - point2.x))
		width = abs(point2.x - point3.x);
	else if (abs(point1.x - point3.x) > abs(point1.x - point2.x) && abs(point1.x - point3.x) > abs(point2.x - point3.x))
		width = abs(point1.x - point3.x);

	if (abs(point1.y - point2.y) > abs(point1.y - point3.y) && abs(point1.y - point2.y) > abs(point2.y - point3.y))
		height = abs(point1.y - point2.y);
	else if (abs(point2.y - point3.y) > abs(point1.y - point3.y) && abs(point2.y - point3.y) > abs(point1.y - point2.y))
		height = abs(point2.y - point3.y);
	else if (abs(point1.y - point3.y) > abs(point1.y - point2.y) && abs(point1.y - point3.y) > abs(point2.y - point3.y))
		height = abs(point1.y - point3.y);


	if (getcurrenthidden() == true) {

		// call the function that draw an image on the circle
		pUI->getwind()->DrawImage("images\\card.jpg", newpoint.x, newpoint.y, width, height);
	}
	else {
		pUI->DrawTriangle(point1, point2,point3, ShpGfxInfo);
	}

}
string Triangle::shapename() {
	string name = "triangle";
	return name;
}

void Triangle::Move(int& x, int& y) {

	int change_x, change_y;
	change_x = x - point1.x;
	change_y = y - point1.y;

	point1.x = point1.x + change_x;
	point1.y = point1.y + change_y;

	point2.x = point2.x + change_x;
	point2.y = point2.y + change_y;

	point3.x = point3.x + change_x;
	point3.y = point3.y + change_y;
}
void Triangle::UnMove() {

	//pUI->DrawCircle(OG_point1, OG_point2, ShpGfxInfo);
	point1.x = OG_point1.x;
	point1.y = OG_point1.y;
	point2.x = OG_point2.x;
	point2.y = OG_point2.y;
	point3.x = OG_point3.x;
	point3.y = OG_point3.y;


}