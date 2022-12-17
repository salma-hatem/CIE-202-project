#include "operation.h"

class opisSelected : public operation
{
public:
	opisSelected(controller* pCont);
	virtual ~opisSelected();

	//Add Circle to the controller
	virtual void Execute();

};