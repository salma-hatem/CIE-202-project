#pragma once

#include "operation.h"


class opSelect : public operation
{
public:
	opSelect(controller* pCont);
	virtual ~opSelect();

	//select a shape 
	virtual void Execute();

};
