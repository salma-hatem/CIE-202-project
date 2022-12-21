#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = P1;
	point2 = P2;
	Saved = false;
	type = "line";
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
string Line::shapeInfo()
{
	double length= sqrt(pow(point1.x-point2.x,2)+pow(point1.y - point2.y, 2));
	string text;


	text = "the length of the line is " + to_string(length);
	return text;
}