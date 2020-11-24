#include<iostream>
#include<list>
#include<string>
#include "components.hpp"

using namespace std;

Components::Components(const std::string& name, int pr):
nameComp(name),
price()
{}

Components::~Components() {}

//ITEM 10: return reference from copy assignment operator
Components& Components::operator=(const Components& copy1) { //copy assignment operator implementation
    nameComp = copy1.nameComp;
    price = copy1.price;
    return *this; //to support chaining assignment
}

Components::Components(const Components& copy2) { //copy constructor implementation
    nameComp = copy2.nameComp;
    price = copy2.price;
}

string Components::getName() {
        return nameComp;
    }
 

