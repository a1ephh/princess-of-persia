#include "shop.h"

Shop::Shop(int initialCoins) : coinCounter(initialCoins) {
    initializeWeapons();
}

void Shop::initializeWeapons() {
    weaponsAvailable.push_back(Weapons("Sword", 10.0));
    weaponsAvailable.push_back(Weapons("Bow", 7.5));
    weaponsAvailable.push_back(Weapons("Axe", 12.5));
    weaponsAvailable.push_back(Weapons("Dagger", 5.0));
    weaponsAvailable.push_back(Weapons("Magic Staff", 15.0));
    weaponsAvailable.push_back(Weapons("Fire Arrow", 9.0));
    weaponsAvailable.push_back(Weapons("Double Blade", 18.0));
}

vector<Weapons> Shop::getAvailableWeapons() const {
    return weaponsAvailable;
}

vector<Weapons> Shop::getPurchasedWeapons() const {
    return weaponsPurchased;
}

int Shop::getCoinCount() const {
    return coinCounter;
}

bool Shop::purchaseWeapon(int index) {
    if (index < 0 || index >= static_cast<int>(weaponsAvailable.size()))
        return false;
    if (coinCounter < 1)
        return false;
    Weapons selected = weaponsAvailable[index];
    weaponsPurchased.push_back(selected);
    coinCounter--;
    return true;
}

void Shop::earnCoins(int coins) {
    coinCounter += coins;
}

