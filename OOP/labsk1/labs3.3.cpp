#include<iostream>
#include<cstring>
using namespace std;

class Car {
    char model[10];
    char reg[10];
    bool dostapnost;
public:
    Car(){}
    Car(char *mmodel,char *reg,bool dostapnost) {
        strcpy(this->model,mmodel);
        strcpy(this->reg,reg);
        this->dostapnost = dostapnost;
    }
    Car(const Car &car) {
        strcpy(this->model,car.model);
        strcpy(this->reg,car.reg);
        this->dostapnost = car.dostapnost;
    }
    friend class RentalService;
  friend  void rentCar(RentalService &car,int id);
};
class RentalService {
  char name[10];
    Car *cars;
    int br;
public:
    RentalService() {
        br=0;
        strcpy(name,"Rent-a-Car");
    }
    RentalService(char *name,Car *cars,int br) {
        strcpy(this->name,name);
        this->br = br;
        this->cars = cars;
    }
    RentalService(const RentalService &car) {
        strcpy(this->name,car.name);
        this->br = car.br;
        this->cars = car.cars;
    }
    void addCar() {
        if(br<50) {
            cars[br++] = c;
        }
    }
  friend  void rentCar(RentalService &car,int id);
};
void rentCar(RentalService &car,int id) {
    if(id>0 && id<car.br) {
        if(car.cars[id].dostapnost) {
            car.cars[id].dostapnost = false;
        }
    }
}
int main() {

}