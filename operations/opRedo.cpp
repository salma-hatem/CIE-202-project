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
		if (lastOp == DELETE) {
			//delete the last shape
			pGr->selectLastSelectedShape();
			pGr->Delete();
			pGr->Addshape(pGr->getLastDeletedShp());
			pGr->deleteLastDeletedShp();

		}
		if (lastOp == MOVE) {
			//delete the last selected shape  (make a selected shapes vector)
			//redraw the shape with original points
			
			pGr->selectLastDeletedShape();
			pGr->Delete();

		}
		pGr->recordOperation(lastOp);
		pGr->deleteFromUndoHistory();
	}
}
