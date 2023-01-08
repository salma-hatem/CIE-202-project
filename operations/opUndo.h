#pragma once

#include "operation.h"

//Add Rectangle operation class

class opUndo : public operation
{
public:
	opUndo(controller* pCont);
	virtual ~opUndo();

	//delete a shape
	virtual void Execute();

};
