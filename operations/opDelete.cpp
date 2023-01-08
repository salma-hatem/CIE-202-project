#include "opDelete.h"
#include "..\controller.h"



opDelete::opDelete(controller* pCont) :operation(pCont)
{}
opDelete::~opDelete()
{}

//Execute the operation
void opDelete::Execute()
{
  //Get a pointer to the graph
	Graph* pGr = pControl->getGraph();


	//call function Delete from Graph
	 
	pGr->Delete();

	pGr = nullptr;
}
