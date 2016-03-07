#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);

int main() {
    cout << "Welcome to the Mad Lib game";
    cout << "Answer the following questions to help create a new story.\n";
    
    string name = askText("please enter a name: ");
    string noun = askText("please enter a plural noun: ");
    int number = askNumber("please enter a number: ");
    string bodyPart = askText("please enter a body part: ");
    string verb = askText("please enter a verb: ");
    
    tellStory(name, noun, number, bodyPart, verb);
    
    
    return 0;
}

string askText(string propmpt) {
    string text;
    cout << propmpt;
    cin >> text;
    return text;
}

int askNumber(string prompt) {
    int number;
    cout << prompt;
    cin >> number;
    return number;
}

void tellStory(string name, string noun, int number, string bodyPart, string verb) {
    cout << "\nhere is your story:\n";
    cout << "the famous explorer " << name << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of " << noun << " when one day, the " << noun << " found the explorer.\n";
    cout << "Surrounded by " << number << " " << noun << ", a tear came to " << name << "'s ";
    cout << bodyPart << ".\n" << "After all this time, the quest was finally over. ";
    cout << "And then, the  " << noun << "\nprompty devoured " << name << ". ";
    cout << "\n\nThe moral of the story? Becareful what you " << verb << " for.";
}