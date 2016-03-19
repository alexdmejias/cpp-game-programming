#include <iostream>

using namespace std;

void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* const array, const int NUM_ELEMENTS);


int main() {
    
    cout << "creating an array of high scores.\n\n";
    
    const int NUM_SCORES = 3;
    int highScores[NUM_SCORES] = {5000, 3500, 2700};
    
    cout << "Displays scores using array name as a constant pointer.\n";
    
    cout << *highScores << endl;
    cout << *(highScores + 1) << endl;
    cout << *(highScores + 2) << "\n\n";
    
    cout << "increasing scores by passing array as a constant pointer.\n\n";
    increase(highScores, NUM_SCORES);
    cout << "displaying scores by passing array as a constant pointer to a constant.\n";
    display(highScores, NUM_SCORES);
    
    
    return 0;
}

void increase(int* const array, const int NUM_ELEMENTS) {
    for(int i = 0; i < NUM_ELEMENTS; i++) {
        array[i] += 500;
    }
}

void display(const int* const array, const int NUM_ELEMENTS) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << array[i] << endl;
    }
}