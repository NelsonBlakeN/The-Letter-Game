# The-Letter-Game
CSCE 121 2016 Team Project

### Project description:

CSCE 121-200: Project - WordSearch
Fall 2016

This is a rather open-ended project, to allow opportunities for your creativity. Each team is to write a C++ program using the textbook's graphics library that presents a graphical user interface (GUI) for playing a word search game. All user interactions with the program are to be via your GUI.

### Minimum Specifications for WordSearch:

When the user first starts, s/he enters his/her name into a textbox.
Have a grid of buttons, whose size is chosen by the user to be either 3x3, 4x4 or 5x5. Randomly label the buttons with letters from A to Z (duplications allowed).
The user can then press buttons to create candidate words: when the user is finished, s/he presses an "enter" button.
Extra credit: don't allow the same button to be pressed more than once, require the pressed buttons to be contiguous, allow the user to backtrack, display what the user has entered so far, etc.

After the user presses "enter", your program will check whether the entered series of letters really is a word, by looking in a provided dictionary file.
Assign a score for the user's string: 0 if it is not in the dictionary, and some positive integer otherwise (you can figure out your own scoring mechanism; perhaps you want to give more points depending on how many letters are in the word, or just give 1 point for a word). Inform the user of his/her score, as well as the total so far.
When the user is through searching for words, s/he presses a "done" button, which displays his/her total score (sum of all the per-word scores).
The program will also keep track of all the scores achieved by all the different players. Note that the same player can have multiple scores, one for each time s/he plays. This information needs to persist even after the program completes, i.e., it needs to be stored in a file, read in when the program begins, and written out when the program quits.
Provide an interface by which the user can request to display the name, maximum score, and a photo of the highest scoring player. Figure out a reasonable way for a new highest scorer to provide the name of a jpg file containing his/her photo.
Feel free to add additional bells and whistles.
Project will be done in teams, to be assigned by Dr. Welch.
