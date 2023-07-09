#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H

#include <string>

class Inventory
{
    private:
        std::string description;        
              double cost;                    
              int units;               
       
    public:
        Inventory()                            
        {
            description = " ";
            cost = 0.0;
            units = 0;
        }

        // Constructor accepting arguments for description, cost and units
        Inventory(std::string desc, double c, int u)
        {
            description = desc;
            cost = c;
            units = u;
        }

        void setDescription(std::string desc)
        { description = desc; }

        void setCost(double c)
        { cost = c; }

        void setUnits(int u)
        { units = u; }

        std::string getDescription() const
        { return description; }

        double getCost() const
        { return cost; }

        int getUnits()
        { return units; }
};
#endif