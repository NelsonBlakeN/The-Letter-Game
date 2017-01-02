// Game_window(Implementation)
// Author: Keith Phillips
// Date:11/7/2016

/*
	This file contains the implementation of the
	Game_window struct that constructs the main GUI
	that allows the user to play the game outlined
	by the project instructions.
*/

#include "Game_window.h"
#include <FL/Fl_Button.H>

// CONSTRUCTORS =========================================================
//-----------------------------------------------------------------------

Game_window::Game_window(Point xy, int w, int h, const string& title, vector<Player> p, map<char, vector<string>> d) :

	// Initializes window
	Window(xy, w, h, title),

	// DATA MEMBERS
	players(p),
	dictionary(d),

	// WIDGETS
	// Profile ----------------------------
		// New Profile
		new_profile(
			Point(x_max()-450,190),
			100,20,
			"New Profile",
			cb_new_profile),
		// Existing Profile
		existing_profile(
			Point(x_max()-252,190),
			100,20,
			"Existing Profile",
			cb_existing_profile),
		// Back Profile
		back_profile(
			Point(x_max()-80, y_max()-30),
			70,20,
			"Back",
			cb_back_profile),
	// New User ---------------------------
		// New Name
		new_name(
			Point(x_max()-375,130),
			150,20,
			"Name: "),
		// New Picture
		new_picture(
			Point(x_max()-375,150),
			150,20,
			"Picture: "),
		// Enter new user
		enter_new_user(
			Point(x_max()-375,190),
			150,20,
			"Enter new user",
			cb_enter_new_user),
		// Blank fields error
		blank_fields(
			Point(x_max()-375,185),
			"Some fields are blank"),
		// Duplicate user error
		duplicate_user(
			Point(x_max()-375,185),
			"Duplicate user"),
	// Existing User ----------------------
		// Existing name
		existing_name(
			Point(x_max()-375,155),
			150,20,
			"Name: "),
		// Enter existing user
		enter_existing_user(
			Point(x_max()-375, 195),
			150,20,
			"Enter existing user",
			cb_enter_existing_user),
		// User not found error
		user_not_found(
			Point(x_max()-375,190),
			"User not found"),
	// Main Menu --------------------------
		// Main Title
		main_title(
			Point(120,140),
			"The Letter Game"),
		// New 3x3
		new_3x3(
			Point(x_max()-410,180),
			60,40,
			"3x3",
			cb_new_3x3),
		// New 4x4
		new_4x4(
			Point(x_max()-330,180),
			60,40,
			"4x4",
			cb_new_4x4),
		// New 5x5
		new_5x5(
			Point(x_max()-250,180),
			60,40,
			"5x5",
			cb_new_5x5),
		// Change Profiles
		change_profile(
			Point(10,y_max()-30),
			70,20,
			"Profile",
			cb_change_profile),
		// Current Profile
		cur_profile(
			Point(10,y_max() - 35),
			""),
		// Show Scores
		main_show_scores(
			Point(x_max()-80,y_max()-30),
			70,20,
			"Scores",
			cb_main_show_scores),
		// Quit
		quit(
			Point(x_max()-80,10),
			70,20,
			"Quit",
			cb_quit),
	// Game -------------------------------
		// New Word
		new_word(
			Point(10,y_max()-120),
			150,20,
			""),
		// Backspace
		backspace(
			Point(170, y_max()-120),
			150, 20,
			"Backspace",
			cb_backspace),
		// Enter Word
		enter_word(
			Point(10,y_max()-90),
			150,20,
			"Enter Word",
			cb_enter_word),
		// Finish Game
		finish_game(
			Point(10,y_max()-60),
			150,20,
			"Finish Game",
			cb_finish_game),
		// Current Score
		current_score(
			Point(10,y_max()-10),
			"Current Score: 0"),
		// Used Words
		used_words(
			Point(x_max()-210, 10),
			200,350,
			""),
		// Show scores
		game_show_scores(
			Point(x_max()-80,y_max()-30),
			70,20,
			"Scores",
			cb_game_show_scores),
		// Duplicate word
		duplicate_word(
			Point(10,y_max()-125),
			"You already entered that word"),
		// Not a word error
		error_word(
			Point(10,y_max()-125),
			"Error: Not a word."),
	// End Game ---------------------------
		// Final Score
		final_score(
			Point(75,80),
			"Final Score:"),
		// Replay
		replay(
			Point(75,90),
			70,20,
			"Replay",
			cb_replay),
		// Main
		new_game(
			Point(75,120),
			70,20,
			"Main",
			cb_new_game),
	// High Scores ------------------------
		// High Scores Label
		lbl_high_scores(
			Point(180,47),
			"HIGH SCORES"),
		// 3x3 Label
		lbl_3x3(
			Point(82,95),
			"3x3"),
		// 3x3 Image
		img_3x3(nullptr),
		// 3x3 Name
		name_3x3(
			Point(20, 290),
			"Name: "),
		// 3x3 Score
		score_3x3(
			Point(20,320),
			"Score:"),
		// 4x4 Label
		lbl_4x4(
			Point(282,95),
			"4x4"),
		// 4x4 Image
		img_4x4(nullptr),
		// 4x4 Name
		name_4x4(
			Point(220, 290),
			"Name: "),
		// 4x4 Score
		score_4x4(
			Point(220,320),
			"Score:"),
		// 5x5 Label
		lbl_5x5(
			Point(482,95),
			"5x5"),
		// 5x5 Image
		img_5x5(nullptr),
		// 5x5 Name
		name_5x5(
			Point(420, 290),
			"Name: "),
		// 5x5 Score
		score_5x5(
			Point(420,320),
			"Score:"),
		// Return Main
		return_main(
			Point(x_max()-80, y_max()-30),
			70,20,
			"Back",
			cb_return_main),
		// Return Game
		return_game(
			Point(x_max()-80, y_max()-30),
			70,20,
			"Back",
			cb_return_game)


		// Constructor Body
		{
			// Adjust Fonts
			Graph_lib::Font fnt_times_bold(Graph_lib::Font::Font_type::times_bold);
			main_title.set_font(fnt_times_bold);

			// Adjust Font Sizes
			main_title.set_font_size(48);
			lbl_high_scores.set_font_size(36);
			lbl_3x3.set_font_size(24);
			lbl_4x4.set_font_size(24);
			lbl_5x5.set_font_size(24);
			name_3x3.set_font_size(18);
			score_3x3.set_font_size(18);
			name_4x4.set_font_size(18);
			score_4x4.set_font_size(18);
			name_5x5.set_font_size(18);
			score_5x5.set_font_size(18);

			// Create scores dividers
			scores_div.add(Point(200,60),
						   Point(200,376));
			scores_div.add(Point(400,60),
						   Point(400,376));
			scores_div.set_style(Line_style{Line_style::solid,3});

			// Attach Widgets
			attach(new_profile);
			attach(existing_profile);
			attach(back_profile);
			attach(new_name);
			attach(new_picture);
			attach(enter_new_user);
			attach(blank_fields);
			attach(duplicate_user);
			attach(existing_name);
			attach(enter_existing_user);
			attach(user_not_found);
			attach(main_title);
			attach(new_3x3);
			attach(new_4x4);
			attach(new_5x5);
			attach(change_profile);
			attach(cur_profile);
			attach(main_show_scores);
			attach(quit);
			attach(new_word);
			attach(backspace);
			attach(enter_word);
			attach(finish_game);
			attach(current_score);
			attach(used_words);
			attach(game_show_scores);
			attach(duplicate_word);
			attach(error_word);
			attach(final_score);
			attach(replay);
			attach(new_game);
			attach(lbl_high_scores);
			attach(scores_div);
			attach(lbl_3x3);
			attach(name_3x3);
			attach(score_3x3);
			attach(lbl_4x4);
			attach(name_4x4);
			attach(score_4x4);
			attach(lbl_5x5);
			attach(name_5x5);
			attach(score_5x5);
			attach(return_main);
			attach(return_game);

			this->resizable(NULL);

			// Hide all
			hide_all();

			// Show Profile screen
			show_profile_screen();

		}

//-----------------------------------------------------------------------
//=======================================================================

// FUNCTIONS (PRIVATE) ==================================================
//-----------------------------------------------------------------------

bool Game_window::in_dict(string s)
{
	/*
		This function returns true if s is
		in the dictionary

		Inputs: N/A
		Outputs: True if s is in dictionary. False otherwise
	*/

	if(dictionary.find(s.at(0)) != dictionary.end())
		for(string dict_entry : dictionary[s.at(0)])
			if(dict_entry == s)
				return true;
	return false;
}

vector<Player*> Game_window::get_leaderboard()
{
	/*
		This function returns a vector of pointers to players
		with highest 3x3,4x4, and 5x5 scores, in that order.

		Inputs: N/A
		Outputs: {3x3 leader, 4x4 leader, 5x5 leader} (pointers)
	*/


	vector<int> v_3x3_PRs;
	vector<int> v_4x4_PRs;
	vector<int> v_5x5_PRs;

	for(auto p : players)
	{
		if(p.get_scores_3x3().size()>0)
			v_3x3_PRs.push_back(p.get_scores_3x3()[0]);
		else
			v_3x3_PRs.push_back(-1);
		if(p.get_scores_4x4().size()>0)
			v_4x4_PRs.push_back(p.get_scores_4x4()[0]);
		else
			v_4x4_PRs.push_back(-1);
		if(p.get_scores_5x5().size()>0)
			v_5x5_PRs.push_back(p.get_scores_5x5()[0]);
		else
			v_5x5_PRs.push_back(-1);
	}
	
	vector<Player*> leaderboard;
	
	if(any_of(v_3x3_PRs.begin(),v_3x3_PRs.end(),[](int i){return i!=-1;}))
	{
		int i_3x3_ldr_idx = distance(v_3x3_PRs.begin(), max_element(v_3x3_PRs.begin(),v_3x3_PRs.end()));
		leaderboard.push_back(&(players[i_3x3_ldr_idx]));
	}
	else
		leaderboard.push_back(dummy_player);
	if(any_of(v_4x4_PRs.begin(),v_4x4_PRs.end(),[](int i){return i!=-1;}))
	{
		int i_4x4_ldr_idx = distance(v_4x4_PRs.begin(), max_element(v_4x4_PRs.begin(),v_4x4_PRs.end()));
		leaderboard.push_back(&(players[i_4x4_ldr_idx]));
	}
	else
		leaderboard.push_back(dummy_player);
	if(any_of(v_5x5_PRs.begin(),v_5x5_PRs.end(),[](int i){return i!=-1;}))
	{
		int i_5x5_ldr_idx = distance(v_5x5_PRs.begin(), max_element(v_5x5_PRs.begin(),v_5x5_PRs.end()));
		leaderboard.push_back(&(players[i_5x5_ldr_idx]));
	}
	else
		leaderboard.push_back(dummy_player);

	return leaderboard;

}

//-----------------------------------------------------------------------

void Game_window::fill_tile_grid(int n)
{
	/*
		This function populates the tile_grid vector
		with nxn random tiles.

		Inputs: int n (dimension of grid)
		Outputs: N/A
	*/

	// Calculate dimensions of grid
	int grid_side = y_max() - 155 - 10;
	int tile_side = grid_side / n;


	for(int i=0;i<n;++i)
	{
		for(int j = 0; j < n; ++j){

			// Generate lower case letter
			char c = rand()%26 + 97; //generates a random lowercase letter
			string str_c(1, c);

			// Add tile to grid
			tile_grid.push_back(new Tile(Point(10 + j * tile_side, 10 + i * tile_side),
				   tile_side, tile_side,
				   cb_tile,
				   str_c,
				   i, j));
		}
	}
}

//-----------------------------------------------------------------------

Tile* Game_window::match_widget_tile(void* fltk_address)
{
	/*
		This function searches for the actual Tile object
		that holds the Fl_Widget inputted to the function.

		Inputs: fltk_address - address of tile on screen
		Outputs: N/A
	*/

	// Iterate through tile_grid until match is found
	for(unsigned i = 0; i < tile_grid.size(); ++i){
		void* temp_tile = tile_grid[i]->get_fltk_address();

		if(fltk_address == temp_tile) {
			return tile_grid[i];
		}
	}

	return nullptr;

}


//-----------------------------------------------------------------------

bool Game_window::is_contiguous(Tile* tile_1, Tile* tile_2)
{
	/*
		This function checks if two tiles are located
		next to each other.

		Inputs: tile_1 - first tile
				tile_2 - seconde tile
		Outputs: bool indicating if tiles were contiguous
	*/

	// Get positions of tiles
	int x1 = tile_1->get_pos_x();
	int y1 = tile_1->get_pos_y();
	int x2 = tile_2->get_pos_x();
	int y2 = tile_2->get_pos_y();


	// Check x positions
	if (x1 - x2 <= 1 && x1 - x2 >= -1) {
		
		// Check y postitions
		if (y1 - y2 <= 1 && y1 - y2 >= -1) {
			return true;
		}
	}
	
	return false;
}


//-----------------------------------------------------------------------

void Game_window::hide_all()
{
	/*
		This function hides all widgets attached to
		the window.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide widgets
	new_profile.hide();
	existing_profile.hide();
	back_profile.hide();
	new_name.hide();
	new_picture.hide();
	enter_new_user.hide();
	detach(blank_fields);
	detach(duplicate_user);
	existing_name.hide();
	enter_existing_user.hide();
	detach(user_not_found);
	detach(main_title);
	new_3x3.hide();
	new_4x4.hide();
	new_5x5.hide();
	change_profile.hide();
	detach(cur_profile);
	main_show_scores.hide();
	quit.hide();
	hide_grid();
	new_word.hide();
	backspace.hide();
	enter_word.hide();
	finish_game.hide();
	detach(current_score);
	used_words.hide();
	game_show_scores.hide();
	detach(duplicate_word);
	detach(error_word);
	detach(final_score);
	replay.hide();
	new_game.hide();
	detach(lbl_high_scores);
	detach(scores_div);
	detach(lbl_3x3);
	detach(name_3x3);
	detach(score_3x3);
	detach(lbl_4x4);
	detach(name_4x4);
	detach(score_4x4);
	detach(lbl_5x5);
	detach(name_5x5);
	detach(score_5x5);
	detach(return_main);
	detach(return_game);

	// Hide images
	if (img_3x3 != nullptr) {
		detach(*img_3x3);
	}
	if (img_4x4 != nullptr) {
		detach(*img_4x4);
	}
	if (img_5x5 != nullptr) {
		detach(*img_5x5);
	}

	// Redraw Window
	redraw();
}

//-----------------------------------------------------------------------

void Game_window::show_profile_screen()
{
	/*
		This function shows the widgets associated
		with the profile screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide all
	hide_all();

	// Show widgets
	new_profile.show();
	existing_profile.show();

}

//-----------------------------------------------------------------------

void Game_window::show_new_user_screen()
{
	/*
		This function shows the widgets associated
		with the new user screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide all
	hide_all();

	// Show widgets
	new_name.show();
	new_picture.show();
	enter_new_user.show();
	back_profile.show();

	// Redraw window
	redraw();
}

//-----------------------------------------------------------------------

void Game_window::show_existing_user_screen()
{
	/*
		This function shows the widgets associated
		with the existing user screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide all
	hide_all();

	// Show widgets
	existing_name.show();
	enter_existing_user.show();
	back_profile.show();

	// Redraw window
	redraw();
}

//-----------------------------------------------------------------------

void Game_window::show_main_menu_screen()
{
	/*
		This function shows the widgets associated
		with the main menu screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide all
	hide_all();

	// Show widgets
	attach(main_title);
	new_3x3.show();
	new_4x4.show();
	new_5x5.show();
	change_profile.show();
	attach(cur_profile);
	main_show_scores.show();
	quit.show();
	redraw();
}

//-----------------------------------------------------------------------

void Game_window::show_game_screen()
{
	/*
		This function shows the widgets associated
		with the game screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide all
	hide_all();

	// Show widgets
	show_grid();
	new_word.show();
	backspace.show();
	enter_word.show();
	finish_game.show();
	attach(current_score);
	used_words.show();
	game_show_scores.show();

	// Redraw window
	redraw();
}

//-----------------------------------------------------------------------

void Game_window::show_end_game_screen()
{
	/*
		This function shows the widgets associated
		with the end game screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide all
	hide_all();

	// Show widgets
	used_words.show();
	attach(final_score);
	replay.show();
	new_game.show();

	// Redraw Window
	redraw();
}


//-----------------------------------------------------------------------

void Game_window::show_high_scores_screen()
{
	/*
		This function shows the widgets associated
		with the high scores screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Hide all
	hide_all();

	// Show widgets
	attach(lbl_high_scores);
	attach(scores_div);
	attach(lbl_3x3);
	attach(name_3x3);
	attach(score_3x3);
	attach(lbl_4x4);
	attach(name_4x4);
	attach(score_4x4);
	attach(lbl_5x5);
	attach(name_5x5);
	attach(score_5x5);

	// Show images
	if (img_3x3 != nullptr) {
		attach(*img_3x3);
	}
	if (img_4x4 != nullptr) {
		attach(*img_4x4);
	}
	if (img_5x5 != nullptr) {
		attach(*img_5x5);
	}

	// Redraw Window
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::show_grid()
{
	/*
		This function shows all of the tile
		buttons on the screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Attach buttons to screen
	for(unsigned i = 0; i < tile_grid.size(); ++i) {
		tile_grid[i]->show();
	}


	// Redraw Window
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::hide_grid()
{
	/*
		This function hides all of the tile
		buttons on the screen.

		Inputs: N/A
		Outputs: N/A
	*/

	// Attach buttons to screen
	for(unsigned i = 0; i < tile_grid.size(); ++i) {
		tile_grid[i]->hide();
	}


	// Redraw Window
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::attach_grid()
{
	/*
		This function attaches all of the tile
		buttons to the game window.

		Inputs: N/A
		Outputs: N/A
	*/

	// Attach buttons to screen
	for(unsigned i = 0; i < tile_grid.size(); ++i) {
		attach(*(tile_grid[i]));
	}


	// Redraw Window
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::detach_grid()
{
	/*
		This function detaches all of the tile
		buttons from the game window.

		Inputs: N/A
		Outputs: N/A
	*/

	// Detach buttons to screen
	for(unsigned i = 0; i < tile_grid.size(); ++i) {
		detach(*(tile_grid[i]));
	}


	// Redraw Window
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::clear_grid()
{
	/*
		This function clears the objects and pointers
		in the tile_grid vector

		Inputs: N/A
		Outputs: N/A
	*/

	// Delete objects
	for(unsigned i = 0; i < tile_grid.size(); ++i) {
		delete tile_grid[i];
	}

	// Clear vector
	tile_grid.clear();

	// Redraw Window
	redraw();

}

//-----------------------------------------------------------------------
//=======================================================================

// CALLBACKS ============================================================
//-----------------------------------------------------------------------

void Game_window::cb_new_profile(Address, Address pw) {
	// References to Game_window::new_profile_pressed
	reference_to<Game_window>(pw).new_profile_pressed();
}

void Game_window::new_profile_pressed()
{
	/*
		Shows new user screen

		Inputs: N/A
		Outputs: N/A
	*/

	show_new_user_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_existing_profile(Address, Address pw) {
	// References to Game_window::existing_profile_pressed
	reference_to<Game_window>(pw).existing_profile_pressed();
}

void Game_window::existing_profile_pressed()
{
	/*
		Shows existing user screen

		Inputs: N/A
		Outputs: N/A
	*/

	show_existing_user_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_enter_new_user(Address, Address pw) {
	// References to Game_window::enter_new_user_pressed
	reference_to<Game_window>(pw).enter_new_user_pressed();
}

void Game_window::enter_new_user_pressed()
{
	/*
		Creates new player object from new_name and new_picture values
		Adds new player object to players
		Sets cur_player_idx to index of new player
		Shows main menu screen

		Preconditions: new_name value is not already in players vector
		Inputs: N/A
		Outputs: N/A
	*/

	string name = new_name.get_string();
	string pic_address = new_picture.get_string();

	if(name=="" || pic_address=="")
	{
		attach(blank_fields);
		redraw();
		return;
	}

	for(auto p : players)
	{
		if(p.get_name() == name)
		{
			attach(duplicate_user);
			redraw();
			return;
		}
	}

	// Create dummy scores vector
	vector<int> v_blank;

	Player p(name,pic_address, v_blank, v_blank, v_blank);
	add_player(p);
	cur_player_idx = players.size()-1;
	cur_profile.set_label(players[cur_player_idx].get_name());

	show_main_menu_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_back_profile(Address, Address pw) {
	// References to Game_window::back_profile_pressed
	reference_to<Game_window>(pw).back_profile_pressed();
}

void Game_window::back_profile_pressed()
{
	/*
		Shows existing user screen

		Inputs: N/A
		Outputs: N/A
	*/

	show_profile_screen();

}

//-----------------------------------------------------------------------


void Game_window::cb_enter_existing_user(Address, Address pw) {
	// References to Game_window::enter_existing_user_pressed
	reference_to<Game_window>(pw).enter_existing_user_pressed();
}

void Game_window::enter_existing_user_pressed()
{
	/*
		Searches players vector for player with user-specified name
		Sets cur_player_idx to index of the found player
		Shows main menu screen

		Preconditions: There is a player in players with the user-specified name
		Inputs: N/A
		Outputs: N/A
	*/

	string name = existing_name.get_string();
	for(int i=0;i<players.size();++i)
	{
		if(players[i].get_name() == name)
		{
			cur_player_idx = i;
			cur_profile.set_label(players[cur_player_idx].get_name());
			show_main_menu_screen();
			return;
		}
	}

	attach(user_not_found);
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::cb_new_3x3(Address, Address pw) {
	// References to Game_window::new_3x3_pressed
	reference_to<Game_window>(pw).new_3x3_pressed();
}

void Game_window::new_3x3_pressed()
{
	/*
		Erases old tiles from tile_grid
		Fills tile_grid with 9 randomly generated tiles
		Sets difficulty to 3x3
		Shows game screen

		Inputs: N/A
		Outputs: N/A
	*/

	clear_grid();
	fill_tile_grid(3);
	attach_grid();
	dif = Difficulty::d_3x3;
	show_game_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_new_4x4(Address, Address pw) {
	// References to Game_window::new_4x4
	reference_to<Game_window>(pw).new_4x4_pressed();
}

void Game_window::new_4x4_pressed()
{
	/*
		Erases old tiles from tile_grid
		Fills tile_grid with 16 randomly generated tiles
		Sets difficulty to 4x4
		Shows game screen

		Inputs: N/A
		Outputs: N/A
	*/

	clear_grid();
	fill_tile_grid(4);
	attach_grid();
	dif = Difficulty::d_4x4;
	show_game_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_new_5x5(Address, Address pw) {
	// References to Game_window::new_5x5
	reference_to<Game_window>(pw).new_5x5_pressed();
}

void Game_window::new_5x5_pressed()
{
	/*
		Erases old tiles from tile_grid
		Fills tile_grid with 25 randomly generated tiles
		Sets difficulty to 5x5
		Shows game screen

		Inputs: N/A
		Outputs: N/A
	*/

	clear_grid();
	fill_tile_grid(5);
	attach_grid();
	dif = Difficulty::d_5x5;
	show_game_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_change_profile(Address, Address pw) {
	// References to Game_window::change_profile_pressed
	reference_to<Game_window>(pw).change_profile_pressed();
}

void Game_window::change_profile_pressed()
{
	/*
		Shows profile screen

		Inputs: N/A
		Outputs: N/A
	*/

	show_profile_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_main_show_scores(Address, Address pw) {
	// References to Game_window::main_show_scores_pressed
	reference_to<Game_window>(pw).main_show_scores_pressed();
}

void Game_window::main_show_scores_pressed()
{
	/*
		Finds highest-scoring players in each category by calling get_leaderboard()
		Updates high-scores screen widgets
		Shows high-scores screen

		Inputs: N/A
		Outputs: N/A
	*/
	enter_word_pressed();

	vector<Player*> highscores = get_leaderboard();

	name_3x3.set_label(highscores[0]->get_name());
	name_4x4.set_label(highscores[1]->get_name());
	name_5x5.set_label(highscores[2]->get_name());

	score_3x3.set_label("Score: " + to_string(highscores[0]->get_scores_3x3()[0]));
	score_4x4.set_label("Score: " + to_string(highscores[1]->get_scores_4x4()[0]));
	score_5x5.set_label("Score: " + to_string(highscores[2]->get_scores_5x5()[0]));

	delete img_3x3;
	delete img_4x4;
	delete img_5x5;

	img_3x3 = new Image(Point(20,100),highscores[0]->get_picture());
	img_4x4 = new Image(Point(220,100),highscores[1]->get_picture());
	img_5x5 = new Image(Point(420,100),highscores[2]->get_picture());

	img_3x3->resize(160,160);
	img_4x4->resize(160,160);
	img_5x5->resize(160,160);

	highscores.clear();

	show_high_scores_screen();
	attach(return_main);
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::cb_quit(Address, Address pw) {
	// References to Game_window::quit_pressed
	reference_to<Game_window>(pw).quit_pressed();
}

void Game_window::quit_pressed()
{
	/*
		This callback action calls the FLTK idiom for delete window.

		Inputs: N/A
		Outputs: N/A
	*/

	// Quit Program
	delete dummy_player;
	output_data(players);
	hide();

}

//-----------------------------------------------------------------------

void Game_window::cb_tile(Address t, Address pw) {
	// References to Tile
	string l = ((Fl_Button*)(t)) -> label();

	// References to Game_window::tile_pressed
	reference_to<Game_window>(pw).tile_pressed(l, t);
}

void Game_window::tile_pressed(string l, Address t)
{
	/*
		Adds a character to the end of the current word string
		Updates the current word outbox

		Inputs: N/A
		Outputs: N/A
	*/

	bool process_tile = false;

	// Get current tile
	Tile* cur_tile = match_widget_tile(t);

	if(used_tiles.size() > 0) {

		// Get previous tile
		Tile* pre_tile = match_widget_tile(used_tiles[used_tiles.size() - 1]);

		// Check if tiles are contiguous
		process_tile = is_contiguous(cur_tile, pre_tile);
	}
	else {
		process_tile = true;
	}

	// Process tile
	if(process_tile) {

		// Hide tile
		cur_tile->hide();

		// Add letter to current word
		cur_word = cur_word + l;

		// Update word
		new_word.put(cur_word);

		// Add tile to list of used
		used_tiles.push_back(((Fl_Widget*)(t)));

		redraw();
	}

}

//-----------------------------------------------------------------------

void Game_window::cb_backspace(Address, Address pw) {
	// References to Game_window::backspace_pressed
	reference_to<Game_window>(pw).backspace_pressed();
}

void Game_window::backspace_pressed()
{
	/*
		Removes a character from the end of the current
		word string and adds the appropriate tile back
		to the game board

		Inputs: N/A
		Outputs: N/A
	*/

	if(used_tiles.size() > 0){
		// Remove letter from the end of the word
		cur_word = cur_word.substr(0, cur_word.size()-1);

		// Update word
		new_word.put(cur_word);

		// Add tile back to game board
		used_tiles[used_tiles.size() - 1]->show();

		// Remove tile from used tile list
		used_tiles.erase(used_tiles.begin() + used_tiles.size() - 1);
	}
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::cb_enter_word(Address, Address pw) {
	// References to Game_window::enter_word_pressed
	reference_to<Game_window>(pw).enter_word_pressed();
}

void Game_window::enter_word_pressed()
{
	/*
		Awards a point and updates used_words_buffer if current word is in dictionary
		Erases the current word
		Updates the score text

		Inputs: N/A
		Outputs: N/A
	*/

	if(cur_word == "")
		return;

	auto it = v_used_words.begin();
	for(; it != v_used_words.end(); ++it)
		if(cur_word == *it)
		{
			detach(error_word);
			attach(duplicate_word);
			break;
		}

	if(!in_dict(cur_word))
	{
		detach(duplicate_word);
		attach(error_word);
	}
	else if(it == v_used_words.end())
	{
		detach(duplicate_word);
		detach(error_word);
		score++;
		used_words_buffer += "\n"+cur_word;
		v_used_words.push_back(cur_word);
	}


	redraw();
	cur_word = "";
	new_word.put("");
	used_words.put(used_words_buffer);
	current_score.set_label("Current score: " + to_string(score));

	// Show all tiles
	used_tiles.clear();
	show_grid();
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::cb_finish_game(Address, Address pw) {
	// References to Game_window::finish_game_pressed
	reference_to<Game_window>(pw).finish_game_pressed();
}

void Game_window::finish_game_pressed()
{
	/*
		Adds score to the current player's appropriate score vector
		Shows end game screen

		Inputs: N/A
		Outputs: N/A
	*/

	enter_word_pressed(); //in case user ends game in the middle of a word
	v_used_words.clear();
	final_score.set_label("Final score: " + to_string(score));
	if(dif == Difficulty::d_3x3)
		players[cur_player_idx].add_score_3x3(score);
	else if(dif == Difficulty::d_4x4)
		players[cur_player_idx].add_score_4x4(score);
	else
		players[cur_player_idx].add_score_5x5(score);

	show_end_game_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_game_show_scores(Address, Address pw) {
	// References to Game_window::game_show_scores_pressed
	reference_to<Game_window>(pw).game_show_scores_pressed();
}

void Game_window::game_show_scores_pressed()
{
	/*
		Finds highest-scoring players in each category by calling get_leaderboard()
		Updates high-scores screen widgets
		Shows high-scores screen

		Inputs: N/A
		Outputs: N/A
	*/
	enter_word_pressed();

	vector<Player*> highscores = get_leaderboard();

	name_3x3.set_label(highscores[0]->get_name());
	name_4x4.set_label(highscores[1]->get_name());
	name_5x5.set_label(highscores[2]->get_name());

	score_3x3.set_label("Score: " + to_string(highscores[0]->get_scores_3x3()[0]));
	score_4x4.set_label("Score: " + to_string(highscores[1]->get_scores_4x4()[0]));
	score_5x5.set_label("Score: " + to_string(highscores[2]->get_scores_5x5()[0]));

	delete img_3x3;
	delete img_4x4;
	delete img_5x5;

	img_3x3 = new Image(Point(20,100),highscores[0]->get_picture());
	img_4x4 = new Image(Point(220,100),highscores[1]->get_picture());
	img_5x5 = new Image(Point(420,100),highscores[2]->get_picture());

	img_3x3->resize(160,160);
	img_4x4->resize(160,160);
	img_5x5->resize(160,160);

	highscores.clear();

	show_high_scores_screen();
	attach(return_game);
	redraw();

}

//-----------------------------------------------------------------------

void Game_window::cb_replay(Address, Address pw) {
	// References to Game_window::replay_pressed
	reference_to<Game_window>(pw).replay_pressed();
}

void Game_window::replay_pressed()
{
	/*
		Allows the player to replay using the same tile grid

		Inputs: N/A
		Outputs: N/A
	*/

	score = 0;
	used_words_buffer.clear();
	used_words.put("");
	show_game_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_new_game(Address, Address pw) {
	// References to Game_window::new_game_pressed
	reference_to<Game_window>(pw).new_game_pressed();
}

void Game_window::new_game_pressed()
{
	/*
		Allows the player to replay using a different tile grid

		Inputs: N/A
		Outputs: N/A
	*/

	score = 0;
	used_words_buffer.clear();
	used_words.put("");
	show_main_menu_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_return_main(Address, Address pw) {
	// References to Game_window::return_main_pressed
	reference_to<Game_window>(pw).return_main_pressed();
}

void Game_window::return_main_pressed()
{
	/*
		Takes the player from the high-scores screen back to the main menu

		Inputs: N/A
		Outputs: N/A
	*/

	show_main_menu_screen();

}

//-----------------------------------------------------------------------

void Game_window::cb_return_game(Address, Address pw) {
	// References to Game_window::return_game_pressed
	reference_to<Game_window>(pw).return_game_pressed();
}

void Game_window::return_game_pressed()
{
	/*
		Takes the player from the high-scores screen back to the game screen

		Inputs: N/A
		Outputs: N/A
	*/

	show_game_screen();

}

//-----------------------------------------------------------------------
//=======================================================================