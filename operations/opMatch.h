#pragma once
#include "operation.h"


class opMatch: public operation
{
public:
	opMatch(controller* pCont);
	virtual ~opMatch();

	//select a shape 
	virtual void Execute();

};

