//
// Created by Jan Janovec on 14.05.2022.
//

#include "Neighborhood.h"
#include "vector"


Neighborhood::Neighborhood() {
    int index = 0;
    for (int i = 0; i < count; i++) {
        houses[i] = new House();
        cout<<"Creating house at index "<<index<<"."<<std::endl;
        index++;
    }
    index = 0;
    houses[0]->setAnimal("kočka");
    houses[1]->setAnimal("kočka");
    houses[2]->setAnimal("kfdsočka");
    houses[3]->setAnimal("kočka");
    houses[4]->setAnimal("kodsfadfadsfsvcčka");

    houses[0]->setDrink("kočka");
    houses[1]->setDrink("kosfdčka");
    houses[2]->setDrink("kfdsočka");
    houses[3]->setDrink("kosfaadffčka");
    houses[4]->setDrink("kodsfadfadsfsvcčka");

}


House* Neighborhood::whichHouseHasThisDrink(const string& text) {
    House* object = nullptr;
    for(House* house : houses){
        if (house->getDrink() == text) {
            object = house;
        }
    }
    return object;
}

House* Neighborhood::whichHouseHasThisNationality(const string& text) {
    House* object = nullptr;
    for(House* house : houses){
        if (house->getNationality() == text) {
            object = house;
        }
    }
    return object;
}

House* Neighborhood::whichHouseHasThisColor(const string& text) {
    House* object = nullptr;
    for(House* house : houses){
        if (house->getColor() == text) {
            object = house;
        }
    }
    return object;
}

House* Neighborhood::whichHouseHasThisCigarette(const string& text) {
    House* object = nullptr;
    for(House* house : houses){
        if (house->getCigarette() == text) {
            object = house;
        }
    }
    return object;
}

House* Neighborhood::whichHouseHasThisAnimal(const string& text) {
    House* object = nullptr;
    for(House* house : houses){
        if (house->getAnimal() == text) {
            object = house;
        }
    }
    return object;
}

House* Neighborhood::whichHouseHasThisLeftNeighbour(House* house0) {
    House* object = nullptr;
    for(House* house : houses){
        if (house->getLeftNeighbour() == house0) {
            object = house;
        }
    }
    return object;
}

House* Neighborhood::whichHouseHasThisRightNeighboor(House* house0) {
    House* object = nullptr;
    for(House* house : houses){
        if (house->getRightNeighbour() == house0) {
            object = house;
        }
    }
    return object;
}

bool Neighborhood::checkFiveHouses() {
    int size = 0;

    for(House* house : houses){
        size++;
    }

    if (size == 5) {
        cout<<"1a There are five houses."<<std::endl;
        return true;
    } else {
        cout<<"Check Five Houses: false"<<std::endl;
        return false;
    }
}

