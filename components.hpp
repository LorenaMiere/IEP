#include<iostream>
#include<list>
#include<string>

using namespace std;

class Components {
    std::string nameComp;
    int price;
public:
    Components(const std::string& name, int pr);
    string getName();
    ~Components();
    Components& operator=(const Components& copy1); //copy assignment operator
    Components (const Components& copy2); //copy constructor
};

Components& comp(const std::string& name, int pr) {
     static Components cmp(name,pr);
     return cmp;
 }

