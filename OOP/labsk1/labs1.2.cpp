#include<iostream>
#include<cstring>
using namespace std;

class Country {
private:
    char name[10];
    char capital[10];
    float area;
    double population;
public:
    Country() {

    }
    Country(char *n, char *c, float a,double p) {
        strcpy(name, n);
        strcpy(capital, c);
        area = a;
        population = p;
    }
    ~Country(){}
    void setName(char *n) {
        strcpy(name, n);
    }
    void setCapital(char *c) {
        strcpy(capital, c);
    }
    void setArea(float a) {
        area = a;
    }
    void setPopulation(double p) {
        population = p;
    }
    char *getName() {
        return name;
    }
    char *getCapital() {
        return capital;
    }
    float getArea() {
        return area;
    }
    double getPopulation() {
        return population;
    }
    void display() {
        cout<<"Country: "<<name<<endl;
        cout<<"Capital: "<<capital<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Population: "<<population<<endl;
    }
};
 void sort(Country *countries,int n) {
     Country temp;
     for(int i=0;i<n-1;i++) {
         for(int j=i;j<n;j++) {
             if(countries[i].getArea()<countries[j].getArea()) {
                 temp=countries[i];
                 countries[i]=countries[j];
                 countries[j]=temp;
             }
         }
     }
     for(int i=0;i<n;i++) {
        cout<< countries[i].getName()<<endl;
     }
 }

int main() {
    int n;
     cin>>n;
     Country countries[10];
     char name[10];
     char capital[10];
     float area;
     double population;
     for(int i=0;i<n;i++) {
         cin>>name>>capital>>area>>population;
         countries[i]=Country(name,capital,area,population);
     }
     cin>>name;
     cin>>capital;
     cin>>area;
     cin>>population;
     countries[n-1].setName(name);
     countries[n-1].setCapital(capital);
     countries[n-1].setArea(area);
     countries[n-1].setPopulation(population);
     cout<<"---> testing set methods and display()"<<endl;
     countries[n-1].display();
     cout<<endl;
     cout<<"---> testing sortCountries()"<<endl;
     sort(countries,n);
     return 0;
}