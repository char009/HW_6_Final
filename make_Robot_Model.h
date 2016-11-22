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

Fl_Input *number_of_models, *model_num;
Fl_Input *Loco, *Head, *Torso, *Arm, *Battery;

void create_robot_model(Fl_Widget* w, void* p) { 
	win->hide();

	cout << "Locomotor Choice " << Loco->value();
	cout << "\nBattery Choice " << Battery->value();
	cout << "\nArm Choice " << Arm->value();
	cout << "\nHead Choice " << Head->value();
	cout << "\nTorso Choice " << Torso->value();
	cout << "\nModel Name " << name->value();
	cout << "\nNo. of models saved " << number_of_models->value();
	cout << "\nModel Number " << model_num->value();
	cout << "\nWeight " << weight->value();
	cout << "\nPrice " << cost->value();
	cout << "\nDescription " << description->value();

	ofstream myfile1;
	myfile1.open("robotcatalog.txt", ios::app);
	myfile1 << "\n" << name->value() << "," << model_num->value() << "," << cost->value() << "," << number_of_models->value() << "," << weight->value() << "," << cost->value() << "," << description->value() << "," << Loco->value() << "," << Arm->value() << "," << Battery->value() << "," << Torso->value() << "," << Head->value();
	myfile1.close();

	win->show(); 

}


void make_Robot_Model()
{
	win = new Fl_Window(700, 800);
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 680 - 10, 230 - 10, "Robot Components Catalog");
	disp->buffer(buff);
	win->resizable(*disp);

	string line, display_line = "";
	ifstream myfile("catalog.txt");
	int i = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			line = std::to_string(i) + ". " + line;
			line += "\n";
			display_line += line;
			
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	const char *line1 = display_line.c_str();
	buff->text(line1);

	name = new Fl_Input(130, 270, 210, 25, " Model Name");
	name->align(FL_ALIGN_LEFT);

	number_of_models = new Fl_Input(130, 310, 210, 25, "No. of Models Sold");
	number_of_models->align(FL_ALIGN_LEFT);

	model_num = new Fl_Input(130, 350, 210, 25, "Model Number");
	model_num->align(FL_ALIGN_LEFT);

	weight = new Fl_Input(130, 390, 210, 25, "Model Weight");
	weight->align(FL_ALIGN_LEFT);

	cost = new Fl_Input(130, 430, 210, 25, "Model Price");
	cost->align(FL_ALIGN_LEFT);

	Loco = new Fl_Input(130, 470, 210, 25, "Locomotor Name: ");
	Loco->align(FL_ALIGN_LEFT);

	Head = new Fl_Input(130, 510, 210, 25, "Head Name: ");
	Head->align(FL_ALIGN_LEFT);

	Torso = new Fl_Input(130, 550, 210, 25, "Torso Name: ");
	Torso->align(FL_ALIGN_LEFT);

	Battery = new Fl_Input(130, 590, 210, 25, "Battery Name: ");
	Battery->align(FL_ALIGN_LEFT);

	Arm = new Fl_Input(130, 630, 210, 25, "Arm Name: ");
	Torso->align(FL_ALIGN_LEFT);

	description = new Fl_Input(130, 670, 210, 25, "Description");
	description->align(FL_ALIGN_LEFT);

	Fl_Return_Button *rp_confirm;
	rp_confirm = new Fl_Return_Button(150, 710, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)create_robot_model, 0);

	win->show();
	Fl::run();
}
