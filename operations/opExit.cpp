#include "opExit.h"
#include "..\controller.h"
//#include "..\Shapes\Shape.h"
//#include "..\GUI\GUI.h"
#include <fstream>


opExit::opExit(controller* pCont) :operation(pCont)
{}
opExit::~opExit()
{}

//Execute the operation
void opExit::Execute()
{
  //Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	bool isAllSaved=pControl->getGraph()->getIsAllSaved();

	if (!isAllSaved)
	{
		pUI->PrintMessage("Some changes are not saved... Do you want to save? (y/n)");
		bool save = pUI->SaveOrExit();
		if (save)
		{
			ofstream file;
			pUI->PrintMessage("Which file would you like to save in?");
			string name = pUI->GetSrting();
			file.open(name, ios::out);
			pGr->Save(file);
			file.close();
		}
	}
}
