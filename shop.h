#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <string>
#include <iostream>
#include "weapons.h"

using namespace std;

class Shop {
private:
    int coinCounter;
    vector<Weapons> weaponsAvailable;
    vector<Weapons> weaponsPurchased;

public:
    Shop(int initialCoins = 0);

    void addWeaponToShop(const Weapons& weapon);
    void displayWeaponsAvailable() const;
    bool purchaseWeapon(int index);
    void earnCoins(int coins);
    int getCoinCount() const;
    vector<Weapons> getPurchasedWeapons() const;
};

#endif // SHOP_H
