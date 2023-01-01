#pragma once
#include "Shape.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	// vector for a single selected shape
<<<<<<< Updated upstream
	vector <shape*> clipboard; //clipboard for copied shape
=======
	shape* rotatedShape;
>>>>>>> Stashed changes
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void AddToClipboard(shape* pFig); //add a pointer to the shape in the vector
	shape* GetClipboard(); //returns the pointer in the clipboard
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) ; //Search for a shape given a point inside the shape
	shape* getrotatedshape(int x, int y);
	shape* getselectedshape() const;
	void UnselectAll();
	void Save(ofstream& outfile);	//Save all shapes to a file
	void Load(ifstream& inputfile);	//Save all shapes to a file
	void Delete(); // Deletes one selected shape (Deletes the first shape in shapesList untill select feature is made)
	shape* getSelectedShape();
	bool getIsAllSaved() const;
	void setselectedshape();

	
};
