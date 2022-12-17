#pragma once
#include "operation.h"
#include <fstream>
//Add Rectangle operation class

class opSave : public operation
{
public:
	opSave(controller* pCont);
	virtual ~opSave();

	//saves all shapes
	virtual void Execute();

};