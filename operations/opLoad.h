#pragma once
#include "operation.h"
#include <fstream>
//Add Rectangle operation class

class opLoad : public operation
{
public:
	opLoad(controller* pCont);
	virtual ~opLoad();

	//loads all shapes
	virtual void Execute();

};