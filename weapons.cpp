#include "weapons.h"

Weapons::Weapons(string name, double damage) : weaponName(name), weaponDamage(damage) {}

string Weapons::getWeaponName() const {
    return weaponName;
}

double Weapons::getWeaponDamage() const {
    return weaponDamage;
}


