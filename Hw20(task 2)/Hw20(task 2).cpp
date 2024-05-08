#include "Plane.h"

int main()
{
    Plane plane1;

    plane1.showInfo();
    cout << "-------------------------------" << endl;
    plane1.sellTicket("Vasya");
    plane1.showInfo();
    cout << "-------------------------------" << endl;
    plane1.returnTicket("Vasya");
    plane1.showInfo();
}