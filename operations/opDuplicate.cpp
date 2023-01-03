#include "opDuplicate.h"
#include "..\shapes\Circle.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opDuplicate::opDuplicate(controller* pCont) :operation(pCont)
{}
opDuplicate::~opDuplicate()
{}

//Execute the operation
void opDuplicate::Execute()
{
	Graph* pGr = pControl->getGraph();
	pGr->setselectedshape();
	shape* clip = pGr->getselectedshape();
	pGr->AddToClipboard(clip);
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Shape added to clipboard!");
	
	if (clip)
	{
		shape* newShp = clip->duplicate(clip);
		pGr->Addshape(newShp);
	}
	pUI->PrintMessage("Shape pasted!");
}
