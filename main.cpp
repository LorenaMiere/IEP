#include<iostream>
#include "car.cpp"

using namespace std;

const char * textS = "Project started";
const char * textE = "Project ended";

int main() {
    cout << textS << endl;

    Components* comp1 = new Components("motor",3300);
    //cout << comp1->getName() << endl;
    Components* comp2 = new Components("wheel",1200);

    Car* car1 = new Car("TM12XAI","black",{*comp1,*comp2},1998);

    cout << car1->getRegistrationNumber() << endl;
    cout << "The car has " << car1->getCarAge(car1->getYearOfFabrication()) << " years old." << endl;

    Components comp3("door",5000); //default constructor
    Components comp4("window",3000);

    cout << "Value of comp3 before copy: " << comp3.getName() << endl;

    //Components comp4(comp3); //copy constructor

    comp3 = comp4; //copy assignment operator

    cout << "Value of comp3 after copy: " << comp3.getName() << endl;

    *comp1 = *comp2;

    cout << "Value of comp1 after copy: " << comp1->getName() << endl;

    delete comp1;
    delete comp2;

    cout << textE << endl;

    return 0;
}