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
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	shape* s = pGr->getselectedshape();

	pGr->setallduplicated(s);

	pUI = nullptr;
	pGr = nullptr;
}
