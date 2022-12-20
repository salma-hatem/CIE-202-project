


#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;
	ColorIconWidth = 30;
	ColorPosition=10;

	DrawColor = BLUE;	//default Drawing color
	FillColor = WHITE;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames
	DrawColor_s = "BLUE";
	FillColor_s = "WHITE";


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{

			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_TRI: return DRAW_TRI;
			case ICON_SQU: return DRAW_SQR;
			case ICON_LINE: return DRAW_LINE;
			//case ICON_POLY: return DRAW_POLY;
			case ICON_PEN: return CHNG_DRAW_CLR;
			case ICON_FILL: return CHNG_FILL_CLR;
			case ICON_DELETE: return DEL;
			case ICON_SAVE: return SAVE;
			case ICON_LOAD: return LOAD;
			case ICON_SELECT: return SELECT;
			case ICON_SWITCH: return TO_PLAY;
			case ICON_EXIT: return EXIT;




			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_EXIT_P: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
		//return TO_PLAY;	//just for now. This should be updated
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);

	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar()
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Tri.jpg";
	MenuIconImages[ICON_SQU] = "images\\MenuIcons\\Menu_Squ.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	//MenuIconImages[ICON_POLY] = "images\\MenuIcons\\Menu_Poly.jpg";
	MenuIconImages[ICON_PEN] = "images\\MenuIcons\\Menu_Pen.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\Menu_Fill.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\Menu_Delete.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\Menu_SElect.jpg";
	MenuIconImages[ICON_SWITCH] = "images\\MenuIcons\\Menu_Switch.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";


	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(LIGHTSEAGREEN, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar()
{
	InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICON_START] = "images\\MenuIcons\\Menu_Start.jpg";
	MenuIconImages[ICON_EXIT_P] = "images\\MenuIcons\\Menu_Exit.jpg";


	//Draw menu icon one image at a time
	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(LIGHTSEAGREEN, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);

}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}

/*string GUI::getDrawclr() const //gets a string according to draw color
{
	 color currentclr = getCrntDrawColor();

	
	switch (currentclr)
	{
	case RED: return "Red";
	/*case C_BLUE: return BLUE;
	case C_ORANGE: return ORANGE;
	case C_GREEN: return GREEN;
	case C_YELLOW: return YELLOW;
	case C_PLUM: return PLUM;
	case C_LIGHTBLUE: return LIGHTBLUE;
	case C_WHITE: return WHITE;
	case C_BLACK: return BLACK;


	default: return "ROYALBLUE";	//A click on empty place in desgin toolbar
	}

}*/

//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

//string getFillclr(); //gets a string according to fill color

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

string GUI::getCrntDrawColor_s() const 
{
	return DrawColor_s;
}
string GUI::getCrntFillColor_s() const 
{
	return FillColor_s;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

/*
void GUI::DrawSquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;


	double length, dxsq, dysq;
	dxsq = pow(P1.x - P2.x, 2);
	dysq = pow(P1.y - P2.y, 2);
	length = pow(dxsq + dysq, 0.5);
	pWind->DrawRectangle(P1.x, P1.y, (P1.x) + length, (P1.y) + length, style);

}*/
void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else 
		DrawingClr = RectGfxInfo.DrawClr;
	

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
///////////////////////////////////
/*
// temp draw square
void GUI::DrawSquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int diffY = P2.y - P1.y;
	P2.x = P1.x + diffY;
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
*/
void GUI::DrawSquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)    //shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);    //Set Drawing color & width

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;


	double length, dxsq, dysq;
	dxsq = pow(P1.x - P2.x, 2);
	dysq = pow(P1.y - P2.y, 2);
	length = pow(dxsq + dysq, 0.5);
	pWind->DrawRectangle(P1.x, P1.y, (P1.x) + length, (P1.y) + length, style);

}
//test switch function ---> need to make an op class instead??

void GUI::switchToPlay() 
{
	InterfaceMode = MODE_PLAY;
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, height);
	CreatePlayToolBar();
	CreateStatusBar();
}

void GUI::changePenColor(color pickedColor)
{
	DrawColor = pickedColor;
}

void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const{
	color DrawingClr;
	if (LineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}
void GUI::DrawTriangle(Point P1, Point P2,Point P3, GfxInfo TriangleGfxInfo) const {
	color DrawingClr;
	if (TriangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x,P3.y, style);
}

void GUI::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo) const {
	color DrawingClr;
	if (CircleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	double redius, dxsq, dysq;
	dxsq = pow(P1.x - P2.x, 2);
	dysq = pow(P1.y - P2.y, 2);
	redius = pow(dxsq + dysq, 0.5);
	pWind->DrawCircle(P1.x, P1.y, redius, style);
}


void GUI::changeFillColor(color pickedColor)
{
	FillColor = pickedColor;
}

//////////////////////////////////////////////////////////////////////////////////////////

// color palette

void GUI::switchToColor()
{
	InterfaceMode = MODE_COLOR;
	CreateColorPalette();
}

void GUI::CreateColorPalette()
{
	InterfaceMode = MODE_COLOR;
	///TODO: write code to create Play mode menu
	string MenuIconImages[COLOR_COUNT];
	MenuIconImages[C_BLUE] = "images\\colors\\blue.jpg";
	MenuIconImages[C_RED] = "images\\colors\\red.jpg";
	MenuIconImages[C_YELLOW] = "images\\colors\\yellow.jpg";
	MenuIconImages[C_GREEN] = "images\\colors\\green.jpg";
	MenuIconImages[C_ORANGE] = "images\\colors\\orange.jpg";
	MenuIconImages[C_PLUM] = "images\\colors\\plum.jpg";
	MenuIconImages[C_LIGHTBLUE] = "images\\colors\\light_blue.jpg";
	MenuIconImages[C_WHITE] = "images\\colors\\white.jpg";
	MenuIconImages[C_BLACK] = "images\\colors\\black.jpg";

	//Draw menu icon one image at a time
	for (int i = 0; i < COLOR_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], ColorPosition + (i * ColorIconWidth), (height - (StatusBarHeight - 2)), ColorIconWidth, ColorIconWidth);
	//pWind->DrawImage(MenuIconImages[i], (width/2)+(i * 10), height - StatusBarHeight-5, (width / 2) + (i * 10)+10, height - StatusBarHeight +5);
}
color GUI::getColor(string draw_fill)
{
	int x, y;

	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	//[1] If user clicks on the Toolbar
	if (y >= height - (StatusBarHeight - 2) && y < height - (StatusBarHeight - ColorIconWidth - 2) && x>= ColorPosition && x < 10 + ColorIconWidth * COLOR_COUNT)
	{
		//Check whick Menu icon was clicked
		//==> This assumes that menu icons are lined up horizontally <==
		int ClickedIconOrder = ((x - ColorPosition) / 30);
		//Divide x coord of the point clicked by the menu icon width (int division)
		//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

		switch (ClickedIconOrder)
		{
		case C_RED: 
			if (draw_fill == "draw") DrawColor_s = "RED";
			if (draw_fill == "fill") FillColor_s = "RED";
			return RED;
		case C_BLUE:
			if (draw_fill == "draw") DrawColor_s = "BLUE";
			else FillColor_s = "BLUE";
			return BLUE;
		case C_ORANGE: 
			if (draw_fill == "draw") DrawColor_s = "ORANGE";
			else FillColor_s = "ORANGE";
			return ORANGE;
		case C_GREEN: 
			if (draw_fill == "draw") DrawColor_s = "GREEN";
			else FillColor_s = "GREEN";
			return GREEN;
		case C_YELLOW: 
			if (draw_fill == "draw") DrawColor_s = "YELLOW";
			else FillColor_s = "YELLOW";
			return YELLOW;
		case C_PLUM: 
			if (draw_fill == "draw") DrawColor_s = "PLUM";
			else FillColor_s = "PLUM";
			return PLUM;
		case C_LIGHTBLUE: 
			if (draw_fill == "draw") DrawColor_s = "LIGHTBLUE";
			else FillColor_s = "LIGHTBLUE";
			return LIGHTBLUE;
		case C_WHITE:
			if (draw_fill == "draw") DrawColor_s = "WHITE";
			else FillColor_s = "WHITE";
			return WHITE;
		case C_BLACK: 
			if (draw_fill == "draw") DrawColor_s = "BLACK";
			else FillColor_s = "BLACK";
			return BLACK;


		default: return ROYALBLUE;	//for testing purposes
		}
	}
	else 
	{
		return SEAGREEN; 
		if (draw_fill == "draw") DrawColor_s = "SEAGREEN";
		else FillColor_s = "SEAGREEN";
	}
}


void GUI::switchToDraw()
{
	InterfaceMode = MODE_DRAW;
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, height);
	CreateDrawToolBar();
	CreateStatusBar();
}

bool GUI::SaveOrExit()
{
	string answer = GetSrting();
	while (answer != "y" && answer != "n")
	{
		answer = GetSrting();
	}
	if (answer == "y") return true;
	else return false;
}
//test switch function ---> need to make an op class instead??

//void GUI::switchToPlay()
//{
//	InterfaceMode = MODE_PLAY;
//	pWind->SetPen(BkGrndColor, 1);
//	pWind->SetBrush(BkGrndColor);
//	pWind->DrawRectangle(0, 0, width, height);
//	CreatePlayToolBar();
//	CreateStatusBar();
//}
//
//void GUI::changePenColor(color pickedColor)
//{
//	DrawColor = pickedColor;
//}
/*
void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const {
	color DrawingClr;
	if (LineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}
void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo) const {
	color DrawingClr;
	if (TriangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void GUI::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo) const {
	color DrawingClr;
	if (CircleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	double redius, dxsq, dysq;
	dxsq = pow(P1.x - P2.x, 2);
	dysq = pow(P1.y - P2.y, 2);
	redius = pow(dxsq + dysq, 0.5);
	pWind->DrawCircle(P1.x, P1.y, redius, style);
}*/


//void GUI::changeFillColor(color pickedColor)
//{
//	FillColor = pickedColor;
//}


//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}
