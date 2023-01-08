#include "opMove.h"
#include "..\controller.h"



opMove::opMove(controller* pCont) :operation(pCont)

{
	
}
opMove::~opMove() // 
{
	
}

//Execute the operation
void opMove::Execute()

{ 
	Point initial_COO;

	GUI* pGi = pControl->GetUI();
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	window* wptr = pGi->getwind();


	pGi->PrintMessage("select the shape you want to move");
	pGi->GetPointClicked(initial_COO.x, initial_COO.y);
	//if (pGi->buttoncoordinates()) {
	while (wptr->GetButtonState(LEFT_BUTTON, initial_COO.x, initial_COO.y) != BUTTON_DOWN) {
		if (initial_COO.y >= 50 && initial_COO.y < 650) {
			pGr->Move_graph( initial_COO);
			initial_COO.x = 0; initial_COO.y = 0;
			pGi->ClearStatusBar();
			pGi->ClearDrawArea();
			pGi->CreateSideToolBar();
			
			
		}
		
		
		pControl->UpdateInterface();
		Sleep(20);
		
	}

	//delete initial_COO;
}