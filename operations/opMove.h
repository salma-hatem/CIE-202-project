#pragma once
#include "operation.h"

class opMove: public operation
{
public:
	opMove(controller* pCont);
	virtual ~opMove();

	//loads all shapes
	virtual void Execute();

};