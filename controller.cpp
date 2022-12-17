#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\opAddLine.h"
#include "operations\opAddSquare.h"
#include "operations\opSelect.h"
#include "operations\opAddTriangle.h"
#include "operations\opAddCircle.h"
#include "operations\opAddLine.h"
#include "operations\opAddTriangle.h"
#include "operations\opAddCircle.h"
#include "operations\opAddSquare.h"
#include "operations\opDelete.h"
#include "operations\opChngDrawClr.h"
#include "operations\opChngFillClr.h"
#include "operations\opSwitch.h"
#include "operations\opSave.h"
#include "operations\opExit.h"
//#include "operations\opLoad.h"

//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;

	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;
		case DRAW_SQR:
			pOp = new opAddSquare(this);
			break;

		case DRAW_LINE:
			///create AddLineoperation here
			pOp = new opAddLine(this);
			break;

		case DRAW_TRI:
			///create AddTriangleoperation here
			pOp = new opAddTriangle(this);
			break;
		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;
		case SAVE:
			pOp = new opSave(this);
			break;
		case EXIT:
			///create Exitoperation here
			pOp = new opExit(this);
			break;

		case DEL:
			pOp = new opDelete(this);
			break;
		case SELECT:
			pOp = new opSelect(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
		case CHNG_DRAW_CLR:
			pOp = new opChngDrawClr(this);
			break;
		case CHNG_FILL_CLR:
			pOp = new opChngFillClr(this);
			break;
		case TO_PLAY:
			pOp = new opSwitch(this);
			break;
		case DRAW_POLY:

			break;
			
	}
	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}




//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}