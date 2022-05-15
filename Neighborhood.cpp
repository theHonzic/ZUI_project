//
// Created by Jan Janovec on 14.05.2022.
//

#include "Neighborhood.h"
#include "vector"
#include "map"


Neighborhood::Neighborhood() {
    int index = 0;
    for (auto & house : houses) {
        house = new House();
        cout<<"Creating house at index "<<index<<"."<<std::endl;
        index++;
    }
/*
    houses[0]->setAnimal("dog");
    houses[1]->setAnimal("cat");
    houses[2]->setAnimal("dolphin");
    houses[3]->setAnimal("monkey");
    houses[4]->setAnimal("donkey");

    houses[0]->setDrink("coke");
    houses[1]->setDrink("beer");
    houses[2]->setDrink("milk");
    houses[3]->setDrink("water");
    houses[4]->setDrink("sprite");

    houses[0]->setCigarette("dunno");
    houses[1]->setCigarette("dont");
    houses[2]->setCigarette("lm");
    houses[3]->setCigarette("camel");
    houses[4]->setCigarette("marneco");

    houses[0]->setNationality("czech");
    houses[1]->setNationality("slovak");
    houses[2]->setNationality("german");
    houses[3]->setNationality("italian");
    houses[4]->setNationality("colombian");

    houses[0]->setColor("red");
    houses[1]->setColor("grey");
    houses[2]->setColor("green");
    houses[3]->setColor("yellow");
    houses[4]->setColor("black");
*/


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
    if (checkEveryoneHasAlcohol() && checkEveryoneHasCigarette() && checkEveryoneHasAnimal()){
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

bool Neighborhood::checkAll() {
    bool firstConditionA = checkFiveHouses();
    bool firstConditionB = checkFiveDifferentColors();
    bool firstCondition = firstConditionA && firstConditionB;
    bool secondCondition = checkFiveDifferentNationalities();
    bool thirdCondition = checkEveryoneHasAlcoholCigaretteAnimal();
    bool fourthCondition = checkDifferentAlcoholCigaretteAnimal();

    if (firstCondition && secondCondition && thirdCondition && fourthCondition){
        std::cout<<"All conditions are true."<<std::endl;
        return true;
    } else {
        return false;
    }
}

void Neighborhood::printInfo() {
    for (auto & house : houses) {
        house->printInfo();
    }
}

void Neighborhood::setRequirements() {
    //nor žije v prvním domě
    houses[0]->setNationality("nor");
    //nor žije vedle modrého domu
    houses[1]->setColor("modra");
    whichHouseHasThisColor("modra")->setLeftNeighbour(whichHouseHasThisNationality("nor"));
    //ten, co žije ve středním domě pije mléko
    houses[2]->setDrink("mleko");
    houses[2]->setLeftNeighbour(houses[1]);
    //obyvatel zeleného domu pije kávu
    houses[3]->setColor("zelena");
    houses[3]->setDrink("kava");
    //zelený dům je nalevo od bílého
    houses[4]->setColor("bila");
    whichHouseHasThisColor("bila")->setLeftNeighbour(whichHouseHasThisColor("zelena"));
    //angličan žije v červeném domě
    houses[2]->setColor("cervena");
    whichHouseHasThisColor("cervena")->setNationality("anglican");
    //obyvatel žlutého domu kouří dunhill
    houses[0]->setColor("zluta");
    whichHouseHasThisColor("zluta")->setCigarette("dunhill");
    //ten, co chová koně, žije vedle toho, kdo kouří dunhill
    whichHouseHasThisLeftNeighbour(whichHouseHasThisCigarette("dunhill"))->setAnimal("kun");
    //ten, co kouří blend, má souseda, který pije vodu
    houses[0]->setDrink("voda");
    whichHouseHasThisLeftNeighbour(whichHouseHasThisDrink("voda"))->setCigarette("blend");
    //ten, co kouří blue master, pije pivo
    houses[4]->setCigarette("blue master");
    whichHouseHasThisCigarette("blue master")->setDrink("pivo");
    //sved chova psy
    houses[3]->setNationality("sved");
    whichHouseHasThisNationality("sved")->setAnimal("pes");
    //ten, co kouri pall mall, chova ptaky
    houses[2]->setCigarette("pall mall");
    whichHouseHasThisCigarette("pall mall")->setAnimal("ptak");
    //dan pije caj
    houses[1]->setNationality("dan");
    whichHouseHasThisNationality("dan")->setDrink("caj");
    //ten, co kouri blend zije vedle toho, kdo chova kocky
    whichHouseHasThisRightNeighboor(whichHouseHasThisCigarette("blend"))->setAnimal("kocka");
    //nemec kouri prince
    houses[4]->setNationality("nemec");
    whichHouseHasThisNationality("nemec")->setCigarette("prince");
}

House *Neighborhood::whichHouseHasFish() {
    House* result;
    for (House* house : houses){
        if (house->getAnimal() == ""){
            result = house;
        }
    }
    return result;
}
