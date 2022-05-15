#include <iostream>
#include "House.h"
#include "Neighborhood.h"
using namespace std;


int main() {
    Neighborhood neighborhood = Neighborhood();

    neighborhood.setRequirements();
    neighborhood.printInfo();
    neighborhood.checkAll();
}