#include <iostream>
#include <vector>
#include "./functions.h"
using namespace std;

Board::Board() {
//    for(int i = 0; i < 3; i++) {
//            board.push_back(vector<int>(3, 0));
//        }
    board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

void Board::print_board() {
    cout << "      0      1      2\n\n";
    //outer loop (goes through all the columns inside the first array)
    for(int i = 0; i <= 2; i++) {
        vector<int> row = board[i];
        switch(i) {
            case 0:
            cout << "a  ";
            break;
            case 1:
            cout << "b  ";
            break;
            case 2:
            cout << "c  ";
            break;
        }






        //inner loop (goes through all the variables inside the rows array)
        for(int num = 0; num <= 2; num++) {
            string cn;
            switch(row[num]) {
                case 0:
                cn = " ";
                break;
                case 2:
                cn = "X";
                break;
                case -10:
                cn = "O";
                break;
                default:
                cn = '!';
                
            }   
            cout << " | ";
            cout << cn;
            cout << " | ";
        }


        cout << "\n";
    }
};


void Board::play(string turn_name, string move) {
    int row;
    switch (move[0]) {
        case 'a':
        row = 0;
        break;
        case 'b':
        row = 1;
        break;
        case 'c':
        row = 2;
        break;
    }


    int column = move[1] - '0';

    if (turn_name == "X") {
        board[row][column] = 2;
        return;
    }
    if (turn_name == "O") {
        board[row][column] = -10;
        return;
    }
}

int Board::get_square(string move) {
    int row;
    switch (move[0]) {
        case 'a':
        row = 0;
        break;
        case 'b':
        row = 1;
        break;
        case 'c':
        row = 2;
        break;
    }


    int column = move[1] - '0';

    return board[row][column];
}


bool Board::is_valid_move(string move) {
    //checks the size
    if(move.length() != 2) {
        cout << "\n\nINPUT MUST BE TWO CHARACTERS LONG\n";
        return false;
    }
    //checks if the first char is a b or c
    if(move[0] != 'a' && move[0] != 'b' && move[0] != 'c') {
        cout << "\n\nFIRST CHARACTER MUST BE a, b or c\n";
        return false;
    }
    //checks if the second char is between 0 and 2
    if(move[1] != '0' && move[1] != '1' && move[1] != '2') {
        cout << "\n\nSECOND CHARACTER MUST BE 0, 1 or 2\n";
        return false;
    }


    //checks if move hasn't been played already
    if(this->get_square(move) != 0) {
        cout << "\n\nMOVE ALREADY MADE\n";
        return false;
    }


    return true;

}


int Board::check_for_win() {
    //Checks the sum of each vector
    for(int i = 0; i <= 2; i++) {

        int vecsum = 0;
        
        for(int j = 0; j <= 2; j++) {
            vecsum = vecsum + board[i][j];
        }
        if(vecsum == 6) {
            return 1;
        }
        if(vecsum == -30) {
            return -1;
        }

    }




    //Checks for sum of each row
    for(int i = 0; i <= 2; i++) {

        int rowsum = 0;
        for(int j = 0; j <= 2; j++) {
            rowsum = rowsum + board[j][i];
        }
        if(rowsum == 6) {
            return 1;
        }
        if(rowsum == -30) {
            return -1;
        }
    }


    //Checks for diagonals
    int diagsum_a = 0;
    int diagsum_b = 0;
    for(int i = 0; i <= 2; i++) {
        diagsum_a = diagsum_a + board[i][i];
        diagsum_b = diagsum_b + board[i][2 - i];
    }

    if(diagsum_a == 6 || diagsum_b == 6) {
            return 1;
        }
    if(diagsum_a == -30 || diagsum_b == -30) {
            return -1;
        }

    return 0;
}