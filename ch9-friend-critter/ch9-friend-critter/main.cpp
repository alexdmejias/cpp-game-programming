#include <iostream>
#include <string>

using namespace std;

class Critter {
    friend void Peek(const Critter& aCritter);
    friend ostream& operator<<(ostream& os, const Critter& aCritter);
public:
    Critter(const string& name="");
private:
    string m_Name;
};

Critter::Critter(const string& name):
m_Name(name)
{}

void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main() {
    Critter crit("Poochie");
    
    cout << "calling Peek() to access crit's private dat memeber, m_Name: \n";
    Peek(crit);
    
    cout << "\nSending crit object to cout with the << operator:\n";
    cout << crit;
    
    return 0;
}

void Peek(const Critter& aCritter) {
    cout << aCritter.m_Name << endl;
}

ostream& operator<<(ostream& os, const Critter& aCritter) {
    os << "Critter object - ";
    os << "m_Name: " << aCritter.m_Name;
    return os;
}

