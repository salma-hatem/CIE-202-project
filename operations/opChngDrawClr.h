#pragma once

#include "operation.h"

//Add Rectangle operation class
class opChngDrawClr: public operation
{
public:
	opChngDrawClr(controller *pCont);
	virtual ~opChngDrawClr();
	
	//Add rectangle to the controller
	virtual void Execute() ;
	
};

