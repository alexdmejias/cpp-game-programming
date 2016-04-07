#include <iostream>

using namespace std;

class Enemy {
public:
    int m_Damage;
    Enemy();
    void attack() const;

};

Enemy::Enemy():
    m_Damage(10)
{}

void Enemy::attack() const {
    cout << "attack inflicts " << m_Damage << " damage points" << endl;
}

class Boss : public Enemy {
public:
    int m_DamageMultiplier;
    Boss();
    void SpecialAttack() const;
};

Boss::Boss():
    m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const {
    cout << "Special attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage points" << endl;
}

int main() {
    cout << "creating an enemy" << endl;
    Enemy enemy;
    enemy.attack();
    
    cout << "\nCreating a boss.\n";
    Boss boss;
    boss.SpecialAttack();
    return 0;
}