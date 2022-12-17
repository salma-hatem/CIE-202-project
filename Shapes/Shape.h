#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <fstream>


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
<<<<<<< HEAD

=======
	bool AllSaved;
	
>>>>>>> origin/salma
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected

<<<<<<< HEAD
	virtual void Draw(GUI* pUI) const = 0;		//Draw the shape

=======
	void InitializeAllSaved(); //initalizes all saved to the value of the first shape (saved ot not)
	bool IsAllSaved() const;		//getter to know if all shapes are saved
	void SetAllSaved(bool s);		//sets the boolean to true if all the shapes are saved

	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
>>>>>>> origin/salma
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color

	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	
	virtual bool point_included(int x, int y) = 0;

	//virtual void Rotate() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void Save(ofstream &outfile) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};

