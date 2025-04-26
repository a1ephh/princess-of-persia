#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <string>
#include "weapons.h"

using namespace std;

class Shop {
private:
    int coinCounter;
    vector<Weapons> weaponsAvailable;
    vector<Weapons> weaponsPurchased;

    void initializeWeapons();

public:
    Shop(int initialCoins = 0);

    vector<Weapons> getAvailableWeapons() const;
    vector<Weapons> getPurchasedWeapons() const;
    int getCoinCount() const;

    bool purchaseWeapon(int index);
    void earnCoins(int coins);
};

#endif // SHOP_H
