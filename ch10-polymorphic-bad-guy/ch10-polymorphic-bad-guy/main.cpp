#include <iostream>

using namespace std;

class Enemy {
public:
    Enemy(int damage = 10);
    virtual ~Enemy();
    void virtual Attack() const;
protected:
    int* m_pDamage;
};

Enemy::Enemy(int damage) {
    m_pDamage = new int(damage);
}

Enemy::~Enemy() {
    cout << "In Enemy destructor, deleting m_pDamage";
    delete m_pDamage;
    m_pDamage = 0;
}

void Enemy::Attack() const {
    cout << "An enemy attack and inflicts " << *m_pDamage << " damage points";
}

class Boss : public Enemy {
public:
    Boss(int multiplier = 3);
    virtual ~Boss();
    void virtual Attack() const;
protected:
    int* m_pMultiplier;
};

Boss::Boss(int multiplier) {
    m_pMultiplier = new int(multiplier);
}

Boss::~Boss() {
    cout <<"in the boss destructor, deleting m_pMultiplier\n";
}

void Boss::Attack() const {
    cout << "a boss attacks and inflicts " << (*m_pMultiplier) * (*m_pDamage) << " damage points";
}



int main() {
    
    cout << "calling attack() on boss object through pointer to enemy:\n";
    Enemy* pBadGuy = new Boss();
    pBadGuy->Attack();
    
    cout << "\n\nDeleting pointer to Enemy:\n";
    delete pBadGuy;
    pBadGuy = 0;
    
    return 0;
}