#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Header.h"

using namespace std;

int main() {
    
    int move;
    
    const int NUM_SQUARES = 9;
    
    vector<char> board(NUM_SQUARES, EMPTY);
    
    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    
    displayBoard(board);
    
    while (winner(board) == NO_ONE) {
        if (turn == human) {
            move = humanMove(board, human);
            board[move] = human;
        } else {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        
        displayBoard(board);
        turn = opponent(turn);
    }
    
    announceWinner(winner(board), computer, human);
    
    
    return 0;
}

void instructions() {
    cout << "welcome to the ultimate man-machine showdown: tic-tac-toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";
    
    cout << "Make your move known by entering a number, 0 - 8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";
    
    cout << "\t 0 | 1 | 2\n";
    cout << "\t-----------\n";
    cout << "\t 3 | 4 | 5\n";
    cout << "\t-----------\n";
    cout << "\t 6 | 7 | 8\n\n";
    
    cout << "Prepare yourself, human. The battle is about to being.\n\n";
}

char askYesNo(string question) {
    char response;
    
    do {
        cout << question << endl;
        cin >> response;
    } while (response != 'y' && response != 'n');
    
    return response;
}

int askNumber(string question, int high, int low) {
    int number;
    
    do {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while(number > high || number < low);
    
    return number;
}

char humanPiece() {
    char go_first = askYesNo("do you require the first move?(y\\n)");
    
    if (go_first == 'y') {
        cout << "\nThen take the first move. You will need it.\n";
        return X;
    } else {
        cout << "\nYour bravery will be your undoing...I will go first\n";
        return O;
    }
}

char opponent(char piece) {
    if (piece == X) {
        return O;
    } else {
        return X;
    }
}

void displayBoard(const vector<char>& board) {
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board) {
//    all possible winning rows
    const int WINNING_ROWS[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    
    const int TOTAL_ROWS = 8;
    
    for (int i = 0; i < TOTAL_ROWS; i++) {
        if ((board[WINNING_ROWS[i][0]] != EMPTY) &&
            (board[WINNING_ROWS[i][0]] == board[WINNING_ROWS[i][1]]) &&
            (board[WINNING_ROWS[i][1]] == board[WINNING_ROWS[i][2]])){
            return board[WINNING_ROWS[i][0]];
        }
    }
    
    if (count(board.begin(), board.end(), EMPTY) == 0) {
        return TIE;
    }
    
    return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board) {
    return (board[move] == EMPTY);
}

int humanMove(const vector<char>&board, char human) {
    int move = askNumber("where will you move?", (board.size() - 1));
    while(!isLegal(move, board)) {
        cout << "\nthat square is already occupied, foolish human.\n";
        move = askNumber("where will you move?", (board.size() - 1));
    }
    
    cout << "fine...\n";
    
    return move;
}

int computerMove(vector<char> board, char computer) {
    unsigned int move = 0;
    bool found = false;
    
    while (!found && move < board.size()) {
        if (isLegal(move, board)) {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        
        if (!found) {
            ++move;
        }
    }
    
    //otherwise, if human can win on next move, that's the move to make
    if (!found) {
        move = 0;
        char human = opponent(computer);
        
        while (!found && move < board.size()) {
            if (isLegal(move, board)) {
                board[move] = human;
                found = winner(board) == human;
                board[move] = EMPTY;
            }
            
            if (!found) {
                ++move;
            }
        }
    }
    
    // otherwise, moving to the best open square is the move to make
    if (!found) {
        move = 0;
        unsigned int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        // pick  best open square
        while (!found && i < board.size()) {
            move = BEST_MOVES[i];
            if (isLegal(move, board)) {
                found = true;
            }
                
            ++i;
        }
    }
    
    cout << "I shall take square number " << move << endl;
    
    return move;
}

void announceWinner(char winner, char computer, char human) {
    if (winner == computer) {
        cout << "the computer wins";
    } else if (winner == human) {
        cout << "the human won";
    } else {
        cout << "it is a tie";
    }
    
    cout << "\n\n";
}

