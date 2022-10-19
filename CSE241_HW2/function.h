#ifndef _FUNCTION_H_
#define _FUNCTION_H_

enum cells : char {userOne, userTwo, emptyCell};

void load_game(char **game_board, int &sizeOfBoard, bool **check);
void save_game(char **game_board, int &sizeOfBoard);
void fill_table(char **game_board, const int &sizeOfBoard);
void show_board(char **game_board, const int &sizeOfBoard);
void edit_board(char **game_board, const int &sizeOfBoard, int row, int coln);
bool check_point(cells **check, const int &move1, const int &move2);
bool finish_game(char **game_board, const int &sizeOfBoard, cells **check, int move1 = 0,  int move2 = 0);
void play_game(char **game_board, int sizeOfBoard, cells **check,char choice);
char upper_case(const char &player);
bool top_to_down_check(char **game_board, const int &sizeOfBoard, cells **check, const int &move1 = 0, const int &move2 = 0);
bool right_to_left_check(char **game_board, const int &sizeOfBoard,cells **check, const int &move1 = 0, const int &move2 = 0);
void computer_move_check(char **game_board, const int &sizeOfBoard, int move1, int move2);


#endif

