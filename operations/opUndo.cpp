#include "opUndo.h"
#include "..\controller.h"



opUndo::opUndo(controller* pCont) :operation(pCont)
{}
opUndo::~opUndo()
{}

//Execute the operation
void opUndo::Execute()
{
<<<<<<< HEAD
  //Get a pointer to the graph
=======
	//Get a pointer to the graph
>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
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
