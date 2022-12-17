#pragma once
#include "operation.h"

//Add Square operation class
class opaddRegPolygon : public operation
{
public:
	opaddRegPolygon(controller* pCont);
	virtual ~opaddRegPolygon();

	//Add regular polygon to the controller
	virtual void Execute();

}; 
