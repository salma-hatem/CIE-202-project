#include "opChngDrawClr.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChngDrawClr::opChngDrawClr(controller * pCont):operation(pCont)
{}
opChngDrawClr::~opChngDrawClr()
{} 

//Execute the operation
void opChngDrawClr::Execute()
{
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	//pUI->PrintMessage("New Rectangle: Click at first corner");
	//Read 1st corner and store in point P1

	//string msg = "First corner is at  (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	//msg += " ... Click at second corner";
	//pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2

	//pUI->ClearStatusBar();


	//Get a pointer to the graph
	//Add the rectangle to the list of shapes
	pUI->changePenColor(RED);

}
