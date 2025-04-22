#include "weapons.h"
using namespace std;

Weapons::Weapons(string name, double damage)
    : weaponName(name), weaponDamage(damage) {}

string Weapons::getWeaponName() const {
    return weaponName;
}

double Weapons::getWeaponDamage() const {
    return weaponDamage;
}

void Weapons::setWeaponName(const string& name) {
    weaponName = name;
}

void Weapons::setWeaponDamage(double damage) {
    weaponDamage = damage;
}
