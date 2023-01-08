#include "opStart.h"
#include "..\shapes\Rect.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opStart::opStart(controller* pCont) :operation(pCont)
{}
opStart::~opStart()
{}
//Execute the operation
void opStart::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->setshapeshidden();

}




