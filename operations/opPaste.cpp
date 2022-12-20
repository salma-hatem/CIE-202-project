#include "opPaste.h"
#include "..\shapes\Rect.h"
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
		
	}
}
