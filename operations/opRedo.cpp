#include "opRedo.h"
#include "..\controller.h"



opRedo::opRedo(controller* pCont) :operation(pCont)
{}
opRedo::~opRedo()
{}

//Execute the operation
void opRedo::Execute()
{
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	if (!pGr->emptyUndoHistory())
	{
		operationType lastOp = pGr->lastUndoOperation();
		if (lastOp == DRAW_CIRC || lastOp == DRAW_LINE || lastOp == DRAW_RECT || lastOp == DRAW_SQR || lastOp == DRAW_TRI)
		{
			pGr->Addshape(pGr->getLastDeletedShp());
			pGr->deleteLastDeletedShp();
		}
		pGr->recordOperation(lastOp);
		pGr->deleteFromUndoHistory();
	}

	pGr = nullptr;
}
