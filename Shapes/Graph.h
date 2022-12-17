#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
<<<<<<< HEAD
	shape* selectedShape;	//pointer to the currently selected shape
public:
=======
	shape* selectedShape;	// vector for a single selected shape
public:										
>>>>>>> origin/salma
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape
	shape* getselectedshape() const;
	void UnselectAll();
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	void Delete(); // Deletes one selected shape (Deletes the first shape in shapesList untill select feature is made)
	shape* getSelectedShape();
	
};
