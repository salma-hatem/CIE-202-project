#pragma once

#include "operation.h"

//Add Rectangle operation class

class opDelete : public operation
{
public:
	opDelete(controller* pCont);
	virtual ~opDelete();

	//delete a shape
	virtual void Execute();

};
