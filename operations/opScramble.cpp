#include "opScramble.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

<<<<<<< HEAD
opScramble::opScramble(controller * pCont):operation(pCont)
{}
opScramble::~opScramble()
{} 
=======
opScramble::opScramble(controller* pCont) :operation(pCont)
{}
opScramble::~opScramble()
{}
>>>>>>> bab3859d683abf495d9c92d054cd758032630b19

//Execute the operation
void opScramble::Execute()
{
<<<<<<< HEAD
	
=======

>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pGr->scrambleGraph();
	pUI->PrintMessage("Graph scrambled");
}
<<<<<<< HEAD
=======
#include "opRedo.h"
#include "..\controller.h"

>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
