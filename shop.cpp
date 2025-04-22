#include "shop.h"
using namespace std;

Shop::Shop(int initialCoins) : coinCounter(initialCoins) {}

void Shop::addWeaponToShop(const Weapons& weapon) {
    weaponsAvailable.push_back(weapon);
}

void Shop::displayWeaponsAvailable() const {
    cout << "Available Weapons:\n";
    for (size_t i = 0; i < weaponsAvailable.size(); ++i) {
        cout << i + 1 << ". " << weaponsAvailable[i].getWeaponName()
        << " (Damage: " << weaponsAvailable[i].getWeaponDamage() << ")\n";
    }
}

bool Shop::purchaseWeapon(int index) {
    if (index < 1 || index > static_cast<int>(weaponsAvailable.size())) {
        cout << "Invalid selection.\n";
        return false;
    }

    if (coinCounter < 1) {
        cout << "Not enough coins to purchase weapon.\n";
        return false;
    }

    Weapons selected = weaponsAvailable[index - 1];
    weaponsPurchased.push_back(selected);
    coinCounter--;
    cout << selected.getWeaponName() << " purchased successfully!\n";
    return true;
}

void Shop::earnCoins(int coins) {
    coinCounter += coins;
}

int Shop::getCoinCount() const {
    return coinCounter;
}

vector<Weapons> Shop::getPurchasedWeapons() const {
    return weaponsPurchased;
}
