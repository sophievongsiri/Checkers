#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

class Checkers {

private:
    char board[8][8];
    char player;

public:

    void Create_Board() {
        cout << "   ---------------------------------" << endl;
        for (int i = 0; i < 8; i++) {
            cout << "   | ";
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "   ---------------------------------" << endl;
        }
    }

    void Create_Spaces() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void Create_Pieces() {

        for (int i = 0; i < 3; i += 2) {
            for (int j = 1; j < 8; j += 2) {
                board[i][j] = 'B';
            }
        }
        for (int i = 1; i < 2; i++) {
            for (int j = 0; j < 8; j += 2) {
                board[i][j] = 'B';
            }
        }

        for (int i = 5; i < 8; i += 2) {
            for (int j = 0; j < 8; j += 2) {
                board[i][j] = 'R';
            }
        }
        for (int i = 6; i < 7; i += 2) {
            for (int j = 1; j < 8; j += 2) {
                board[i][j] = 'R';
            }
        }
    }

    void Assign_Player() {
        player = 2;
    }

    void Switch_Player() {
        player = (player == 2) ? 1 : 2;
    }


    void Choose_Move() {
        int row1, column1, row2, column2;

        while (true) {
            if (player == 2) {
                cout << "Your turn. What piece would you like to move?" << endl;
                cout << "Row: ";
                cin >> row1;
                cout << "Column: ";
                cin >> column1;

                if (row1 < 0 || row1 >= 8 || column1 < 0 || column1 >= 8) {
                    cout << "Invalid input. Try again." << endl;
                    continue;
                }

                if (board[row1][column1] == 'K') {
                    bool jumped = false;
                    if (row1 + 2 < 8 && column1 + 2 < 8 && (board[row1 + 1][column1 + 1] == 'R' || board[row1 + 1][column1 + 1] == 'Q') && board[row1 + 2][column1 + 2] == ' ') {
                        cout << "You must jump." << endl;
                        board[row1 + 2][column1 + 2] = 'K';
                        board[row1][column1] = ' ';
                        board[row1 + 1][column1 + 1] = ' ';
                        jumped = true;
                    }
                    else if (row1 + 2 < 8 && column1 - 2 >= 0 && (board[row1 + 1][column1 - 1] == 'R' || board[row1 + 1][column1 - 1] == 'Q') && board[row1 + 2][column1 - 2] == ' ') {
                        cout << "You must jump." << endl;
                        board[row1 + 2][column1 - 2] = 'K';
                        board[row1][column1] = ' ';
                        board[row1 + 1][column1 - 1] = ' ';
                        jumped = true;
                    }
                    else if (row1 - 2 >= 0 && column1 - 2 >= 0 && (board[row1 - 1][column1 - 1] == 'R' || board[row1 - 1][column1 - 1] == 'Q') && board[row1 - 2][column1 - 2] == ' ') {
                        cout << "You must jump." << endl;
                        board[row1 - 2][column1 - 2] = 'K';
                        board[row1][column1] = ' ';
                        board[row1 - 1][column1 - 1] = ' ';
                        jumped = true;
                    }
                    else if (row1 - 2 >= 0 && column1 + 2 < 8 && (board[row1 - 1][column1 + 1] == 'R' || board[row1 - 1][column1 + 1] == 'Q') && board[row1 - 2][column1 + 2] == ' ') {
                        cout << "You must jump." << endl;
                        board[row1 - 2][column1 + 2] = 'K';
                        board[row1][column1] = ' ';
                        board[row1 - 1][column1 + 1] = ' ';
                        jumped = true;
                    }
                    if (jumped) {
                        Create_Board();
                        Switch_Player();
                        break;
                    }

                    cout << "Where would you like to move the checker to?" << endl;
                    cout << "Row: ";
                    cin >> row2;
                    cout << "Column: ";
                    cin >> column2;

                    if (row2 < 0 || row2 >= 8 || column2 < 0 || column2 >= 8) {
                        cout << "Invalid input. Try again." << endl;
                        continue;
                    }
                    if ((board[row1][column1] == 'K') && (board[row2][column2] == ' ')) {
                        int row_change = row2 - row1;
                        int column_change = column2 - column1;
                        if ((row_change == 1 || row_change == -1) && (column_change == 1 || column_change == -1)) {
                            board[row2][column2] = 'K';
                            board[row1][column1] = ' ';
                            Create_Board();
                            Switch_Player();
                            break;
                        }
                        else {
                            cout << "Invalid input. Try again." << endl;
                        }
                    }
                    else {
                        cout << "Invalid move. Choose again." << endl;
                    }
                }
                if (board[row1][column1] == 'B') {
                    bool jumped = false;

                    if (row1 + 2 < 8 && column1 + 2 < 8 && (board[row1 + 1][column1 + 1] == 'R' || board[row1 + 1][column1 + 1] == 'Q') && board[row1 + 2][column1 + 2] == ' ') {
                        cout << "You must jump." << endl;
                        board[row1 + 2][column1 + 2] = 'B';
                        board[row1][column1] = ' ';
                        board[row1 + 1][column1 + 1] = ' ';
                        if ((row1 + 2) == 7) {
                            board[row1 + 2][column1 + 2] = 'K';
                        }
                        jumped = true;
                    }
                    else if (row1 + 2 < 8 && column1 - 2 >= 0 && (board[row1 + 1][column1 - 1] == 'R' || board[row1 + 1][column1 - 1] == 'Q') && board[row1 + 2][column1 - 2] == ' ') {
                        cout << "You must jump." << endl;
                        board[row1 + 2][column1 - 2] = 'B';
                        board[row1][column1] = ' ';
                        board[row1 + 1][column1 - 1] = ' ';
                        if ((row1 + 2) == 7) {
                            board[row1 + 2][column1 - 2] = 'K';
                        }
                        jumped = true;
                    }

                    if (jumped) {
                        Create_Board();
                        Switch_Player();
                        break;
                    }

                    cout << "Where would you like to move the checker to?" << endl;
                    cout << "Row: ";
                    cin >> row2;
                    cout << "Column: ";
                    cin >> column2;

                    if (row2 < 0 || row2 >= 8 || column2 < 0 || column2 >= 8) {
                        cout << "Invalid input. Try again." << endl;
                        continue;
                    }

                    if ((board[row1][column1] == 'B') && (board[row2][column2] == ' ')) {
                        int row_change = row2 - row1;
                        int column_change = column2 - column1;
                        if (row_change == 1 && (column_change == 1 || column_change == -1)) {
                            board[row2][column2] = 'B';
                            board[row1][column1] = ' ';
                            if (row2 == 7) {
                                board[row2][column2] = 'K';
                            }
                            Create_Board();
                            Switch_Player();
                            break;
                        }
                        else {
                            cout << "Invalid input. Try again." << endl;
                        }
                    }
                    else {
                        cout << "Invalid move. Choose again." << endl;
                    }
                }
                else {
                    cout << "No piece at this location or wrong piece selected. Try again." << endl;
                }

            }
            else if (player == 1) {
                cout << "Computer's turn." << endl;

                while (true) {
                    row1 = rand() % 8;
                    column1 = rand() % 8;

                    if (board[row1][column1] == 'Q') {
                        row2 = (rand() % 2 == 0) ? row1 - 1 : row1 + 1;
                        column2 = (rand() % 2 == 0) ? column1 - 1 : column1 + 1;
                        bool jumped = false;
                        if (row1 - 2 >= 0 && column1 - 2 >= 0 && (board[row1 - 1][column1 - 1] == 'B' || board[row1 - 1][column1 - 1] == 'K') && board[row1 - 2][column1 - 2] == ' ') {
                            cout << "Computer must jump." << endl;
                            cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row1 - 2 << ", " << column1 - 2 << ")." << endl;
                            board[row1 - 2][column1 - 2] = 'Q';
                            board[row1][column1] = ' ';
                            board[row1 - 1][column1 - 1] = ' ';
                            jumped = true;
                        }
                        else if (row1 - 2 >= 0 && column1 + 2 < 8 && (board[row1 - 1][column1 + 1] == 'B' || board[row1 - 1][column1 + 1] == 'K') && board[row1 - 2][column1 + 2] == ' ') {
                            cout << "Computer must jump." << endl;
                            cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row1 - 2 << ", " << column1 + 2 << ")." << endl;
                            board[row1 - 2][column1 + 2] = 'Q';
                            board[row1][column1] = ' ';
                            board[row1 - 1][column1 + 1] = ' ';
                            jumped = true;
                        }
                        else if (row1 + 2 < 8 && column1 + 2 < 8 && (board[row1 + 1][column1 + 1] == 'B' || board[row1 + 1][column1 + 1] == 'K') && board[row1 + 2][column1 + 2] == ' ') {
                            cout << "Computer must jump." << endl;
                            cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row1 - 2 << ", " << column1 + 2 << ")." << endl;
                            board[row1 + 2][column1 + 2] = 'Q';
                            board[row1][column1] = ' ';
                            board[row1 + 1][column1 + 1] = ' ';
                            jumped = true;
                        }
                        else if (row1 + 2 < 8 && column1 - 2 >= 0 && (board[row1 + 1][column1 - 1] == 'B' || board[row1 + 1][column1 - 1] == 'K') && board[row1 + 2][column1 - 2] == ' ') {
                            cout << "Computer must jump." << endl;
                            cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row1 - 2 << ", " << column1 + 2 << ")." << endl;
                            board[row1 + 2][column1 - 2] = 'Q';
                            board[row1][column1] = ' ';
                            board[row1 + 1][column1 - 1] = ' ';
                            jumped = true;
                        }
                        if (jumped) {
                            Create_Board();
                            Switch_Player();
                            break;
                        }
                        else {
                            if (row2 >= 0 && column2 >= 0 && column2 < 8 && board[row1][column1] == 'Q' && board[row2][column2] == ' ') {
                                board[row2][column2] = 'Q';
                                board[row1][column1] = ' ';
                                cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row2 << ", " << column2 << ")." << endl;
                                Create_Board();
                                Switch_Player();
                                break;
                            }
                        }
                    }




                    if (board[row1][column1] == 'R') {
                        row2 = row1 - 1;
                        column2 = (rand() % 2 == 0) ? column1 - 1 : column1 + 1;
                        bool jumped = false;
                        if (row1 - 2 >= 0 && column1 - 2 >= 0 && (board[row1 - 1][column1 - 1] == 'B' || board[row1 - 1][column1 - 1] == 'K') && board[row1 - 2][column1 - 2] == ' ') {
                            cout << "Computer must jump." << endl;
                            cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row1 - 2 << ", " << column1 - 2 << ")." << endl;
                            board[row1 - 2][column1 - 2] = 'R';
                            board[row1][column1] = ' ';
                            board[row1 - 1][column1 - 1] = ' ';
                            if ((row1 - 2) == 0) {
                                board[row1 - 2][column1 - 2] = 'Q';
                            }
                            jumped = true;
                        }
                        else if (row1 - 2 >= 0 && column1 + 2 < 8 && (board[row1 - 1][column1 + 1] == 'B' || board[row1 - 1][column1 + 1] == 'K') && board[row1 - 2][column1 + 2] == ' ') {
                            cout << "Computer must jump." << endl;
                            cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row1 - 2 << ", " << column1 + 2 << ")." << endl;
                            board[row1 - 2][column1 + 2] = 'R';
                            board[row1][column1] = ' ';
                            board[row1 - 1][column1 + 1] = ' ';
                            if ((row1 - 2) == 0) {
                                board[row1 - 2][column1 + 2] = 'Q';
                            }
                            jumped = true;
                        }
                        if (jumped) {
                            Create_Board();
                            Switch_Player();
                            break;
                        }
                        else {
                            if (row2 >= 0 && column2 >= 0 && column2 < 8 && board[row1][column1] == 'R' && board[row2][column2] == ' ') {
                                board[row2][column2] = 'R';
                                board[row1][column1] = ' ';
                                cout << "Computer moved from (" << row1 << ", " << column1 << ") to (" << row2 << ", " << column2 << ")." << endl;
                                if (row2 == 0) {
                                    board[row2][column2] = 'Q';
                                }
                                Create_Board();
                                Switch_Player();
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int Check_Win() {
        bool NoComputer = true;
        bool NoUser = true;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'K' || board[i][j] == 'B') {
                    NoUser = false;
                    break;
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'Q' || board[i][j] == 'R') {
                    NoComputer = false;
                    break;
                }
            }
        }
        if (NoComputer) {
            cout << "Congrats! You won!" << endl;
            return 1;
        }
        if (NoUser) {
            cout << "Oh no! You lost!" << endl;
            return 0;
        }
    }
};

int main() {
    srand(time(NULL));
    Checkers play;
    cout << "This is the board, rows (0-7) and columns (0-7).\nIf you get a king, the icon will change to K. If the computer does, its icon will become Q. \nYou play first! You are Black (B). Computer is Red (R)." << endl;
    play.Create_Spaces();
    play.Create_Pieces();
    play.Create_Board();
    play.Assign_Player();

    while (true) {
        play.Choose_Move();
        if ((play.Check_Win() == 1) || (play.Check_Win()) == 0) {
            break;
        }
    }

    return 0;
}





