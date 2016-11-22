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

using namespace std;
Fl_Input *model_choice, *quantity;

string file_name;

void choose_model(Fl_Widget* w, void* p) { 
	win->hide();
	double price = (3000 + (std::rand() % (6500 - 3000 + 1))) / 3; 
	int order_num = 0;
	string order_num_str;


	ifstream myfile3("Order Number.txt");
	if (myfile3.is_open())
	{
		while (getline(myfile3, order_num_str))
		{
			stringstream convert(order_num_str);
			convert >> order_num;

		}
	}
	order_num++;
	myfile3.close();

	ofstream myfile4;
	myfile4.open("Order Number.txt");
	stringstream ss;
	ss << order_num;
	myfile4 << ss.str();
	myfile4.close();


	cout << "Customer Name" << name->value();
	cout << "Model Name " << model_choice->value();
	cout << "Model Quantity " << quantity->value();
	cout << " Price " << price;
	cout << "Order Number " << order_num_str;

	stringstream ss2;

	ss2 << price;

	ofstream myfile1, myfile2;
	myfile1.open(file_name, ios::app);
	myfile2.open("All customer Records.txt", ios::app);
	myfile1 << order_num_str + "," + model_choice->value() + "," + quantity->value() + "," + ss2.str();
	myfile2 << order_num_str + "," + model_choice->value() + "," + quantity->value() + "," + ss2.str() + "\n";
	myfile1.close();
	myfile2.close();


}

void choose_name1(Fl_Widget* w, void* p) {
	win->hide();

	file_name = name->value();
	file_name += ".txt";

	ofstream myfile1;
	myfile1.open(file_name, ios::app);
	myfile1 << "";
	myfile1.close();

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


	win->end();
	win->show(); 
}

void robot_quantity()
{
	win = new Fl_Window(800, 700);
	name = new Fl_Input(150, 20, 210, 25, "Customer's Full Name"); 

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(150, 50, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)choose_name1, 0);

	buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 100, 800 - 40, 250, "Buy Robot");
	disp->buffer(buff);
	win->resizable(*disp);

	model_choice = new Fl_Input(160, 400, 210, 25, "Robot Model Name"); 
	quantity = new Fl_Input(160, 430, 210, 25, "Quantity"); 


	Fl_Return_Button *rp_confirm1;
	rp_confirm1 = new Fl_Return_Button(160, 470, 120, 25, "Confirm");
	rp_confirm1->callback((Fl_Callback *)choose_model, 0);


	win->show();
	Fl::run();
}