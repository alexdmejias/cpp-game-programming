#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "do you feel you are banging your head against something?"},
        {"glasses", "these might help you see the answer"},
        {"labored", "going slowly, is it?"},
        {"persistent", "keep at it"},
        {"jumble", "it's what this game is all about"}
    };
    
    srand(static_cast<unsigned int>(time(0)));
    
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    
    string jumble = theWord;
    int len = jumble.size();
    for (int i = 0; i < len; i++) {
        int index1 = (rand() % len);
        int index2 = (rand() % len);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }
    
    
    cout << "\t\t welcome to the jumble\n";
    cout << "unscramble the letters to make a word.\n";
    cout << "Enter 'hint' for a a hint.\n";
    cout << "Enter 'quit' to quit the game";
    cout << "the jumble is: " << jumble;
    
    string guess;
    cout << "\n\nyour guess: ";
    cin >> guess;
    
    while ((guess != theWord) && (guess != "quit")) {
        if (guess == "hint") {
            cout << theHint;
        } else {
            cout << "sorry, that is not it";
        }
        
        cout << "\n\nyour guess: ";
        cin >> guess;
        
    }
    
    if (guess == theWord) {
        cout << "\nthat's it, you guessed it";
    }
    
    cout << "\nthanks for playing. \n";
    
    
    return 0;
}