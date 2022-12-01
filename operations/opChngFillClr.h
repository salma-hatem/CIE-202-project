#pragma once

#include "operation.h"

//Add Rectangle operation class
class opChngFillClr: public operation
{
public:
	opChngFillClr(controller *pCont);
	virtual ~opChngFillClr();
	
	//Add rectangle to the controller
	virtual void Execute() ;
	
};

