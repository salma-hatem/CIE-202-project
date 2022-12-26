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
	shape* Shp = pGr->getselectedshape();
	if (Shp)
	{
		Shp->resize(2);
	}
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Resized!");
	Shp->SetSelected(false);
}
