//
// Created by Jan Janovec on 22.04.2022.
//

#include "House.h"

House::House() {
    m_nationality="";
    m_color="";
    m_cigarette="";
    m_drink="";
    m_animal="";

    m_left = nullptr;
    m_right = nullptr;
}

void House::setNationality(string nationality) {
    this->m_nationality = nationality;
}

string House::getNationality() {
    return this->m_nationality;
}

void House::setColor(string color) {
    this->m_color = color;
}

string House::getColor() {
    return this->m_color;
}

void House::setCigarette(string cigarette) {
    this->m_cigarette = cigarette;
}

string House::getCigarette() {
    return this->m_cigarette;
}

void House::setDrink(string drink) {
    this->m_drink = drink;
}

string House::getDrink() {
    return this->m_drink;
}

void House::setAnimal(string animal) {
    this->m_animal = animal;
}

string House::getAnimal() {
    return this->m_animal;
}

void House::setLeftNeighbour(House *house) {
    this->m_left = house;
    if(house->getRightNeighbour() == nullptr) house->setRightNeighbour(this);
}

House *House::getLeftNeighbour() {
    return this->m_left;
}

void House::setRightNeighbour(House *house) {
    this->m_right = house;
    if (house->getLeftNeighbour() == nullptr) house->setLeftNeighbour(this);
}

House *House::getRightNeighbour() {
    return this->m_right;
}

void House::printInfo() {
    cout<<"Nationality: "<< this->getNationality()<<endl;
    cout<<"Color: "<< this->getColor()<<endl;
    cout<<"Cigarette: "<< this->getCigarette()<<endl;
    cout<<"Drink: "<< this->getDrink()<<endl;
    cout<<"Animal: "<< this->getAnimal()<<endl;
    cout<<"----------------------Left Neighbour Info----------------------"<<endl;
    if (getLeftNeighbour() != nullptr) getLeftNeighbour()->printNeighbourInfo();
    if (getLeftNeighbour() == nullptr) cout<<"Unknown"<<endl;
    cout<<"---------------------Right Neighbour Info----------------------"<<endl;
    if (getRightNeighbour() != nullptr) getRightNeighbour()->printNeighbourInfo();
    if (getRightNeighbour() == nullptr) cout<<"Unknown"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
}

void House::printNeighbourInfo() {
    cout<<"Nationality: "<< this->getNationality()<<endl;
    cout<<"Color: "<< this->getColor()<<endl;
    cout<<"Cigarette: "<< this->getCigarette()<<endl;
    cout<<"Drink: "<< this->getDrink()<<endl;
    cout<<"Animal: "<< this->getAnimal()<<endl;
}
