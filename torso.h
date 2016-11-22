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


Fl_Input *no_of_batteries;

void create_robot_partCBT(Fl_Widget* w, void* p) { 
	win->hide();
	cout << "Name " << name->value();
	cout << "No. of batteries " << no_of_batteries->value();
	cout << "Power " << power->value();
	cout << " Speed " << speed->value();
	cout << "Part Number " << part_num->value();
	cout << "Weight " << weight->value();
	cout << "Component Cost " << cost->value();
	cout << "Description " << description->value();

	
	ofstream myfile;
	myfile.open("torso.txt", ios::app);
	myfile << "\n" << name->value() << "," << no_of_batteries->value() << "," << power->value() << "," << speed->value() << "," << part_num->value() << "," << weight->value() << "," << cost->value() << "," << description->value();
	myfile.close();

	ofstream myfile1;
	myfile1.open("catalog.txt", ios::app);
	myfile1 << "\n" << name->value() << "," << no_of_batteries->value() << "," << power->value() << "," << speed->value() << "," << part_num->value() << "," << weight->value() << "," << cost->value() << "," << description->value();
	myfile1.close();
}

void torso()
{

	win = new Fl_Window{ 480,430, "Torso" };

	name = new Fl_Input(150, 40, 210, 25, "Name");
	name->align(FL_ALIGN_LEFT);

	no_of_batteries = new Fl_Input(150, 70, 210, 25, "Num of Batteries(1-3)");
	name->align(FL_ALIGN_LEFT);

	power = new Fl_Input(150, 100, 210, 25, "Power");
	power->align(FL_ALIGN_LEFT);

	speed = new Fl_Input(150, 140, 210, 25, "Max Speed(Mph)");
	speed->align(FL_ALIGN_LEFT);

	part_num = new Fl_Input(150, 180, 210, 25, "Part Number");
	part_num->align(FL_ALIGN_LEFT);

	weight = new Fl_Input(150, 220, 210, 25, "Weight");
	weight->align(FL_ALIGN_LEFT);

	cost = new Fl_Input(150, 260, 210, 25, "Component Cost");
	cost->align(FL_ALIGN_LEFT);

	description = new Fl_Input(150, 300, 210, 25, "Description");
	description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(180, 340, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)create_robot_partCBT, 0);

	win->show(); 
	Fl::run();
}
