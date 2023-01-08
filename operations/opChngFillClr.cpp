#include "opChngFillClr.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opChngFillClr::opChngFillClr(controller * pCont):operation(pCont)
{}
opChngFillClr::~opChngFillClr()
{} 

//Execute the operation
void opChngFillClr::Execute()
{
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->switchToColor();

	color pickedcolor;
	pickedcolor = pUI->getColor("fill");

	pUI->changeFillColor(pickedcolor);
	pUI->switchToDraw();

	pUI = nullptr;
}
