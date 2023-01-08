#include "opRedo.h"
#include "..\controller.h"



opRedo::opRedo(controller* pCont) :operation(pCont)
{}
opRedo::~opRedo()
{}

//Execute the operation
void opRedo::Execute()
{
<<<<<<< HEAD
  //Get a pointer to the graph
=======
	//Get a pointer to the graph
>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
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
}
