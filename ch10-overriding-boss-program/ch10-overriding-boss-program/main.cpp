#include <iostream>

using namespace std;

class Enemy {
public:
    Enemy(int damage = 10);
    void virtual Taunt() const;
    void virtual Attack() const;
private:
    int m_Damage;
};

Enemy::Enemy(int damage):
m_Damage(damage)
{}

void Enemy::Taunt() const {
    cout << "the enemy says he will fight you\n";
}

void Enemy::Attack() const {
    cout << "attack! inflicts " << m_Damage << " damage points";
}

class Boss : public Enemy {
public:
    Boss(int damage = 30);
    void virtual Taunt() const;
    void virtual Attack() const;
};

Boss::Boss(int damage):
Enemy(damage)
{}

void Boss::Attack() const {
    Enemy::Attack();
    cout << " and laughs at you\n";
}

void Boss::Taunt() const {
    cout << "the boss says he will end your pitiful existence";
}

int main() {
    cout << "Enemy object:\n";
    Enemy enemy;
    enemy.Taunt();
    enemy.Attack();
    
    cout << "\n\nBoss object:\n";
    Boss boss;
    boss.Taunt();
    boss.Attack();
    
    return 0;
}