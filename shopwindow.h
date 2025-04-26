#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QDialog>
#include "shop.h"

namespace Ui {
class ShopWindow;
}

class ShopWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShopWindow(QWidget *parent = nullptr);
    ~ShopWindow();

private slots:
    void on_buttonBuyWeapon_clicked();

private:
    Ui::ShopWindow *ui;
    Shop shop;

    void updateWeaponTable();
    void updateCoinDisplay();
};

#endif // SHOPWINDOW_H
