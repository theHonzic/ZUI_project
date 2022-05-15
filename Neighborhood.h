//
// Created by Jan Janovec on 14.05.2022.
//

#ifndef ZUI_PROJEKT_NEIGHBORHOOD_H
#define ZUI_PROJEKT_NEIGHBORHOOD_H
#include "iostream"
#include "House.h"

class Neighborhood {
private:
    static const int count = 5;
    House* houses[count];
public:
    Neighborhood();

    House* whichHouseHasThisNationality(const string& text);
    House* whichHouseHasThisDrink(const string& text);
    House* whichHouseHasThisColor(const string& text);
    House* whichHouseHasThisCigarette(const string& text);
    House* whichHouseHasThisAnimal(const string& text);
    House* whichHouseHasThisLeftNeighbour(House* house0);
    House* whichHouseHasThisRightNeighboor(House* house0);

    bool checkAll();
    bool checkFiveHouses();
    bool checkFiveDifferentColors();
    bool checkFiveDifferentNationalities();
    bool checkEveryoneHasAlcohol();
    bool checkEveryoneHasCigarette();
    bool checkEveryoneHasAnimal();
    bool checkEveryoneHasAlcoholCigaretteAnimal();
    bool checkDifferentAlcohol();
    bool checkDifferentCigarette();
    bool checkDifferentAnimal();
    bool checkDifferentAlcoholCigaretteAnimal();

    void printInfo();
    void setRequirements();
};


#endif //ZUI_PROJEKT_NEIGHBORHOOD_H
