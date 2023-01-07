#include"opHide.h"
#include"../controller.h"
#include"../GUI/GUI.h"

opHide::opHide(controller* pCont) :operation(pCont) {}

opHide::~opHide() {}

void opHide::Execute()
{
	Point P1;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("all shapes have been hidden");
	pGr->setshapeshidden();
}
