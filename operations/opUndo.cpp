#include "opUndo.h"
#include "..\controller.h"



opUndo::opUndo(controller* pCont) :operation(pCont)
{}
opUndo::~opUndo()
{}

//Execute the operation
void opUndo::Execute()
{
  //Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	if (!pGr->emptyHistory())
	{
		operationType lastOp = pGr->lastOperation();
		if (lastOp == DRAW_CIRC || lastOp == DRAW_LINE || lastOp == DRAW_RECT || lastOp == DRAW_SQR || lastOp == DRAW_TRI)
		{
			pGr->recordDeltedShp();
			pGr->deleteLastShp();
		}
		pGr->recordUndo(lastOp);
		pGr->deleteFromHistory();
	}

}
