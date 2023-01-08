#include "Graph.h"
#include "../GUI/GUI.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
=======
=======
#include <iostream>
#include <vector>
#include <algorithm>
>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
#include<Windows.h>
#include <iostream>
#include<dos.h>
using namespace std;
>>>>>>> d22ddba5cca426ecc4e0c030bafc2e297120ab18

Graph::Graph()
{
	selectedShape = nullptr;
<<<<<<< HEAD
<<<<<<< HEAD
=======
	rotatedShape = nullptr;

	
>>>>>>> origin/salma
=======
	rotatedShape = nullptr;

	
>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
}

Graph::~Graph()
{
	selectedShape = nullptr;
<<<<<<< HEAD
<<<<<<< HEAD
=======
	rotatedShape = nullptr;
>>>>>>> origin/salma
=======
	rotatedShape = nullptr;
>>>>>>> bab3859d683abf495d9c92d054cd758032630b19
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
void Graph::clearClipBoard()
{
	clipboard.clear();
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
	for (auto shapePointer = shapesList.rbegin(); shapePointer != shapesList.rend(); ++shapePointer) {
		if ((*shapePointer)->point_included(x, y))
		{
			selectedShape = (*shapePointer);
			return selectedShape;
		}
		
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
//void Graph::Hide(GUI* pUI) {
//	pUI->getwind()->DrawString(20,20, "ssss");
//	for (auto shapePointer : shapesList) {
//		shapePointer->Hidding(pUI);
//	
//	}
//	Draw(pUI);
//}
=======
=======
/*
void Graph::scrambleGraph()
{
	for (int i = 0; i < shapesList.size();i++)
	{
		shapesList[i]->scrambleShape();
	}
}*/

void Graph::scrambleGraph()
{
	fillpositions();
	double factor = 1;
	Point position;
	std::random_shuffle(shapesList.begin(), shapesList.end());
	for (int i = 0; i < shapesList.size();i++)
	{
		shapesList[i]->calculateWH();
		factor = shapesList[i]->getfactor(col, row-20);
		shapesList[i]->resize(factor);
		position.x = shapePositions[i].x + 10;
		position.y = shapePositions[i].y + 10;
		shapesList[i]->scrambleShape(position,col,row);
	}
}

void Graph::fillpositions()
{
	col = 1000 / (shapesList.size()/2);
	int c = 0;
	Point p;
	for (int i = 0;i < shapesList.size();i++)
	{
		/*if (c == shapesList.size() / 2) c = 0;
		shapePositionsx.push_back(100+10+(col+10)*(c));
		c++;
		int y = 100 + 10 + 250 * (i / (shapesList.size() / 2));
		shapePositionsy.push_back(100 + 10 + 250 * (i / (shapesList.size() / 2)));*/
		if (c == shapesList.size() / 2) c = 0;
		p.x=100 + 10 + (col + 10) * (c);
		c++;
		p.y =100 + 10 + 250 * (i / (shapesList.size() / 2));
		shapePositions.push_back(p);
	}
}


//////////////////////////////////////////
//					UNDO				//
//////////////////////////////////////////


bool Graph::emptyHistory()
{
	//int x = operationHistory.size();
	if (operationHistory.size() == 0) return true;
	else return false;
}

operationType Graph::lastOperation() const
{
	return operationHistory[operationHistory.size()-1];
}

void Graph::recordOperation(operationType x)
{
	operationHistory.push_back(x);
}

void Graph::deleteLastShp()
{
	//deletedShp.push_back(shapesList[shapesList.size() - 1]);
	shapesList.pop_back();
}
void Graph::deleteFromHistory()
{
	operationHistory.pop_back();
}

//////////////////////////////////////////
//					REDO				//
//////////////////////////////////////////

bool Graph::emptyUndoHistory()
{
	//int x = undoHistory.size();
	if (undoHistory.size() == 0) return true;
	else return false;
}

operationType Graph::lastUndoOperation() const
{
	return undoHistory[undoHistory.size() - 1];
}

void Graph::recordUndo(operationType x)
{
	undoHistory.push_back(x);
}

void Graph::recordDeltedShp()
{
	deletedShp.push_back(shapesList[shapesList.size() - 1]);
}

shape* Graph::getLastDeletedShp() const
{
	return deletedShp[deletedShp.size() - 1];
}

void Graph::deleteLastDeletedShp()
{
	deletedShp.pop_back();
}

void Graph::deleteFromUndoHistory()
{
	undoHistory.pop_back();
}
>>>>>>> bab3859d683abf495d9c92d054cd758032630b19

>>>>>>> d22ddba5cca426ecc4e0c030bafc2e297120ab18

void Graph::setshapeshidden() {
	for (auto shapePointer : shapesList) {
		shapePointer->currenthidden(true);
	}
}
void Graph::setshapeduphidded(int x, int y) {

	for (auto shapePointer = shapesList.rbegin(); shapePointer != shapesList.rend(); ++shapePointer) {
		if ((*shapePointer)->point_included(x, y)) {
			(*shapePointer)->currenthidden(false);
			(*shapePointer)->prevhidden(true);
			
		}
		
	}
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
	score += 3;
}
void Graph::Subtractscore() {
	score -= 1;
	
}
int Graph::getscore() {
	return score;
}
<<<<<<< HEAD

=======
/*
void Graph::scrambleGraph()
{
	for (int i = 0; i < shapesList.size();i++)
	{
		shapesList[i]->scrambleShape();
	}
}*/

void Graph::scrambleGraph()
{
	fillpositions();
	double factor = 1;
	Point position;
	std::random_shuffle(shapesList.begin(), shapesList.end());
	for (int i = 0; i < shapesList.size();i++)
	{
		shapesList[i]->calculateWH();
		factor = shapesList[i]->getfactor(col, row-20);
		shapesList[i]->resize(factor);
		position.x = shapePositions[i].x + 10;
		position.y = shapePositions[i].y + 10;
		shapesList[i]->scrambleShape(position,col,row);
	}
}

void Graph::fillpositions()
{
	col = 1000 / (shapesList.size()/2);
	int c = 0;
	Point p;
	for (int i = 0;i < shapesList.size();i++)
	{
		/*if (c == shapesList.size() / 2) c = 0;
		shapePositionsx.push_back(100+10+(col+10)*(c));
		c++;
		int y = 100 + 10 + 250 * (i / (shapesList.size() / 2));
		shapePositionsy.push_back(100 + 10 + 250 * (i / (shapesList.size() / 2)));*/
		if (c == shapesList.size() / 2) c = 0;
		p.x=100 + 10 + (col + 10) * (c);
		c++;
		p.y =100 + 10 + 250 * (i / (shapesList.size() / 2));
		shapePositions.push_back(p);
	}
}


//////////////////////////////////////////
//					UNDO				//
//////////////////////////////////////////


bool Graph::emptyHistory()
{
	//int x = operationHistory.size();
	if (operationHistory.size() == 0) return true;
	else return false;
}

operationType Graph::lastOperation() const
{
	return operationHistory[operationHistory.size()-1];
}

void Graph::recordOperation(operationType x)
{
	operationHistory.push_back(x);
}

void Graph::deleteLastShp()
{
	//deletedShp.push_back(shapesList[shapesList.size() - 1]);
	shapesList.pop_back();
}
void Graph::deleteFromHistory()
{
	operationHistory.pop_back();
}

//////////////////////////////////////////
//					REDO				//
//////////////////////////////////////////

bool Graph::emptyUndoHistory()
{
	//int x = undoHistory.size();
	if (undoHistory.size() == 0) return true;
	else return false;
}

operationType Graph::lastUndoOperation() const
{
	return undoHistory[undoHistory.size() - 1];
}

void Graph::recordUndo(operationType x)
{
	undoHistory.push_back(x);
}

void Graph::recordDeltedShp()
{
	deletedShp.push_back(shapesList[shapesList.size() - 1]);
}

shape* Graph::getLastDeletedShp() const
{
	return deletedShp[deletedShp.size() - 1];
}

void Graph::deleteLastDeletedShp()
{
	deletedShp.pop_back();
}

void Graph::deleteFromUndoHistory()
{
	undoHistory.pop_back();
}
>>>>>>> origin/salma
=======
void Graph::setallduplicated(shape* s) {
	for (auto shapePointer : shapesList) {
		AddToClipboard(shapePointer);
		
	}
	for (auto clip : clipboard) {
		shape* newshp = clip->duplicate(clip);
		Addshape(newshp);
	}
	
}
>>>>>>> d22ddba5cca426ecc4e0c030bafc2e297120ab18
