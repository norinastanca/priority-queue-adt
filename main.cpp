#include <iostream>
#include "CoadaCuPrioritati.h"
#include "TestScurt.h"
#include "TestExtins.h"

using namespace std;

int main() {
    testAll();
    cout << "Testele scurte au trecut cu succes!" << endl;


    testAllExtins();
    cout << "Testele extinse au trecut cu succes!" << endl;



    return 0;
}