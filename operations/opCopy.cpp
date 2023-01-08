#include "opCopy.h"
#include "..\shapes\Circle.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opCopy::opCopy(controller * pCont):operation(pCont)
{}
opCopy::~opCopy()
{} 

//Execute the operation
void opCopy::Execute()
{
	Graph* pGr = pControl->getGraph();
	pGr->setselectedshape();
	shape* clip = pGr->getselectedshape();
	pGr->clearClipBoard();
	pGr->AddToClipboard(clip);
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Shape added to clipboard!");
}
