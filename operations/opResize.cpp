#include "opResize.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opResize::opResize(controller * pCont):operation(pCont)
{}
opResize::~opResize()
{} 

//Execute the operation
void opResize::Execute()
{
	
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Enter a factor (0.25 / 0.5 / 2 / 4): ");
	double factor = pUI->getFactor();
	shape* Shp = pGr->getselectedshape();
	if (Shp)
	{
		Shp->resize(factor);
	}
	
	pUI->PrintMessage("Resized!");
	Shp->SetSelected(false);
}
