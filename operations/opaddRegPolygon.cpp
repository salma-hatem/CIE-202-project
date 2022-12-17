//#include "opaddRegPolygon.h"
//#include "..\shapes\regpolygon.h"
//
//#include "..\controller.h"
//
//#include "..\GUI\GUI.h"
//
//opaddRegPolygon::opaddRegPolygon(controller* pCont) :operation(pCont)
//{}
//opaddRegPolygon::~opaddRegPolygon()
//{}
//
////Execute the operation
//void opaddRegPolygon::Execute()
//{
//	Point P1;
//	double numv, r;
//
//
//	//Get a Pointer to the Input / Output Interfaces
//	GUI* pUI = pControl->GetUI();
//
//	pUI->PrintMessage("New Square: Click at first point");
//	//Read 1st corner and store in point P1
//	pUI->GetPointClicked(P1.x, P1.y);
//
//	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
//	msg += " ... Click at second point";
//	pUI->PrintMessage(msg);
//	//Read 2nd corner and store in point P2
//	pUI->GetPointClicked(P2.x, P2.y);
//	pUI->ClearStatusBar();
//
//	//Preapre all rectangle parameters
//	GfxInfo SquareGfxInfo;
//
//	//get drawing, filling colors and pen width from the interface
//	SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
//	SquareGfxInfo.FillClr = pUI->getCrntFillColor();
//	SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();
//
//
//	SquareGfxInfo.isFilled = false;	//default is not filled
//	SquareGfxInfo.isSelected = false;	//defualt is not selected
//
//
//	//Create a Square with the above parameters
//	regpolygon* R = new regpolygon(P1,numv,r, regpolygonGfxInfo);
//
//	//Get a pointer to the graph
//	Graph* pGr = pControl->getGraph();
//
//	//Add the Square to the list of shapes
//	pGr->Addshape(R);
//
//}