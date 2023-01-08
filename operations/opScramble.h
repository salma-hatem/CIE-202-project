#pragma once

#include "operation.h"

//Add Rectangle operation class
class opScramble: public operation
{
public:
	opScramble(controller *pCont);
	virtual ~opScramble();
	
	//Add rectangle to the controller
	virtual void Execute() ;
	
};

