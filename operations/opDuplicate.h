#pragma once

#include "operation.h"

//Add Rectangle operation class
class opDuplicate : public operation
{
public:
	opDuplicate(controller* pCont);
	virtual ~opDuplicate();

	//Add rectangle to the controller
	virtual void Execute();

};

