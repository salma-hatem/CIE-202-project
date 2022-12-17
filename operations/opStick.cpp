#include "opStick.h"
#include "..\shapes\Rect.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"



opStick::opStick(controller* pCont) :operation(pCont)
{}
opStick::~opStick()
{}

//Execute the operation
void opStick::Execute()
{
	Point P1;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Select the figure you want");
	pUI->GetPointClicked(P1.x, P1.y);
	if (pGr->Getshape(P1.x, P1.y))
	{
		
		pGr->UnselectAll(); 							//unselect everything 
		pGr->Getshape(P1.x, P1.y)->SetSelected(true);		//make this shape is selected

	}
	else
	{
		pGr->UnselectAll();
		pUI->ClearStatusBar();
	}

}
