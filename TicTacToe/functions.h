#include<iostream>
#include <vector>
using namespace std;

class Board {

private:
    vector<vector<int>> board;

public:
    Board();
    void print_board();
    void play(string turn_name, string move);
    int get_square(string move);
    bool is_valid_move(string move);
    int check_for_win();
};

