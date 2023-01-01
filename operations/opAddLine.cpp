#include "opAddLine.h"
#include "..\shapes\Line.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddLine::opAddLine(controller* pCont) :operation(pCont)
{}
opAddLine::~opAddLine()
{}

//Execute the operation
void opAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at first point");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Line parameters
	GfxInfo LineGfxInfo;

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LineGfxInfo.FillClr = pUI->getCrntFillColor();
	LineGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	LineGfxInfo.DrawClr_s = pUI->getCrntDrawColor_s();
	LineGfxInfo.FillClr_s = pUI->getCrntFillColor_s();


	LineGfxInfo.isFilled = false;	//default is not filled
	LineGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Line with the above parameters
	Line* R = new Line(P1, P2, LineGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}