#pragma once
#include "operation.h"


class opStart : public operation
{
public:
	opStart(controller* pCont);
	virtual ~opStart();

	//select a shape 
	virtual void Execute();

};
