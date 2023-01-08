#include "Graph.h"
#include "../GUI/GUI.h"
#include<Windows.h>
#include <iostream>
#include<dos.h>
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
	//clipboard.clear();
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
	for (auto shapePointer : shapesList) {
		shapePointer->Draw(pUI);
		shapePointer->Hidding(pUI);
	}
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


void Graph::Save(ofstream& outfile)
{
	//CREATE A NEW FILE //ASK THE TA IF YOU CREATE A NEW FILE OR IS IT THE SAME FILE

	//GET THE SHAPES LIST 
	//LOOP THROUGH THE ELEMENTS

	shapesList[0]->InitializeAllSaved();
	outfile << "Draw color " << " fill color " << &GUI::getCrntPenWidth << " " << shapesList.size() << endl;
	for (int i = 0;i < shapesList.size();i++) {
		shapesList[i]->Save(outfile);


		//if (!shapesList[i]->IsAllSaved()) { //if there's a shape that isn't saved

			//GUI*->
		//}

	}

	//delete pOi;
	//pOi = nullptr;
	//Loop through the selected shape vector and call the save function in each shape
}


void Graph::Delete() {
	if (!shapesList.empty()) {
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
void Graph::DeleteMatched() {
	if (!shapesList.empty()) {
		int index = 0;
		auto num1 = find(shapesList.begin(), shapesList.end(), getmatched()[0]);  //serach for selectedShape
		if (num1 != shapesList.end()) { //the selected shape is in the shapesList
			index = num1 - shapesList.begin(); //get the index of selectedshape
			shapesList[index]->SetAllSaved(false);
		}
		auto num2 = find(shapesList.begin(), shapesList.end(), getmatched()[1]);  //serach for selectedShape
		if (num2 != shapesList.end()) { //the selected shape is in the shapesList
			index = num2 - shapesList.begin(); //get the index of selectedshape
			shapesList[index]->SetAllSaved(false);
		}
		shapesList.erase(remove(shapesList.begin(), shapesList.end(), getmatched()[0]), shapesList.end());//remove the selected shape from the shapesList*/
		shapesList.erase(remove(shapesList.begin(), shapesList.end(), getmatched()[1]), shapesList.end());//remove the selected shape from the shapesList*/

		//shapesList.erase(shapesList.begin());
		//switch the zero to the index of selected shape11
		//make the shape's saved= false
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


void Graph::setshapeshidden() {
	for (auto shapePointer : shapesList) {
		shapePointer->sethidden(true);
	}
}
void Graph::setshapeduphidded(int x, int y) {
	for (auto shapePointer : shapesList) {
		if (shapePointer->point_included(x, y))
		{
			shapePointer->sethidden(false);
			
			//shapePointer->sethidden(true);
	
		}
	}
	/*Sleep(300);
	setshapeshidden();*/
}

void Graph::addMatched(shape* s)
{
	matchedshapes.push_back(s);
}

vector <shape*> Graph::getmatched()
{
	return matchedshapes;
}

void Graph::clearMatched()
{
	matchedshapes.clear();
}
void Graph::Addscore() {
	static int score1 = 0;
	score1 += 1;
	ptr = &score1;
}
int Graph::getscore() {
	return *ptr;
}
void Graph::setallduplicated(shape* s) {
	for (auto shapePointer : shapesList) {
		AddToClipboard(shapePointer);
		/*if (shapePointer)
		{
			shape* newShp = shapePointer->duplicate(shapePointer);
			Addshape(newShp);
			
		}*/
	}
	for (auto clip : clipboard) {
		shape* newshp = clip->duplicate(clip);
		Addshape(newshp);
	}
	
}