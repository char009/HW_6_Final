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
#include "locomotor.h"
#include "arm.h"
#include "battery.h"
#include "head.h"
#include "torso.h"
#include "make_Robot_Model.h"
#include "print_comp_cat.h"
#include "print_robot_cat.h"


void My_Callback11(Fl_Widget*w, void* userdata)
{
	// LOCOMOTOR
	
	loc();

}
void My_Callback12(Fl_Widget*w, void* userdata)
{
	//ARM
	arm();
}
void My_Callback13(Fl_Widget*w, void* userdata)
{
	battery();
	// BATTERY
}
void My_Callback14(Fl_Widget*w, void* userdata)
{
	torso();
	// TORSO
}
void My_Callback15(Fl_Widget*w, void* userdata)
{
	// HEAD
	head();

}
void My_Callback4(Fl_Widget*w, void* userdata)
{
	//Make Robot Components"
	win->hide();

	win = new Fl_Window{ 600, 400, "Make Robot Components" };
	Fl_Button button1(50, 50, 200, 30, "LOCOMOTOR");
	Fl_Button button2(50, 100, 200, 30, "ARM");
	Fl_Button button3(50, 150, 200, 30, "BATTERY");
	Fl_Button button4(50, 200, 200, 30, "TORSO");
	Fl_Button button5(50, 250, 200, 30, "HEAD");


	button1.callback(My_Callback11);
	button2.callback(My_Callback12);
	button3.callback(My_Callback13);
	button4.callback(My_Callback14);
	button5.callback(My_Callback15);

	win->show();
	
	Fl::run();
}

void My_Callback5(Fl_Widget*w, void* userdata)
{
	// Make Robot Models
	make_Robot_Model();

}
void My_Callback6(Fl_Widget*w, void* userdata)
{
	// Print Component Catalog
	print_comp_cata();
}

void My_Callback7(Fl_Widget*w, void* userdata)
{
	// "Print Robot Catalog
	print_robot_cata();
}



void create_robot_partCBPM(Fl_Widget* w, void* p) { 
	win->hide();

	
		//return ;
	cout << rp_user->value() <<"   "<<rp_pass->value();

	if (!(strcmp(rp_user->value(), "PMRRS") == 0 && strcmp(rp_pass->value(), "char009") == 0))
		return;

	win = new Fl_Window{ 600, 400, "PM Shop Manager" };

	Fl_Button button1(50, 50, 200, 30, "Make Robot Components");
	Fl_Button button2(50, 100, 200, 30, "Make Robot Models");
	Fl_Button button3(50, 150, 200, 30, "Print Component Catalog");
	Fl_Button button4(50, 200, 200, 30, "Print Robot Catalog");

	button1.callback(My_Callback4);
	button2.callback(My_Callback5);
	button3.callback(My_Callback6);
	button4.callback(My_Callback7);

	win->show(); // hide this
	Fl::run();
}

void pm()
{	
	
	win = new Fl_Window{ 600, 400, "PM Login Shop Manager" };
	rp_user = new Fl_Input(90, 40, 210, 25, "User Name");
	rp_user->align(FL_ALIGN_LEFT);
	rp_pass = new Fl_Input(90, 70, 210, 25, "Password");
	rp_pass->align(FL_ALIGN_LEFT);

	Fl_Return_Button *rp_login;
	rp_login = new Fl_Return_Button(100, 100, 120, 25, "Login");
	 
	rp_login->callback((Fl_Callback *)create_robot_partCBPM, 0);
	
	

	win->show();
	Fl::run();
}