#ifndef WEAPONS_H
#define WEAPONS_H

#include <string>

using namespace std;

class Weapons {
private:
    string weaponName;
    double weaponDamage;

public:
    Weapons(string name = "", double damage = 0.0);

    string getWeaponName() const;
    double getWeaponDamage() const;

    void setWeaponName(const string& name);
    void setWeaponDamage(double damage);
};

#endif // WEAPONS_H
