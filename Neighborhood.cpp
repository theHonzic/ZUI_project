//
// Created by Jan Janovec on 14.05.2022.
//

#include "Neighborhood.h"
#include "vector"
#include "map"


Neighborhood::Neighborhood() {
    int index = 0;
    for (int i = 0; i < count; i++) {
        houses[i] = new House();
        cout<<"Creating house at index "<<index<<"."<<std::endl;
        index++;
    }
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

    houses[0]->setCigarette("kočka");
    houses[1]->setCigarette("kosfdčka");
    houses[2]->setCigarette("kfdsočka");
    houses[3]->setCigarette("kosfaadffčka");
    houses[4]->setCigarette("kjh");

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

bool Neighborhood::checkFiveDifferentColors() {

    std::vector<std::string> used;
    for (int i=0; i<=5-1; i++){
        used.push_back(houses[i]->getColor());
    }

    std::map<std::string, int> countMap;
    for (auto & elem : used){
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if (result.second == false) result.first->second++;
    }

    bool success = true;
    for (auto & elem : countMap){
        if (elem.second > 1){
            cout<<"There are some duplicates:"<<std::endl;
            cout << elem.first << ": " << elem.second <<"times."<< std::endl;
            success = false;
        }
    }
    if (success) cout<<"1b The houses have different colors."<<std::endl;
    return success;
}

bool Neighborhood::checkFiveDifferentNationalities() {
    std::vector<std::string> used;

    for (int i=0; i<=5-1; i++){
        used.push_back(houses[i]->getNationality());
    }

    std::map<std::string, int> countMap;
    for (auto & elem : used){
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if (result.second == false) result.first->second++;
    }

    bool success = true;
    for (auto & elem : countMap){
        if (elem.second > 1){
            cout<<"There are some duplicates:"<<std::endl;
            cout << elem.first << ": " << elem.second <<"times."<< std::endl;
            success = false;
        }
    }
    if (success) cout<<"2 The houses have different nationalities."<<std::endl;
    return success;
}

bool Neighborhood::checkEveryoneHasAlcohol() {
    std::vector<std::string> used;
    for (int i=0; i<=5-1; i++){
        if (!houses[i]->getDrink().empty()) used.push_back(houses[i]->getCigarette());
    }

    if (used.size() == 5){
        return true;
    } else {
        std::cout<<"Not every house has alcohol assigned."<<std::endl;
        return false;
    }
}

bool Neighborhood::checkEveryoneHasCigarette() {
    std::vector<std::string> used;
    for (int i=0; i<=5-1; i++){
        if (!houses[i]->getCigarette().empty()) used.push_back(houses[i]->getCigarette());
    }

    if (used.size() == 5){
        return true;
    } else {
        std::cout<<"Not every house has cigarette assigned."<<std::endl;
        return false;
    }
}

bool Neighborhood::checkEveryoneHasAnimal() {
    std::vector<std::string> used;
    for (int i=0; i<=5-1; i++){
        if (!houses[i]->getAnimal().empty()) used.push_back(houses[i]->getAnimal());
    }

    if (used.size() == 5){
        return true;
    } else {
        std::cout<<"Not every house has animal assigned."<<std::endl;
        return false;
    }
}

bool Neighborhood::checkEveryoneHasAlcoholCigaretteAnimal() {
    if (checkEveryoneHasAlcohol() && checkEveryoneHasCigarette() && checkEveryoneHasCigarette()){
        cout<<"Every house has alcohol, cigarette and animal assigned."<<std::endl;
        return true;
    } else {
        return false;
    }
}

bool Neighborhood::checkDifferentAlcohol() {
    std::vector<std::string> used;
    for (int i=0; i<=5-1; i++){
        used.push_back(houses[i]->getDrink());
    }

    std::map<std::string, int> countMap;
    for (auto & elem : used){
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if (result.second == false) result.first->second++;
    }

    bool success = true;
    for (auto & elem : countMap){
        if (elem.second > 1){
            cout<<"There are some duplicates:"<<std::endl;
            cout << elem.first << ": " << elem.second <<"times."<< std::endl;
            success = false;
        }
    }
    if (!success) cout<<"The houses do not have different alcohol."<<std::endl;
    return success;
}

bool Neighborhood::checkDifferentCigarette() {
    std::vector<std::string> used;
    for (int i=0; i<=5-1; i++){
        used.push_back(houses[i]->getCigarette());
    }

    std::map<std::string, int> countMap;
    for (auto & elem : used){
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if (result.second == false) result.first->second++;
    }

    bool success = true;
    for (auto & elem : countMap){
        if (elem.second > 1){
            cout<<"There are some duplicates:"<<std::endl;
            cout << elem.first << ": " << elem.second <<"times."<< std::endl;
            success = false;
        }
    }
    if (!success) cout<<"The houses do not have different cigarette."<<std::endl;
    return success;
}

bool Neighborhood::checkDifferentAnimal() {
    std::vector<std::string> used;
    for (int i=0; i<=5-1; i++){
        used.push_back(houses[i]->getAnimal());
    }

    std::map<std::string, int> countMap;
    for (auto & elem : used){
        auto result = countMap.insert(std::pair<std::string, int>(elem, 1));
        if (result.second == false) result.first->second++;
    }

    bool success = true;
    for (auto & elem : countMap){
        if (elem.second > 1){
            cout<<"There are some duplicates:"<<std::endl;
            cout << elem.first << ": " << elem.second <<"times."<< std::endl;
            success = false;
        }
    }
    if (!success) cout<<"The houses do not have different animal."<<std::endl;
    return success;
}

bool Neighborhood::checkDifferentAlcoholCigaretteAnimal() {
    if (checkDifferentAlcohol() && checkDifferentCigarette() && checkDifferentAnimal()){
        std::cout<<"Every house has different alcohol, cigarette and animal assigned."<<std::endl;
        return true;
    } else {
        std::cout<<"Every house does not have different alcohol, cigarette and animal assigned."<<std::endl;
        return false;
    }
}
