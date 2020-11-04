#include<iostream>
#include<string>
#include<list>

#include"components.cpp"

using namespace std;

class Uncopyable {
protected: // allow construction
Uncopyable() {} // and destruction of
~Uncopyable() {} // derived objects...
private:
Uncopyable(const Uncopyable&); // ...but prevent copying
Uncopyable& operator=(const Uncopyable&);
};

class Car: private Uncopyable{
    std::string registrationNumber;
    std::string colour;
    std::list<Components> components;
    const int yearOfFabrication;
    int speed;
    //Car& operator=(const Car& copy3); //copy assignment operator - declarations only
    //Car (const Car& copy4); //copy constructor - declarations only
public:
    Car(const std::string& regNr, const std::string& clr, const std::list<Components>& comp, int y);
    string getRegistrationNumber();
    int getYearOfFabrication();
    int getCarAge(int year);
};
