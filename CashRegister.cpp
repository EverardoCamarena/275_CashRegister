#include <iomanip>
#include <iostream>
#include <string>

#include "CashRegister.h"

bool CashRegister::isQuantity(Inventory item, int iQty)
{
    if (item.getUnits() > 0 && iQty <= item.getUnits())
    {
        quantity = iQty;
        return true;
    }
    else if (item.getUnits() == 0)
    {
        quantity = 0;
        std::cout << "\n" << item.getDescription() << " Out Of Stock\n";
        return true;
    }
    else
    {
        std::cout << "\nItem: " << item.getDescription() << "\n";
        std::cout << "Availabe quantity: " << item.getUnits() << "\n";
        return false;
    }

    return false;
}

void CashRegister::setCost(const Inventory item)
{
    cost = item.getCost();
}

void CashRegister::updateUnits(Inventory &item)
{
    item.setUnits(item.getUnits() - getQuantity());
}

void CashRegister::updateRegister()
{
    unitPrice += getUnitPrice() * getQuantity();
    salesTax  += getSalesTax()  * getQuantity();
    subTotal  += getSubTotal()  * getQuantity();
    taxTotal  += getTaxTotal()  * getQuantity();
    total     += getTotal()     * getQuantity();
}

void CashRegister::displayReceipt()
{
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << std::left << "Markup " << std::setw(26)
               << std::right << "$ "        << std::setw(6)
                 << recUnitPrice() << "\n";

    std::cout << std::left << "Sales-Tax " << std::setw(23)
                 << std::right << "$ " << std::setw(6)
                 << recSalesTax() << "\n";

    std::cout << std::left << "Tax-Total " << std::setw(23)
                 << std::right << "$ " << std::setw(6)
                 << recTaxTotal() << "\n\n";

    std::cout << std::left << "Sub-Total " << std::setw(23)
                 << std::right << "$ " << std::setw(6)
                 << recSubTotal() << "\n";

    std::cout << std::left << "Purchase Price " << std::setw(18)
                 << std::right << "$ " << std::setw(6)
                 << recTotal() << "\n";

    std::cout << "\n               WALMART     \n"
               << "\t  THANK YOU FOR SHOPPING WITH US!";
}