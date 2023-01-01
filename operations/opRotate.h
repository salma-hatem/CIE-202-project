#pragma once

#include "operation.h"


class opRotate : public operation
{
public:
	opRotate(controller* pCont);
	virtual ~opRotate();

	//select a shape 
	virtual void Execute();

};
