#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "weapon.h"
#include "equipment.h"
#include "character.h"

using namespace std;

int main()
{
    Character amy("amy");
    cout << amy.getStrength() << endl;
    amy.changeAttributes(1, 50);
    cout << amy.getStrength() << endl;
    return 0;
}
