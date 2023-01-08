#include"opMatch.h"
#include"../controller.h"
#include"../GUI/GUI.h"

opMatch::opMatch(controller* pCont) :operation(pCont) {}

opMatch::~opMatch() {}

void opMatch::Execute()
{
	static int score = 0;
	Point P1, P2;
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
		if (pGr->getmatched()[0]->shapeInfo() == pGr->getmatched()[1]->shapeInfo()) {
			pGr->Addscore();
			pUI->PrintMessage("well done, you got two matched shapes,   your score is " + to_string(pGr->getscore()));
			pGr->DeleteMatched();
			pGr->clearMatched();



		}
		else {
			pGr->clearMatched();
			pGr->Subtractscore();
			pUI->PrintMessage("try again, your score is " + to_string(pGr->getscore()));
			pGr->setshapeduphidded(P1.x, P1.y);
			pGr->setshapeduphidded(P2.x, P2.y);
			pUI->ClearDrawArea();
			pGr->Draw(pUI);
			Sleep(1000);
			pGr->setshapeshidden();
		}
	}
	if (pGr->shapeslist()) {
		pUI->PrintMessage("Winner Winner Chicken Dinner");

	}

	pUI = nullptr;
	pGr = nullptr;
}