#ifndef _FUNCTION_H_
#define _FUNCTION_H_



void fill_table(char **game_board, int sizeOfBoard);
void show_board(char **game_board, int sizeOfBoard);
void edit_board(char **game_board, int sizeOfBoard, int row, int coln);
bool check_point(bool **check, int move1, int move2);
bool finish_game(char **game_board, int sizeOfBoard, bool **check, int move1 = 0, int move2 = 0);
void play_game(char **game_board, int sizeOfBoard, bool **check);
char upper_case(char player);
bool top_to_down_check(char **game_board, int sizeOfBoard, bool **check, int move1 = 0, int move2 = 0);
bool right_to_left_check(char **game_board, int sizeOfBoard,bool **check, int move1 = 0, int move2 = 0);
void computer_move_check(char **game_board, int sizeOfBoard, int move1, int move2);


#endif




