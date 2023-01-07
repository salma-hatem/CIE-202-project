#include"opUnHide.h"
#include"../controller.h"
#include"../GUI/GUI.h"
#include<windows.h>


opUnHide::opUnHide(controller* pCont) :operation(pCont) {}

opUnHide::~opUnHide() {}

void opUnHide::Execute() {
	Point P1;
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->GetPointClicked(P1.x, P1.y);
	pGr->setshapeduphidded(P1.x, P1.y);
	
}

