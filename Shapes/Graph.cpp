#include "Graph.h"
#include "../GUI/GUI.h"



Graph::Graph()
{
	selectedShape = nullptr;
	rotatedShape = nullptr;

	
}

Graph::~Graph()
{
	selectedShape = nullptr;
	rotatedShape = nullptr;
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
		
		}
		return nullptr;
	}
//shape* Graph::getrotatedshape(int x, int y) {
//	for (auto shapePointer = shapesList.rbegin(); shapePointer != shapesList.rend(); ++shapePointer) {
//		if ((*shapePointer)->point_included(x, y))
//		{
//			rotatedShape = (*shapePointer);
//			return rotatedShape;
//		}
//	}
//	return nullptr;
//}

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

shape* Graph::getSelectedShape() 
{
	return selectedShape;
}


void Graph::Delete() {
	int index = 0;
	auto num = find(shapesList.begin(), shapesList.end(), getSelectedShape());  //serach for selectedShape
	if (num != shapesList.end()) { //the selected shape is in the shapesList
		 index = num - shapesList.begin(); //get the index of selectedshape
	};
	shapesList.erase(shapesList.begin()+index);//remove the selected shape from the shapesList*/
	shapesList[index]->SetAllSaved(false);
	//shapesList.erase(shapesList.begin());
	//switch the zero to the index of selected shape11
	//make the shape's saved= false

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

void Graph::scrambleGraph()
{
	for (int i = 0; i < shapesList.size();i++)
	{
		shapesList[i]->scrambleShape();
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