#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
#include <fstream>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
	string DrawClr_s;
	string FillClr_s;
	bool isHidden = false;
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY,	//Playing mode
		MODE_COLOR
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu
		ICON_TRI,		//Triangle icon in menu
		ICON_SQU,		//Square icon in menu
		ICON_LINE,		//Line icon in menu
		ICON_PEN,		//Pen icon in menu
		ICON_FILL,		//Fill icon in menu
		ICON_UNDO,
		ICON_REDO,
		ICON_SELECT,    //Select icon in menu
		ICON_DUPLICATE,
		ICON_SAVE,		//save icon in menu
		ICON_LOAD,		//Load icon in menu
		ICON_SWITCH,	//Switch icon in menu

		//TODO: Add more icons names here

		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};
	enum SideMenuIcon
	{
		//ICON_MOVE,
		ICON_COPY,		//copy icon in menu
		ICON_PASTE,		//paste icon in menu
		ICON_RESIZE,
		ICON_ROTATE,
		ICON_DELETE,	//Delete icon in menu
		SIDE_ICON_COUNT
	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_START,
		ICON_HIDE,
		ICON_UNHIDE,
		ICON_MATCH,
		ICON_SCRAMBLE,
		ICON_EXIT_P,
		//TODO: Add more icons names here

		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum Colors_CP
	{
		C_BLUE,
		C_RED,
		C_GREEN,
		C_YELLOW,
		C_ORANGE,
		C_PLUM,
		C_LIGHTBLUE,
		C_WHITE,
		C_BLACK,
		COLOR_COUNT,
	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		x1,y1,
		x2,y2,
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth,		//Width of each icon in toolbar menu
		ColorIconWidth,
		ColorPosition,
		SideMenuWidth,
		SideMenuPosition;


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	string DrawColor_s, FillColor_s; 
	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	window* getwind();
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateSideToolBar();

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo)const;
	void DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo)const;
	void DrawSquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const;
	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	string getCrntDrawColor_s() const;
	string getCrntFillColor_s() const;
	int getCrntPenWidth() const;		//get current pen width
	void switchToPlay(); //switches the play mode
	void changePenColor(color pickedColor); //changes pen color to picked color
	void changeFillColor(color pickedColor); //changes fill color to picked color

//	string getDrawclr() const ; //gets a string according to draw color
	//string getFillclr() const ; //gets a string according to fill color

	void switchToColor(); //colorPalette
	void CreateColorPalette(); //draw color palette
	color getColor(string draw_fill); //detect which
	void switchToDraw(); //switch back to play
	bool SaveOrExit(); //asks user whether they want to save
	double getFactor(); //asks choose a factor

	~GUI();
};

