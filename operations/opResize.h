#pragma once

#include "operation.h"

//Add Rectangle operation class
class opResize: public operation
{
public:
	opResize(controller *pCont);
	virtual ~opResize();
	
	//Add rectangle to the controller
	virtual void Execute() ;
	
};

