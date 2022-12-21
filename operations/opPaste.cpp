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
		string type = clip->getType();
		GfxInfo info = clip->getInfo();
		if (type == "circle")
		{
			Circle* CLIP = (Circle*)(clip);
			Point p1 = CLIP->getP1();
			Point p2 = CLIP->getP2();
			p1 = CLIP->pointshift(p1);
			p2 = CLIP->pointshift(p2);
			Circle* S = new Circle(p1, p2, info);
			pGr->Addshape(S);
		}
	}
}
