#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "InventoryItem.h"

class CashRegister
{
    private:
        int    quantity;       
        double cost;               
        double markup; //markup 30%
        double taxRate; //tax rate 6%
        double unitPrice;            
        double salesTax; //sales tax 6%
        double taxTotal;            
        double subTotal;            
        double total;                

    public:
        CashRegister(double iMarkup = 0.30, double rate = 0.06)
        {
            markup = iMarkup;
            taxRate = rate;

            unitPrice = 0.0;
            salesTax = 0.0;
            subTotal = 0.0;
            taxTotal = 0.0;
            total = 0.0;
        }

        void setCost(const Inventory item);
        bool isQuantity(Inventory item, int iQty);
        void updateRegister();
        void updateUnits(Inventory &item);
        void displayReceipt();

        double getCost() const
        { return cost; }

        double getUnitPrice() const
        { return (getCost() * markup); }

        double getSalesTax() const
        { return (getCost() * taxRate); }

        double getTaxTotal() const
        { return (getCost() * taxRate) + getUnitPrice(); }

        double getSubTotal() const
        { return (getUnitPrice() + getCost()); }

        double getTotal() const
        { return (getSubTotal() + getSalesTax()); }

        int getQuantity() const
        { return quantity; }

        double recUnitPrice() const
        { return unitPrice; }

        double recSalesTax() const
        { return salesTax; }

        double recTaxTotal() const
        { return taxTotal; }

        double recSubTotal() const
        { return subTotal; }

        double recTotal() const
        { return total; }
};
#endif