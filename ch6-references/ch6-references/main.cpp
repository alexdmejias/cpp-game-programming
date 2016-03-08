#include <iostream>

using namespace std;

int main() {
    int myScore = 1000;
    int& mikeScore = myScore;
    
    cout << "myScoore is " << myScore << "\n";
    cout << "mikeScore is" << mikeScore << "\n\n";
    
    cout << "increasing myScore by 500\n";
    myScore += 500;
    cout << "myScore is " << myScore << "\n";
    cout << "mikeScore is " << mikeScore << "\n";
    
    cout << "increasing mikeScore by 500\n";
    mikeScore += 500;
    cout << "myScore is " << myScore << "\n";
    cout << "mikeScore is " << mikeScore << "\n";
    
    
    return 0;
}