#pragma once

#include "operation.h"

//Add Rectangle operation class

class opExit : public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit();

	//delete a shape
	virtual void Execute();

};
