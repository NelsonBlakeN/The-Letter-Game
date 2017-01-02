// Guards ===============================================================
#ifndef _FILEMGMT_HEADER_INCLUDED_
#define _FILEMGMT_HEADER_INCLUDED_

// Header file ==========================================================
// #include <iostream>
// #include <fstream>
// #include <vector>
#include <map>
// #include <string>
#include "Classes.h"

using namespace std;

// Organizes the dictionary into a more manageable
// storage design by using the map data structure.
// This function creates a map using the first letter
// of the word - a char - as the key, and a string
// vector containing all the words beginning with that
// letter as the value.

/*
    Creates the dictionary object, which is a map indexed
    by the first character of the word, and who's value
    is a vector of strings from the dictionary file that
    begin with the corresponding letter.

    Inputs: N/A
    Outputs: N/A
*/
map<char, vector<string> > make_dict();

/*
    Saves the data about each player to an output file

    Inputs: Vector of Player objects
    Outputs: N/A
*/
void output_data(const vector<Player>& players);

/*
    This function skips to the next character in a stream

    Inputs: N/A
    Outputs: N/A
*/
void skip_whitespace(istream& is);

/*
    This function picks out a line of ints from an
    input stream and converts them to a vector
    of ints.

    Inputs: is - stream to pick line of ints out of
    Outputs: - Vector of ints
*/
vector<int> get_ints(istream& is);

/*
    Reads data from the established data text file,
    and creates Player objects that are saved to the
    given vector. These are used to determine high
    scores and previous users.

    Inputs: Vector of players
    Outputs: N/A
*/
void input_data(vector<Player>& players);

#endif