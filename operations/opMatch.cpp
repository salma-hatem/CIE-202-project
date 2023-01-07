#include"opMatch.h"
#include"../controller.h"
#include"../GUI/GUI.h"

opMatch::opMatch(controller* pCont) :operation(pCont) {}

opMatch::~opMatch() {}

void opMatch::Execute()
{
	Point P1;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Select a shape");
	pUI->GetPointClicked(P1.x, P1.y);
	if (pGr->Getshape(P1.x, P1.y))
	{
		pUI->PrintMessage(pGr->Getshape(P1.x, P1.y)->shapeInfo());
		pGr->UnselectAll(); 							//unselect everything 
		pGr->Getshape(P1.x, P1.y)->SetSelected(true);		//make this shape is selected
		shape* shape1 = pGr->Getshape(P1.x, P1.y);
		pGr->addMatched(shape1);
	}
	else
	{
		pGr->UnselectAll();
		pUI->ClearStatusBar();
	}
	if (pGr->getmatched().size() == 2) {
		if (pGr->getmatched()[0]->shapename() == pGr->getmatched()[1]->shapename()) {
			pUI->PrintMessage("you got two matched shapes, congrats");
			pGr->DeleteMatched();
			pGr->clearMatched();
		}
	}
	else if (pGr->getmatched().size() != 1) {
		pGr->clearMatched();
	}
}
