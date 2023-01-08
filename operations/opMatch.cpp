#include"opMatch.h"
#include"../controller.h"
#include"../GUI/GUI.h"

opMatch::opMatch(controller* pCont) :operation(pCont) {}

opMatch::~opMatch() {}

void opMatch::Execute()
{
	static int score=0;
	Point P1,P2;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Select a shape");
	pUI->GetPointClicked(P1.x, P1.y);
	if (pGr->Getshape(P1.x, P1.y))
	{
		pUI->PrintMessage(pGr->Getshape(P1.x, P1.y)->shapeInfo());
		pGr->UnselectAll(); 							//unselect everything 
		shape* shape1 = pGr->Getshape(P1.x, P1.y);
		pGr->addMatched(shape1);
	}
	else
	{
		pGr->UnselectAll();
		pUI->ClearStatusBar();
	}
	pUI->GetPointClicked(P2.x, P2.y);
	if (pGr->Getshape(P2.x, P2.y))
	{
		pUI->PrintMessage(pGr->Getshape(P2.x, P2.y)->shapeInfo());
		pGr->UnselectAll(); 							//unselect everything 
		shape* shape1 = pGr->Getshape(P2.x, P2.y);
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
			pGr->Addscore();
			//pUI->PrintMessage(to_string(pGr->getscore()));
		}
	}
	else if (pGr->getmatched().size() != 1) {
		pGr->clearMatched();
	}
	
}
