#include <iostream>

using namespace std;

class Critter{
public:
    int m_Hunger;
    Critter(int hunger = 0);
    void Greet();
};

// member initializer list
Critter::Critter(int hunger): m_Hunger(hunger)
{
    cout << "A new critter has been born\n\n";
    
}

//Critter::Critter(int hunger) {
//    cout << "A new critter has been born\n\n";
//    m_Hunger = hunger;
//}

void Critter::Greet() {
    cout << "Hi. I'm a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main() {
    Critter crit(7);
    
    crit.Greet();
    
    
    return 0;
}