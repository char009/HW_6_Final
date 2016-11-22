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
#include "print_robot_cat.h"
#include "robot_quant.h"
#include "all_orders.h"

void My_Callback8(Fl_Widget*w, void* userdata)
{
	//Print Robot Catalog
	print_robot_cata();
}
void My_Callback9(Fl_Widget*w, void* userdata)
{
	// Buy Robot and Quantity
	robot_quantity();
}
void My_Callback10(Fl_Widget*w, void* userdata)
{
	// Show all orders
	show_orders();
}

void create_robot_partCB(Fl_Widget* w, void* p) {
	win->hide();

	if (!(strcmp(rp_user->value(), "SA100") == 0 && strcmp(rp_pass->value(), "char009") == 0))
		return;

	win = new Fl_Window{ 600, 400, "SA Shop Manager" };
	Fl_Button button1(50, 50, 200, 30, "Print Robot Catalog");
	Fl_Button button2(50, 100, 200, 30, "Buy Robot and Quantity");
	Fl_Button button3(50, 150, 200, 30, "Show all orders");

	button1.callback(My_Callback8);
	button2.callback(My_Callback9);
	button3.callback(My_Callback10);

	win->show(); 
	Fl::run();
}

void sa()
{
	
	win = new Fl_Window{ 600, 400, "SA Login Shop Manager" };
	rp_user = new Fl_Input(90, 40, 210, 25, "User Name");
	rp_user->align(FL_ALIGN_LEFT);
	rp_pass = new Fl_Input(90, 70, 210, 25, "Password");
	rp_pass->align(FL_ALIGN_LEFT);

	Fl_Return_Button *rp_login;
	rp_login = new Fl_Return_Button(100, 100, 120, 25, "Login");
	rp_login->callback((Fl_Callback *)create_robot_partCB, 0);

	
	win->show();
	Fl::run();
}