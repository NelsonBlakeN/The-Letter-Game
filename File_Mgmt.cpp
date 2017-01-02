#include "File_Mgmt.h"
#include <map>
#include <algorithm>
#include "Classes.h"

using namespace std;

// Organizes the dictionary into a more manageable
// storage design by using the map data structure.
// This function creates a map using the first letter
// of the word - a char - as the key, and a string
// vector containing all the words beginning with that
// letter as the value.
map<char, vector<string> > make_dict() {
    map<char, vector<string> > dictionary;      // Final dictionary map
    ifstream ifs("dictionary.txt");             // Dictionary file
    string word;                                // Word to add to map vector

    while(!ifs.eof()) {     // While we have not reached the end of the file...
        ifs >> word;
        char first_letter = word.at(0);

        // Check if the first letter is already a key in the dictionary map
        if(dictionary.find(first_letter) == dictionary.end()) {
            // Key does not presently exist, create new pair
            vector<string> alpha_words;
            alpha_words.push_back(word);
            dictionary.insert(make_pair(first_letter, alpha_words));
        }
        else {
            // Key does presently exist, add word to existing vector
            dictionary[first_letter].push_back(word);
        }
    }
    return dictionary; // Return complete dictionary
}

void output_data(const vector<Player>& players) {
    ofstream ofs("player_data.txt");
    for(auto p : players) {
        ofs << p;
    }
}

void skip_whitespace(istream& is)
{
    /*
        This function skips to the next character in a stream

        Inputs: N/A
        Outputs: N/A
    */

    for (char ch; is.get(ch);) {
        if (isspace(ch)) {
        }
        else if (ch == '\r') {
        }
        else {
            is.unget();
            return;
        }
    }
}

vector<int> get_ints(istream& is)
{
    /*
        This function picks out a line of ints from an
        input stream and converts them to a vector
        of ints.

        Inputs: is - stream to pick line of ints out of
        Outputs: - Vector of ints
    */

    vector<int> vec_ints;

    // Get input from stream
    string str_num;
    skip_whitespace(is);
    getline(is,str_num);

    istringstream iss {str_num};
    int int_num = 0;

    while(true) {
        iss >> int_num;

        if(!iss) {
            break;
        }

        if(int_num == -1){
            return vec_ints;
        }

        vec_ints.push_back(int_num);
    }

    sort(vec_ints.begin(), vec_ints.end());
    reverse(vec_ints.begin(), vec_ints.end());

    return vec_ints;
}

void input_data(vector<Player>& players) {
    /*
        Reads data from the established data text file,
        and creates Player objects that are saved to the
        given vector. These are used to determine high
        scores and previous users.

        Inputs: Vector of players
        Outputs: N/A
    */
    ifstream ifs("player_data.txt");
    if(!ifs) return;
    string name, pic_url;
    vector<int> scores_3x3, scores_4x4, scores_5x5;
    while(!ifs.eof()) {
        //First line: name
        ifs >> name;

        if(name.size() == 0){
            return;
        }
        //Second line: (local) path to picture
        ifs >> pic_url;

        //Next 3 lines: list of scores per difficulty
        scores_3x3 = get_ints(ifs);
        scores_4x4 = get_ints(ifs);
        scores_5x5 = get_ints(ifs);

        players.push_back(Player(name, pic_url, scores_3x3, scores_4x4, scores_5x5));

        skip_whitespace(ifs);
    }
}