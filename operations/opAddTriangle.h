#pragma once

#include "operation.h"

//Add Triangle operation class
class opAddTriangle : public operation
{
public:
	opAddTriangle(controller* pCont);
	virtual ~opAddTriangle();

	//Add rectangle to the controller
	virtual void Execute();

};