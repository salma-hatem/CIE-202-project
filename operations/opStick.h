#pragma once

#include "operation.h"


class opStick : public operation
{
public:
	opStick(controller* pCont);
	virtual ~opStick();

	//select a shape 
	virtual void Execute();

};
