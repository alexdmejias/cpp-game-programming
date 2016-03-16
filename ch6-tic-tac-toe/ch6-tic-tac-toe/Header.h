#ifndef Header_h
#define Header_h

#include <string>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();

char askYesNo(string question);

int askNumber(string question, int high, int low = 0);

char humanPiece();

char opponent(char piece);

void displayBoard(const vector<char>& board);

char winner(const vector<char>& board);

bool isLegal(const vector<char> board, int move);

int humanMove(const vector<char>& board, char human);

int computerMove(vector<char> board, char computer);

void announceWinner(char winner, char computer, char human);

#endif /* Header_h */
