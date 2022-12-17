#include "opLoad.h"
#include "..\controller.h"



opLoad::opLoad(controller* pCont) :operation(pCont)
{}
opLoad::~opLoad() // 
{}

//Execute the operation
void opLoad::Execute()

{
	GUI* pGi = pControl->GetUI();
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();



	//create a file 
	//get the name of the file from the user since you have a
	pGi->PrintMessage("write the name of the file to load from ");

	string file_name = pGi->GetSrting();

	ifstream file;

	file.open(file_name, ios::out);
	//call function Save from Graph

	//pGr->load(file);

	file.close();
	pGi->PrintMessage("Your work is loaded ");
}