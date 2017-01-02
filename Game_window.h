// Game_window (Declarations)
// Author: Keith Phillips
// Date: 11/7/2016

/*
	This file contains the declarations for the
	Game_window struct that constructs the main GUI
	that allows the user to play the game outlined
	by the project instructions.
*/

// Guards ===============================================================
#ifndef _GAMEWINDOW_HEADER_INCLUDED_
#define _GAMEWINDOW_HEADER_INCLUDED_

// Header files =========================================================
#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "File_Mgmt.h"
#include "Classes.h"

using namespace Graph_lib;

// Struct ===============================================================

enum class Difficulty{d_3x3,d_4x4,d_5x5};

struct Game_window : Graph_lib::Window {

	// Constructors
	Game_window(Point xy,
				int w,
				int h,
				const string& title,
				vector<Player> p,
				map<char, vector<string>> d);


private:
	// DATA MEMBERS
	vector<Player> players;
	map<char, vector<string>> dictionary;

	Difficulty dif;
	vector<Tile*> tile_grid;
	int cur_player_idx;
	int score = 0;
	string cur_word;
	vector<Fl_Widget*> used_tiles;
	vector<string> v_used_words;
	string used_words_buffer;
	Player* dummy_player = new Player();
	Lines scores_div;

	// UTILITY FUNCTIONS
	void add_player(Player p) {players.push_back(p);}
	bool in_dict(string s); //returns true if s is in dictionary
	vector<Player*> get_leaderboard(); //return vector of pointers to players with highest 3x3, 4x4, and 5x5 scores, in that order
	void fill_tile_grid(int n); //fills tile_grid with nxn tiles
	Tile* match_widget_tile(void* fltk_address);
	bool is_contiguous(Tile* tile_1, Tile* tile_2);

	// FUNCTIONS
	void hide_all();
	void show_profile_screen();
	void show_new_user_screen();
	void show_existing_user_screen();
	void show_main_menu_screen();
	void show_game_screen();
	void show_end_game_screen();
	void show_high_scores_screen();
	void show_grid();
	void hide_grid();
	void attach_grid();
	void detach_grid();
	void clear_grid();

	// WIDGETS
	// Profile ----------------------------
	Button new_profile;
	Button existing_profile;
	Button back_profile;
	// New User ---------------------------
	In_box new_name;
	In_box new_picture;
	Button enter_new_user;
	Text blank_fields;
	Text duplicate_user;
	// Existing User ----------------------
	In_box existing_name;
	Button enter_existing_user;
	Text user_not_found;
	// Main Menu --------------------------
	Text main_title;
	Button new_3x3;
	Button new_4x4;
	Button new_5x5;
	Button change_profile;
	Text cur_profile;
	Button main_show_scores;
	Button quit;
	// Game -------------------------------
	Out_box new_word;
	Button backspace;
	Button enter_word;
	Button finish_game;
	Text current_score;
	Out_box used_words;
	Button game_show_scores;
	Text duplicate_word;
	Text error_word;
	// End Game ---------------------------
	Text final_score;
	Button replay;
	Button new_game;
	// High Scores ------------------------
	Text lbl_high_scores;
	Text lbl_3x3;
	Image* img_3x3;
	Text name_3x3;
	Text score_3x3;
	Text lbl_4x4;
	Image* img_4x4;
	Text name_4x4;
	Text score_4x4;
	Text lbl_5x5;
	Image* img_5x5;
	Text name_5x5;
	Text score_5x5;
	Button return_main;
	Button return_game;


	// CALLBACK ACTIONS
	// Profile ----------------------------
	void new_profile_pressed();
	void existing_profile_pressed();
	void back_profile_pressed();
	// New User ---------------------------
	void enter_new_user_pressed();
	// Existing User ----------------------
	void enter_existing_user_pressed();
	// Main Menu --------------------------
	void new_3x3_pressed();
	void new_4x4_pressed();
	void new_5x5_pressed();
	void change_profile_pressed();
	void main_show_scores_pressed();
	void quit_pressed();
	// Game -------------------------------
	void tile_pressed(string l, Address t);
	void backspace_pressed();
	void enter_word_pressed();
	void finish_game_pressed();
	void game_show_scores_pressed();
	// End Game ---------------------------
	void replay_pressed();
	void new_game_pressed();
	// High Scores ------------------------
	void return_main_pressed();
	void return_game_pressed();


	// CALLBACK FUNCTIONS
	// Profile ----------------------------
	static void cb_new_profile(Address, Address);
	static void cb_existing_profile(Address, Address);
	static void cb_back_profile(Address, Address);
	// New User ---------------------------
	static void cb_enter_new_user(Address, Address);
	// Existing User ----------------------
	static void cb_enter_existing_user(Address, Address);
	// Main Menu --------------------------
	static void cb_new_3x3(Address, Address);
	static void cb_new_4x4(Address, Address);
	static void cb_new_5x5(Address, Address);
	static void cb_change_profile(Address, Address);
	static void cb_main_show_scores(Address, Address);
	static void cb_quit(Address, Address);
	// Game -------------------------------
	static void cb_tile(Address, Address);
	static void cb_backspace(Address, Address);
	static void cb_enter_word(Address, Address);
	static void cb_finish_game(Address, Address);
	static void cb_game_show_scores(Address, Address);
	// End Game ---------------------------
	static void cb_replay(Address, Address);
	static void cb_new_game(Address, Address);
	// High Scores ------------------------
	static void cb_return_main(Address, Address);
	static void cb_return_game(Address, Address);

};

#endif // _GAMEWINDOW_HEADER_INCLUDER_