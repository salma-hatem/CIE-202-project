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
	vector <shape*> clipboard; //clipboard for copied shape
	shape* rotatedShape;
	vector <operationType> operationHistory; //vector to record the history of operations made
	vector <operationType> undoHistory; //records the operations deleting
	vector <shape*> deletedShp;
	vector <Point> shapePositions;
	int col; int row = 250;								
	vector <shape*> selectedshapes;
	vector <shape*> matchedshapes;
	int score = 0;
	
	
public:	
	
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void AddToClipboard(shape* pFig); //add a pointer to the shape in the vector
	void clearClipBoard();
	shape* GetClipboard(); //returns the pointer in the clipboard
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) ; //Search for a shape given a point inside the shape
	shape* getselectedshape() const;
	void UnselectAll();
	void Save(ofstream& outfile);	//Save all shapes to a file
	void Load(ifstream& inputfile);	//Save all shapes to a file
	void Delete(); // Deletes one selected shape (Deletes the first shape in shapesList untill select feature is made)
	void DeleteMatched();
	bool getIsAllSaved() const;
	void setselectedshape();
	void setshapeshidden();
	void setshapeduphidded(int x, int y);
	vector <shape*> getmatched();
	void addMatched(shape* s);
	void clearMatched();
	void Addscore();
	void Subtractscore();
	int getscore();
	void setallduplicated(shape* s);
	void scrambleGraph(); //scrambles the graph
	void fillpositions(); //positions on the grid
	bool shapeslist();

//	UNDO

	bool emptyHistory(); //checks if the user made any operations
	operationType lastOperation() const; //returns the type of the last operation made
	void recordOperation(operationType); //records the last operation in the vector
	void deleteLastShp(); //deletes last shape in the shape vector
	void deleteFromHistory();

//	REDO

	bool emptyUndoHistory(); //checks if the user undo any operations
	operationType lastUndoOperation() const;
	void recordUndo(operationType); //adds operation to undoHistory
	void recordDeltedShp(); //saves a pointer to the deleted shape in deletedShp
	shape* getLastDeletedShp() const; //returns last element in deletedShp
	void deleteLastDeletedShp();
	void deleteFromUndoHistory();
};
