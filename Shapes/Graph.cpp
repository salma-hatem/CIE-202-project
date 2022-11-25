#include "Graph.h"
#include "../GUI/GUI.h"



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
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}


shape* Graph::getSelectedShape() {
	return selectedShape;
}

void Graph:: Delete(){
	/*int index = 0;
	auto num = find(shapesList.begin(), shapesList.end(), selectedShape);  //serach for selectedShape 
	if (num != shapesList.end()) { //the selected shape is in the shapesList 
		 index = num - shapesList.begin(); //get the index of selectedshape
	};
	shapesList.erase(shapesList.begin()+index);//remove the selected shape from the shapesList*/
	shapesList.erase(shapesList.begin());


}