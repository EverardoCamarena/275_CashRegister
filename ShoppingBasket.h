#ifndef SHOPPING_BASKET_H
#define SHOPPING_BASKET_H

#include <string>

#include "InventoryItem.h"

class Basket
{
private:
    std::string description;       
    int numItems;                      
    double cost;                        

public:
    Basket()
    {
        description = " ";
        numItems = 0;
        cost = 0.0;
    }

    Basket(int iQty)
    {
        numItems = iQty;
    }

    
    void setItemInfo(const Inventory item)
    {
        description = item.getDescription();
        cost = item.getCost();
    }

    void setNumItems(int iQty)
    { numItems += iQty; }

    int getQuantity() const
    { return numItems; }

    std::string getDescription() const
    { return description; }

    double getCost() const
    { return cost; }
};
#endif