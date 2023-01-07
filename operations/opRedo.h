#pragma once

#include "operation.h"

//Add Rectangle operation class

class opRedo : public operation
{
public:
	opRedo(controller* pCont);
	virtual ~opRedo();

	//delete a shape
	virtual void Execute();

};
