#include <iostream>
#include "array"
#include "House.h"
#include "Neighborhood.h"
using namespace std;


int main() {
    Neighborhood neighborhood = Neighborhood();
    //1a there are five houses
    neighborhood.checkFiveHouses();
    //1b in 5 different colors
    neighborhood.checkFiveDifferentColors();

}