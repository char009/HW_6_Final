#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "imp.h"
#include "product_manager.h"

void print_robot_cata()
{
	win = new Fl_Window(640, 400);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 20, 400 - 20, "Robot Catalog");
	disp->buffer(buff);
	win->resizable(*disp);

	string line, display_line = "";
	ifstream myfile("robotcatalog.txt");
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