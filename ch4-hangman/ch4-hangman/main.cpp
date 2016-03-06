#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main() {
    const int MAX_WRONG = 8;
    vector<string> words;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];
    
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";
    
    cout << "Welcome to Hangman. good luck!\n";
    
    while((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        cout << "\n\nyou have " << MAX_WRONG - wrong;
        cout << " incorrect guesses left.\n";
        cout << "\nyou've have the following letters:\n" << used << endl;
        cout << "\nso far, the words:\n" << soFar << endl;
        
        char guess;
        cout << "\n\nenter your guess: ";
        cin >> guess;
        guess = toupper(guess);
        while (used.find(guess) != string::npos) {
            cout << "\nyou've already guessed " << guess << endl;
            cout << "enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        
        
        
        used += guess;
        
        if (THE_WORD.find(guess) != string::npos) {
            cout << "that's right " << guess << " is in the word.\n";
            for (int i = 0; i < THE_WORD.length(); ++i) {
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        } else {
            cout << "sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    
    
    if (wrong == MAX_WRONG) {
        cout << "\nyou've been hanged";
    } else {
        cout << "\nyou guessed it";
    }
    
    cout << "\nthe word was " << THE_WORD << endl;
    
    return 0;
}