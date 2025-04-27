#include "shopwindow.h"
#include "ui_shopwindow.h"
#include <QMessageBox>

ShopWindow::ShopWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShopWindow)
    , shop(0)
{
    ui->setupUi(this);
    ui->tableWeapons->setColumnCount(2);
    ui->tableWeapons->setHorizontalHeaderLabels(QStringList()<<"Weapon Name" << "Damage");
    ui->tableWeapons->horizontalHeader()->setStretchLastSection(true);
    ui->tableWeapons->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWeapons->verticalHeader()->setVisible(false);
    ui->tableWeapons->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWeapons->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWeapons->setShowGrid(false);


    updateWeaponTable();
    updateCoinDisplay();
}

ShopWindow::~ShopWindow()
{
    delete ui;
}

void ShopWindow::updateWeaponTable() {

    vector<Weapons> available = shop.getAvailableWeapons();

    ui->tableWeapons->setRowCount(static_cast<int>(available.size()));

    ui->tableWeapons->setColumnCount(2);
    ui->tableWeapons->setHorizontalHeaderLabels(QStringList() << "Weapon Name" << "Damage");

    QFont font;
    font.setPointSize(40);


    for (int i = 0; i < static_cast<int>(available.size()); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(available[i].getWeaponName()));
        QTableWidgetItem *damageItem = new QTableWidgetItem(QString::number(available[i].getWeaponDamage()));

        nameItem->setTextAlignment(Qt::AlignCenter);
        damageItem->setTextAlignment(Qt::AlignCenter);

        nameItem->setFont(font);
        damageItem->setFont(font);
        ui->tableWeapons->setRowHeight(i, 50);

        ui->tableWeapons->setItem(i, 0, nameItem);
        ui->tableWeapons->setItem(i, 1, damageItem);

}

    ui->tableWeapons->resizeColumnsToContents();
    ui->tableWeapons->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void ShopWindow::updateCoinDisplay()
{
    ui->labelCoins->setText("Coins: " + QString::number(shop.getCoinCount()));
}

void ShopWindow::on_buttonBuyWeapon_clicked()
{
    int selectedRow = ui->tableWeapons->currentRow();  // Get selected weapon

    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a weapon to buy!");
        return;
    }

    bool success = shop.purchaseWeapon(selectedRow);
    if (success) {
        QMessageBox::information(this, "Purchase Successful", "You have bought the weapon!");
        updateWeaponTable();
        updateCoinDisplay();
    } else {
        QMessageBox::critical(this, "Purchase Failed", "You don't have enough coins to buy!");
    }


}
