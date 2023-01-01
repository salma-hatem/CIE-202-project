/*#include "opSave.h"
#include "..\controller.h"



opSave::opSave(controller* pCont) :operation(pCont)
{}
opSave::~opSave() // 
{}

//Execute the operation
void opSave::Execute()

{
	GUI* pGi = pControl->GetUI();
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();



	//create a file 
	//get the name of the file from the user since you have a
	pGi->PrintMessage("write the name of the file to save in ");

	string file_name = pGi->GetSrting();

	ofstream file;

	file.open(file_name, ios::out);
	//call function Save from Graph

	file << pGi->getCrntDrawColor_s() << " " << pGi->getCrntFillColor_s() << " " << pGi->getCrntPenWidth() << endl;

	pGr->Save(file);

	file.close();
	pGi->PrintMessage("Your work is saved! ");
}*/