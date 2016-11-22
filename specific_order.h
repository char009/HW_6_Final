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

Fl_Text_Buffer *buff;

void choose_name(Fl_Widget* w, void* p) {
	win->hide();

	cout << "Name Choice " << choice->value();
	string file_name = choice->value();
	file_name += ".txt";

	string line, display_line = "";
	ifstream myfile(file_name); 
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




	win->end();
	win->show(); 

				 // choose that locomotor according to value of locomotor choice
}

void specific_order()
{
	win = new Fl_Window(700, 700);
	choice = new Fl_Input(150, 20, 210, 25, "Customer's Full Name"); 

	Fl_Return_Button *rp_confirm;
	rp_confirm = new Fl_Return_Button(150, 50, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)choose_name, 0);

	buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 100, 640 - 40, 250 - 40, "Customer Record");
	disp->buffer(buff);
	win->resizable(*disp);
	win->show();
	Fl::run();
}