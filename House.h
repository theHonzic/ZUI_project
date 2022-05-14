//
// Created by Jan Janovec on 22.04.2022.
//

#ifndef ZUI_PROJEKT_HOUSE_H
#define ZUI_PROJEKT_HOUSE_H

#include <iostream>

using namespace std;
class House {
private:
    string m_nationality;
    string m_color;
    string m_cigarette;
    string m_drink;
    string m_animal;

    House* m_left;
    House* m_right;

public:
    House();
    void setNationality(string nationality);
    string getNationality();
    void setColor(string color);
    string getColor();
    void setCigarette(string cigarette);
    string getCigarette();
    void setDrink(string drink);
    string getDrink();
    void setAnimal(string animal);
    string getAnimal();

    void setLeftNeighbour(House* house);
    House* getLeftNeighbour();
    void setRightNeighbour(House* house);
    House* getRightNeighbour();

    void printInfo();
    void printNeighbourInfo();
};


#endif //ZUI_PROJEKT_HOUSE_H
