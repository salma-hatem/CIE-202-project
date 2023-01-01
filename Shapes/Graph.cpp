#include <iostream>
#include "Graph.h"
#include "../GUI/GUI.h"
using namespace std;



Graph::Graph()
{
	selectedShape = nullptr;
	

	
}

Graph::~Graph()
{
	selectedShape = nullptr;
	
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}


void Graph::AddToClipboard(shape* pFig)
{
	clipboard.clear();
	clipboard.push_back(pFig);
}
shape* Graph::GetClipboard()
{
	return clipboard[0];
}

////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}
shape* Graph::getselectedshape()const {
	return selectedShape;
}

shape* Graph::Getshape(int x, int y) 
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL
	for (auto shapePointer = shapesList.rbegin(); shapePointer != shapesList.rend(); ++shapePointer)
		if ((*shapePointer)->point_included(x, y))
		{
			selectedShape = (*shapePointer);
			return selectedShape;
			break;
		
		}
		return nullptr;
	}
void Graph::UnselectAll()
{
	for (auto shapePointer : shapesList)
		shapePointer->SetSelected(false);
	selectedShape = nullptr;
}


//return nullptr;



void Graph::Save(ofstream& outfile) {
	

	//GET THE SHAPES LIST 
	//LOOP THROUGH THE ELEMENTS

	shapesList[0]->InitializeAllSaved();

	for (int i = 0;i < shapesList.size();i++) {
		shapesList[i]->Save(outfile);

		
	}


}

void Graph::Delete() {
	if (!shapesList.empty()){
	int index = 0;
	auto num = find(shapesList.begin(), shapesList.end(), getselectedshape());  //serach for selectedShape
	if (num != shapesList.end()) { //the selected shape is in the shapesList
		index = num - shapesList.begin(); //get the index of selectedshape
		shapesList[index]->SetAllSaved(false);

	}
	shapesList.erase(remove(shapesList.begin(), shapesList.end(), getselectedshape()), shapesList.end());//remove the selected shape from the shapesList*/
	//shapesList.erase(shapesList.begin());
	//switch the zero to the index of selected shape11
	//make the shape's saved= false


}
}

void Graph:: Load(ifstream& inputfile) {

	//slice the file into lines and each line into an array of wo crds
	//if statement to know which shape it is
	//create the shapes with the same parameters 
	//append these shapes into shapeslist
	string str_line;
	//vector<string> lines;

	while (getline(inputfile, str_line)) {

		//lines.push_back(str_line);
		stringstream ss(str_line);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> line_words(begin, end);
		if (line_words[0] == "Circle") {
			cout << "found a circle" << endl;
		}
		else if (line_words[0] == "Line") {
			cout << "found a line" << endl;
		}
		else if (line_words[0] == "TRI") {
			cout << "found a triangle" << endl;
		}
		else if (line_words[0] == "SQU") {
			cout << "found a square" << endl;
		}
		else if (line_words[0] == "Rect") {
			cout << "found a rectangle" << endl;
		}

	}
	 
}



bool Graph::getIsAllSaved() const
{
	bool saved = true;
	for (int i = 0; i < shapesList.size();i++)
	{
		saved = saved && shapesList[i]->IsAllSaved();
	}
	return saved;
}

void Graph::setselectedshape()
{
	for (int i = 0; i < shapesList.size();i++)
	{
		if (shapesList[i]->IsSelected()) selectedShape = shapesList[i];
	}
}