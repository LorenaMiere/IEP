#include<iostream>
#include<list>
#include<string>
#include<ctime>
#include "car.hpp"

using namespace std;

Car::Car(const std::string& regNr, const std::string& clr, const std::list<Components>& comp, const int y):
registrationNumber(regNr),
colour(clr),
components(comp),
yearOfFabrication(y),
speed(0)
{}

string Car::getRegistrationNumber() {
    return registrationNumber;
}

int Car::getYearOfFabrication() {
    return yearOfFabrication;
}

int Car::getCarAge(int year) {
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    return (timePtr->tm_year + 1900) - year;
}