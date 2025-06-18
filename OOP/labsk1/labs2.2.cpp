#include<iostream>
using namespace std;
#include<cstring>

class Date {
    private:
    int year;
    int month;
    int day;
public:
    Date(){}
    Date(int _year, int _month, int _day) {
        year = _year;
        month = _month;
        day = _day;
    }
    int getYear() {
        return year;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    void print() {
        cout<<year<<"."<<month<<"."<<day<<endl;
    }
};
class Person {
    private:
    char name[10];
    char surname[10];
public:
    Person(char *_name,char *_surname) {
        strcpy(name,_name);
        strcpy(surname,_surname);
    }
    char *getName() {
        return name;
    }
    char *getSurname() {
        return surname;
    }
    void print() {
        cout<<name<<" "<<surname<<endl;
    }
};
class Car {
    private:
    Person p;
    Date d;
    float cena;
public:
    Car(){}
    Car(Person _p,Date _d,float _cena) {
        p=_p;
        d=_d;
        cena=_cena;
    }
    void print() {
        p.print();
        d.print();
        cout<<"cena: "<<cena<<endl;
    }
    float getCena() {
        return cena;
    }
};
void cheaperThan(Car *cars,int numberofcars,float price) {
    for(int i=0;i<numberofcars;i++) {
        if(cars[i].getCena()<price) {
            cars[i].print();
        }
    }
}

int main()
{
    char name[20];
    char lastName[20];
    int year;
    int month;
    int day;
    float price;

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(year, month, day);

        cin >> price;
        Car car(lik, date, price);

        car.print();
    }
    else if (testCase == 2)
    {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(Date(year, month, day));

        cin >> price;
        Car car(lik, date, price);
        car.print();
    }
    else
    {
        int numCars;
        cin >> numCars;

        Car cars[10];
        for (int i = 0; i < numCars; i++)
        {
            cin >> name;
            cin >> lastName;
            Person lik(name, lastName);

            cin >> year;
            cin >> month;
            cin >> day;
            Date date(year, month, day);

            cin >> price;
            cars[i] = Car(lik, date, price);
        }
        float priceLimit;
        cin >> priceLimit;
        cheaperThan(cars, numCars, priceLimit);
    }


    return 0;
}