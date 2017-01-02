// Guards ===============================================================
#ifndef _CLASSES_HEADER_INCLUDED_
#define _CLASSES_HEADER_INCLUDED_


// Header file ==========================================================
// #include <iostream>
// #include <string>
// #include <vector>
#include "GUI.h"
#include "Window.h"
#include "Graph.h"

using namespace Graph_lib;
using namespace std;

class Player {
    /*
        The object that contains all the data relevant to
        a Player, including a vector of scores for each
        level the user has played, the name of the user,
        and the ame of their corresponding picture.
        This object also contains the necessary functions,
        such as returning these data members, as well as
        adding new scores and outputting all the saved information.
    */
private:
    string name;
    vector<int> scores_3x3;
    vector<int> scores_4x4;
    vector<int> scores_5x5;
    string pict_url;

public:
    Player(string n, string p, vector<int> s3, vector<int> s4, vector<int> s5) : name(n), pict_url(p),
                                                                                 scores_3x3(s3),
                                                                                 scores_4x4(s4),
                                                                                 scores_5x5(s5)
    {}

    Player() {
        name = "No Scores";
        pict_url = "";
        scores_3x3 = {0};
        scores_4x4 = {0};
        scores_5x5 = {0};
    }
    string get_name() const { return name; }
    string get_picture() const { return pict_url; }
    const vector<int>& get_scores_3x3() const { return scores_3x3; }
    const vector<int>& get_scores_4x4() const { return scores_4x4; }
    const vector<int>& get_scores_5x5() const { return scores_5x5; }

    void add_score_3x3(int new_score)
    {
        for(int i=0;i<scores_3x3.size();++i)
        {
            if(new_score>=scores_3x3[i])
            {
                scores_3x3.insert(scores_3x3.begin()+i,new_score);
                return;
            }
        }
        scores_3x3.insert(scores_3x3.end(),new_score);
    }

    void add_score_4x4(int new_score)
    {
        for(int i=0;i<scores_4x4.size();++i)
        {
            if(new_score>=scores_4x4[i])
            {
                scores_4x4.insert(scores_4x4.begin()+i,new_score);
                return;
            }
        }
        scores_4x4.insert(scores_4x4.end(),new_score);
    }

    void add_score_5x5(int new_score)
    {
        for(int i=0;i<scores_5x5.size();++i)
        {
            if(new_score>=scores_5x5[i])
            {
                scores_5x5.insert(scores_5x5.begin()+i,new_score);
                return;
            }
        }
        scores_5x5.insert(scores_5x5.end(),new_score);
    }
};

inline string scores_to_string(vector<int> scores) {
    string score_string = "";
    if(scores.size() > 0) {
        score_string += to_string(scores[0]);
        for(int i = 1; i < scores.size(); ++i) {
            score_string += (" "  + to_string(scores[i]));
        }
    }
    else
        cout << "Scores vector is empty." << endl;
    return score_string;
}

inline ostream& operator<<(ostream& os, const Player& p) {
    os << p.get_name() << endl
       << p.get_picture() << endl;

    if (p.get_scores_3x3().size() == 0){
    	os << -1 << endl;
    }
    else {
    	os << scores_to_string(p.get_scores_3x3()) << endl;
    }

    if (p.get_scores_4x4().size() == 0){
    	os << -1 << endl;
    }
    else {
    	os << scores_to_string(p.get_scores_4x4()) << endl;
    }

    if (p.get_scores_5x5().size() == 0){
    	os << -1 << endl;
    }
    else {
    	os << scores_to_string(p.get_scores_5x5()) << endl;
    }

}

struct Tile : Button {
    /*
        The object that contains relevant information to the
        Tiles on the game grid.
        This object extends the previous button class, but also
        contains a position and a letter.
    */
    Tile(Point xy, int w, int h, Callback cb, string l, int x, int y)
        : Button(xy, w, h, l, cb), letter(l), pos_x(x), pos_y(y) { }


    void get_letter(string &l) { l = letter; }
    void* get_fltk_address(){return pw;}
    int get_pos_x() {return pos_x;}
    int get_pos_y() {return pos_y;}

    private:
        string letter;
        int pos_x;
        int pos_y;
};

#endif // _TEST_HEADER_INCLUDED_