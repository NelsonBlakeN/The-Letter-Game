// Homework 08 Problem 01: Main
// Author: Keith Phillips
// Date: 10/22/2016

/*
	
*/

#include "std_lib_facilities_4.h"
#include "Main_Test.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;

int main()
{
	try {
		// Create Dictionary
		map<char, vector<string>> dict;
		dict = make_dict();

		// File Input/Output
		vector<Player> players;
		input_data(players);

		// Contruct the GUI window
		Game_window win(Point(100,100),600,400,"Letter Game", players, dict);
		return gui_main();
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << "\n";
		return 1;
	}
	catch (...) {
		cerr << "some exception\n";
		return 2;
	}
};
