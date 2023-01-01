#include "opRotate.h"
#include "..\shapes\Rect.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opRotate::opRotate(controller* pCont) :operation(pCont)
{}
opRotate::~opRotate()
{}
//Execute the operation
void opRotate::Execute()
{
	Point P1;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Select Your Firgure");
	pUI->GetPointClicked(P1.x, P1.y);
	if (pGr->Getshape(P1.x, P1.y))
	{
		pGr->Getshape(P1.x, P1.y)->Rotate(pUI);
		
	}
	else
	{
		pGr->UnselectAll();
		pUI->ClearStatusBar();
	}

}
