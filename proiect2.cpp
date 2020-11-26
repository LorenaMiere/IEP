#include<iostream>

using namespace std;

class Components{
    private:
    string name;

    public:
    Components(string nm): name(nm){};
    string getNameOfComp(){
        return this->name;
    }
};

class Car{
    private:
    string registrationNumber;
    int yearOfFabrication;
    Components *components;

    public:

    Car() : registrationNumber("TM-09-AND"),yearOfFabrication(2010),components(new Components("roata")){};

    Car(string regNr,int year,Components *c):
    registrationNumber(regNr),
    yearOfFabrication(year),
    components(c)
    {};

    Car (const Car& ca):
    registrationNumber(ca.registrationNumber),
    yearOfFabrication(ca.yearOfFabrication),
    components(ca.components)
    {};

    Car& operator=(const Car& ca){
        this->registrationNumber=ca.registrationNumber;
        this->yearOfFabrication=ca.yearOfFabrication;

        Components *orig=components;
        this->components=new Components(*ca.components);
        delete orig;
        return *this;
    };

    void toString(){
        cout<<registrationNumber<<" "<<yearOfFabrication<<" "<<components->getNameOfComp();
    }

};

class Tesla : public Car{
    private:
        string color;
    public:
        Tesla(string regNr, int year, Components *c, string col):
            Car(regNr, year, c),
            color(col)
        {};
        Tesla(const Tesla& ca):
            Car(ca),
            color(ca.color)
        {};
        Tesla& operator=(const Tesla& ca){
            Car::operator=(ca);
            color=ca.color;

            return *this;
        }
        void toString(){
            Car::toString();
            cout<<" "<<color;
        }
};

int main(){
    Components *c1= new Components("usa");
    Components *c2= new Components("portbagaj");

    Car car1("TM-12-ABC",2011,c1);
    Car car2("TM-11-BDC",2012,c2);

    Tesla t1("TM-45-OPO",2015,c1,"rosu");

    cout<<"Car 1:";
    car1.toString();

    cout<<endl<<"Car 2:";
    car2.toString();

    Car c3(car2);
    cout<<endl<<"Car 3 copy constructor:";
    c3.toString();

    Car c4("TM-30-KLO",2019,c2);
    (car2=c4)=car1;

      cout<<endl<<"Car 1 assignment operator: ";
    car1.toString();

  cout<<endl<<"Car 2 assignment operator: ";
    car2.toString();

      cout<<endl<<"Car 4 assignment operator: ";
    c4.toString();



    cout<<endl<<"Tesla";
    t1.toString();

    Tesla t3(t1);
    cout<<endl<<"Tesla 3 copy constructor:";
    t3.toString();

    return 0;
}