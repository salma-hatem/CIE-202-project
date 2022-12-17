#include "opSelect.h"
#include "..\shapes\Rect.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opSelect::opSelect(controller* pCont) :operation(pCont)
{}
opSelect::~opSelect()
{}
//Execute the operation
void opSelect::Execute()
{
	Point P1;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Select Your Firgure");
	pUI->GetPointClicked(P1.x, P1.y);
	if (pGr->Getshape(P1.x, P1.y))
	{
		pUI->PrintMessage(pGr->Getshape(P1.x, P1.y)->shapeInfo());
		pGr->UnselectAll(); 							//unselect everything 
		pGr->Getshape(P1.x, P1.y)->SetSelected(true);		//make this shape is selected
	}
	else
	{
		pGr->UnselectAll();
		pUI->ClearStatusBar();
	}

}

