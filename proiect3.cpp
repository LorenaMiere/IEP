#include <iostream>
#include <memory>
using namespace std;

class Car{ 
   private:
    string registrationNumber;
    int yearOfFabrication;
        
    public:
        // Copy constructor
        Car(const Car &ca){
            cout << "Car copy constructor\n";
           registrationNumber=ca.registrationNumber;
           yearOfFabrication=ca.yearOfFabrication;
        };

        // Copy assignment operator
        Car& operator=(const Car &ca){
            cout << "Car copy assignment operator\n";
            registrationNumber= ca.registrationNumber;
            yearOfFabrication = ca.yearOfFabrication;
            return *this;
        }; 
        // Default constructor 
        Car() : registrationNumber("TM-12-AAA"), yearOfFabrication(2010){}; 
        Car(string &x, int &y) : registrationNumber(x), yearOfFabrication(y){}; // Constructor with values
         
      void accelereaza()
	{
		cout << registrationNumber << " accelereaza" << "\n";
	}
	
	void franeaza()
	{
		cout << registrationNumber << " franeaza" << "\n";
	}

        string getRegistrationNumber(){
            return registrationNumber;
        }

        int getYearOfFabrication(){
            return yearOfFabrication;
        }
};


Car* createCar(string &x, int &y){
    return new Car(x, y);
}

static void deleteCar(Car *ca){  
    ca->~Car();
    cout<<"The car "<<ca->getRegistrationNumber()<<" has been deleted\n";
}

int main(){
    string x;
    int y;
    cout<<"Enter registration number: ";
    cin>>x;
    cout<<"Enter year of fabrication: ";
    cin>>y;
    shared_ptr<Car> r1(createCar(x,y),deleteCar);
    shared_ptr<Car> r2;
    auto_ptr<Car> r3(createCar(x,y));
    auto_ptr<Car> r4;
    r2=r1; // both shared_ptr pointers point to the same object
    r4=r3; // only r4 points to the object
    
    // Class methods for both shared_ptr pointers
    r1->accelereaza();
    r2->accelereaza();
    r1->franeaza();
    r2->franeaza();

    cout<<endl;
    // Class methods for auto_ptr
    r4->accelereaza();
    r4->franeaza();
   
    return 0;
}
