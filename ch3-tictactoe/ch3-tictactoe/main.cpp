#include <iostream>

using namespace std;

int main() {
    const int ROWS = 3;
    const int COLUMNS = 3;
    char board[ROWS][COLUMNS] = {{'o', 'x', 'x'}, {'o', 'x', 'o'}, {'x', 'o', 'x'}};
    
    cout << "Here is a tictactoe board:\n";
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << board[i][j];
        }
        
        cout << endl;
    }
    
    cout << "\n'X' moves to the empty location. \n\n";
    
    board[1][0] = 'x';
    
    cout << "now the tictactoe board is in: \n";
    
    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << board[i][j];
        }
        
        cout << endl;
    }
    
    cout << "\n'X' just won!" << endl;
    
    return 0;
    
    
    
}