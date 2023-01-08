#include "opLoad.h"
#include "..\controller.h"
#include <fstream>


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

	if (file) {
		//the file exists
		//pGr->Load(file);
		string str_line;
		vector<string> lines;
		string first_line;
		getline(file, first_line);
		stringstream ss(first_line);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> line_words(begin, end);

		pGi->setCrntDrawColor(line_words[0]);
		pGi->setCrntFillColor(line_words[1]);
		pGi->setPenWidth(line_words[2]);

		while (getline(file, str_line)) {

			//lines.push_back(str_line);
			stringstream ss(str_line);
			istream_iterator<string> begin(ss);
			istream_iterator<string> end;
			vector<string> line_words(begin, end);
			//pGi->setCrntDrawColor(line_words[0]);
			//pGi->setCrntFillColor(line_words[1]);
			//pGi->setPenWidth(line_words[2]);

			if (line_words[0] == "Circle") {
				//cout << "found a circle" << endl;
			}
			else if (line_words[0] == "Line") {
				//cout << "found a line" << endl;
			}
			else if (line_words[0] == "TRI") {
				//cout << "found a triangle" << endl;
			}
			else if (line_words[0] == "SQU") {
				//cout << "found a square" << endl;
			}
			else if (line_words[0] == "Rect") {
				//cout << "found a rectangle" << endl;
			}

		}

		file.close();
		pGi->PrintMessage("Your work is loaded ");
	}
	else {
		pGi->PrintMessage("The file doesn't exist");
	}
	//shape* pSH = pControl->load(file);





}