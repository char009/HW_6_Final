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


void create_robot_partCBH(Fl_Widget* w, void* p) { 
	win->hide();
	cout << "Name " << name->value();
	cout << "Part Number " << part_num->value();
	cout << "Weight " << weight->value();
	cout << "Component Cost " << cost->value();
	cout << "Description " << description->value();


	ofstream myfile;
	myfile.open("head.txt", ios::app);
	myfile << "\n" << name->value() << "," << part_num->value() << "," << weight->value() << "," << cost->value() << "," << description->value();
	myfile.close();

	ofstream myfile1;
	myfile1.open("catalog.txt", ios::app);
	myfile1 << "\n" << name->value() << "," << part_num->value() << "," << weight->value() << "," << cost->value() << "," << description->value();
	myfile1.close();


}

void head()
{

	win = new Fl_Window{ 420,320, "Head" };

	name = new Fl_Input(130, 40, 210, 25, "Name");
	name->align(FL_ALIGN_LEFT);

	part_num = new Fl_Input(130, 80, 210, 25, "Part Number");
	part_num->align(FL_ALIGN_LEFT);

	weight = new Fl_Input(130, 120, 210, 25, "Weight");
	weight->align(FL_ALIGN_LEFT);

	cost = new Fl_Input(130, 160, 210, 25, "Component Cost");
	cost->align(FL_ALIGN_LEFT);

	description = new Fl_Input(130, 200, 210, 25, "Description");
	description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(150, 240, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)create_robot_partCBH, 0);

	win->show();
	Fl::run();
}
