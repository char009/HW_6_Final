#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Display.H>
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "imp.h"
#include "sales_associate.h"

void show_orders() 
{
	win = new Fl_Window(640, 400);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 45, 620 - 20, 360 - 20, "All Orders\n\tOrder Num, Robot, Quantity, Price");
	disp->buffer(buff);
	win->resizable(*disp);
	
	string line, display_line = "";
	ifstream myfile("All Customer Records.txt");
	int i = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			line = std::to_string(i) + ". " + line;
			line += "\n";
			cout << line;
			display_line += line;
			
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	const char *line1 = display_line.c_str();
	
	buff->text(line1);

	win->show();
	Fl::run();
}