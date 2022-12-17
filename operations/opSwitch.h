#pragma once

#include "operation.h"

//Add Rectangle operation class
class opSwitch: public operation
{
public:
	opSwitch(controller *pCont);
	virtual ~opSwitch();
	
	//Add rectangle to the controller
	virtual void Execute() ;
	
};

