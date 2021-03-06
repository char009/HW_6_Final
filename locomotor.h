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


Fl_Input *choice;
Fl_Input *name, *power, *speed, *part_num, *weight, *cost, *description;

void create_robot_partCBL(Fl_Widget* w, void* p) { 
	win->hide();
	cout << "Name " << name->value();
	cout << "Power " << power->value();
	cout << " Speed " << speed->value();
	cout << "Part Number " << part_num->value();
	cout << "Weight " << weight->value();
	cout << "Component Cost " << cost->value();
	cout << "Description " << description->value();



	ofstream myfile;
	myfile.open("locomotor.txt", ios::app);
	myfile << "\n" << name->value() << "," << power->value() << "," << speed->value() << "," << part_num->value() << "," << weight->value() << "," << cost->value() << "," << description->value();
	myfile.close();

	ofstream myfile1;
	myfile1.open("catalog.txt", ios::app);
	myfile1 << "\n" << name->value() << "," << power->value() << "," << speed->value() << "," << part_num->value() << "," << weight->value() << "," << cost->value() << "," << description->value();
	myfile1.close();

}

void choose_locomotor(Fl_Widget* w, void* p) {
	win->hide();

	cout << "Locomotor Choice " << choice->value();

	win->show();

			
}


void loc()
{
	win = new Fl_Window{ 600, 400, "Locomotor" };

	name = new Fl_Input(130, 40, 210, 25, "Name");
	name->align(FL_ALIGN_LEFT);

	power = new Fl_Input(130, 70, 210, 25, "Power");
	power->align(FL_ALIGN_LEFT);

	speed = new Fl_Input(130, 100, 210, 25, "Max Speed(Mph)");
	speed->align(FL_ALIGN_LEFT);

	part_num = new Fl_Input(130, 140, 210, 25, "Part Number");
	part_num->align(FL_ALIGN_LEFT);

	weight = new Fl_Input(130, 180, 210, 25, "Weight");
	weight->align(FL_ALIGN_LEFT);

	cost = new Fl_Input(130, 220, 210, 25, "Component Cost");
	cost->align(FL_ALIGN_LEFT);

	description = new Fl_Input(130, 260, 210, 25, "Description");
	description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)create_robot_partCBL, 0);
	
	win->show(); 
	Fl::run();
}