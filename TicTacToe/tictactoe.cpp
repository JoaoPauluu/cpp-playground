#include <iostream>
#include <vector>
#include "./functions.h"
using namespace std;


int main() {

    int turn = 1;

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "TIC TAC TOE BY JOAOPAULUU \n \n \n";
    cout << "MOVES MUST BE ROW THEN COLLUM, EX: a0, b2, c2 \n\n\n\n\n\n";


    Board board;


    while(true) {

        // Checks for draw and ends the game
        if(turn > 9) {
            cout << "\nDRAW";
            break;
        }



        //checks whose the turn is
        string turn_name;

        if(turn % 2 == 1) {
            turn_name = "X";
        }
        else {
            turn_name = "O";
        }



            //Reads and checks if move is valid
            string current_move;
            board.print_board();

            cout << turn_name << "'s turn: ";
            cin >> current_move;
            cout << "\n\n";

            if(!board.is_valid_move(current_move)) {
                cout << "PLAY AGAIN\n\n\n";
                continue;
            }

            board.play(turn_name, current_move);

            int win = board.check_for_win();
            if(win == 1) {
                cout << "\n\nX WON";
                break;
            }
            if(win == -1) {
                cout << "\n\nO WON";
                break;
            }

            turn++;

    }

    string empty;
    cout << "\n\nTHANKS FOR PLAYING";
    cin >> empty;
}