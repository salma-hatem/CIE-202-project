#include "opPaste.h"
#include "..\shapes\Circle.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opPaste::opPaste(controller * pCont):operation(pCont)
{}
opPaste::~opPaste()
{} 

//Execute the operation
void opPaste::Execute()
{
	Graph* pGr = pControl->getGraph();
	shape* clip = pGr->GetClipboard();
	if (clip)
	{
		shape* newShp = clip->duplicate(clip);
		pGr->Addshape(newShp);
	}
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Shape pasted!");
}
