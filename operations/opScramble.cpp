#include "opScramble.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opScramble::opScramble(controller * pCont):operation(pCont)
{}
opScramble::~opScramble()
{} 

//Execute the operation
void opScramble::Execute()
{
	
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pGr->scrambleGraph();
	pUI->PrintMessage("Graph scrambled");
}
