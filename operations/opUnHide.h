#pragma once
#include"..\operations\operation.h"


class opUnHide :public operation {
public:
	opUnHide(controller* pCont);
	virtual ~opUnHide();

	virtual void Execute();

};

