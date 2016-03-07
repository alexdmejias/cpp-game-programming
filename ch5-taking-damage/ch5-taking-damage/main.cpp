#include <iostream>

using namespace std;

int radiation(int health);

int main() {
    
    int health = 80;
    
    cout << "your health: " << health << "\n\n";
    
    health = radiation(health);
    cout << "after radiation, your health is now: " << health << "\n\n";
    
    health = radiation(health);
    cout << "after radiation, your health is now: " << health << "\n\n";
    
    health = radiation(health);
    cout << "after radiation, your health is now: " << health << "\n\n";
    
    return 0;
}

int radiation(int health) {
    return health / 2;
}