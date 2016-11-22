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
#include "imp.h"
#include "print_robot_cat.h"
#include "specific_order.h"

void My_Callback16(Fl_Widget*w, void* userdata)
{

	print_robot_cata();
}

void My_Callback17(Fl_Widget*w, void* userdata)
{

	specific_order();
}

void cm()
{
	win = new Fl_Window{ 600, 400, "Customer Shop Manager" };

	Fl_Button button5(50, 50, 200, 30, "Print Robot Catolog");
	Fl_Button button6(50, 100, 200, 30, "See Specific Order");

	button5.callback(My_Callback16);
	button6.callback(My_Callback17);

	win->show();
	Fl::run();
}