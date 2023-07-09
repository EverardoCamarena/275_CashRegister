#include <iomanip>
#include <iostream>
#include <string>
#include <array>

#include "ShoppingBasket.h"
#include "CashRegister.h"
#include "InventoryItem.h"

const int NUM_ITEMS = 6;

void displayItems(std::array<Inventory, NUM_ITEMS>);
void shoppingBasket(std::array<Inventory, NUM_ITEMS> &,
                          std::array <Basket, NUM_ITEMS> &, CashRegister &);
void displayBasket(const std::array <Basket, NUM_ITEMS>);

int main()
{
    CashRegister sales;

    std::array<Inventory, NUM_ITEMS> items { Inventory("Pepsi", 8.34, 3),
                                                          Inventory("Water", 2.75, 3),
                                                          Inventory("Honey", 78.76, 3),
                                                          Inventory("T-Shirt", 34.21, 3),
                                                          Inventory("Radio", 3.45, 13),
                                                          Inventory("Tire", 18.99, 51) };
   
    std::array <Basket, NUM_ITEMS> content{ };

    char repeat = ' ';

    std::cout << "\t                WELCOME TO WALMART!      \n\n";

    do
    {
        shoppingBasket(items, content, sales);

        std::cout << "\nDo you want to buy another item? ";
        std::cin >> repeat;
        std::cout << "\n";

        while (toupper(repeat) != 'Y' && toupper(repeat) != 'N')
        {
            std::cout << "\nDo you wwant to buy another item? ";
            std::cin >> repeat;
        }

        if (toupper(repeat) == 'N')
        {
            std::cout << "     WALMART RECEIPT\n\n";

            displayBasket(content);
            sales.displayReceipt();
           
        }
    } while (toupper(repeat) != 'N');

    std::cin.get();
    std::cin.ignore();
    return 0;
}

void displayItems(std::array<Inventory, NUM_ITEMS> item)
{
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "Item ID\t\t" << "Description\t\t" << "Available\t\t" << "Cost\n\n";

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (item[i].getUnits() > 0)
        {
            std::cout << (i + 1) << "\t\t"
                       << item[i].getDescription() << "\t\t\t"
                         << item[i].getUnits() << "\t\t"
                         << item[i].getCost() << "\n";
        }
        else
        {
            std::cout << (i + 1) << "\t\t"
                       << item[i].getDescription() << "\t\t\t"
                         << "Out of stock\t"
                         << item[i].getCost() << "\n";
        }
    }
}

void shoppingBasket(std::array<Inventory, NUM_ITEMS> &item, std::array <Basket, NUM_ITEMS> &basket,
                          CashRegister &sales)
{
    int iQty = 0;
    int iID = 0;

    displayItems(item);

    std::cout << "\nWhich item do you want to buy? ";
    std::cin >> iID;

    while (iID <= 0 || iID > NUM_ITEMS)
    {
        std::cout << "\nWhich item do you want to buy? (1 through " << NUM_ITEMS << ") ";
        std::cin >> iID;
    }

    std::cout << "How many items do you want to buy? ";
    std::cin >> iQty;

    while (sales.isQuantity(item[iID - 1], iQty) == false)
    {
        std::cout << "How many items do you want to buy? ";
        std::cin >> iQty;
    }   

    sales.setCost(item[iID-1]);
    sales.updateUnits(item[iID - 1]);
    sales.updateRegister();

    basket[iID - 1].setItemInfo(item[iID-1]);
    basket[iID - 1].setNumItems(sales.getQuantity());
}

void displayBasket(const std::array <Basket, NUM_ITEMS> content)
{
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (content[i].getQuantity() > 0)
        {
            std::cout << "ITEM NAME: " << std::setw(28) << content[i].getDescription() << "\n"
                         << "QUANTITY:  " << std::setw(28) << content[i].getQuantity() << "\n"
                         << "COST: "        << std::setw(26)
                         << "$"               << std::setw(7) << content[i].getCost() << "\n\n";
        }   
    }
    std::cout << "---------------------------------------\n\n";
}