#include "opChngDrawClr.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChngDrawClr::opChngDrawClr(controller * pCont):operation(pCont)
{}
opChngDrawClr::~opChngDrawClr()
{} 

//Execute the operation
void opChngDrawClr::Execute()
{
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->switchToColor();

	color pickedcolor;
	pickedcolor = pUI->getColor("draw");

	pUI->changePenColor(pickedcolor);
	pUI->switchToDraw();

}
