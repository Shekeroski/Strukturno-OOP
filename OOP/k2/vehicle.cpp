#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class InvalidPlateNumberException : public exception {
private:
    string plateNumber;
public:
    InvalidPlateNumberException(string plateNumber) {
        this->plateNumber = plateNumber;
    }
    void mssg() {
        cout <<"ne validen broj na tablica :"<< plateNumber << endl;
    }
};
class Vehicle {
protected:
    string brand;
    string model;
    string plateNumber;
    float consumptionPer100km;
public:
    virtual float calculateRange()=0;
    virtual void print()=0;
    Vehicle(string brand="",string model="",string plateNumber="SU444AB",float consumptionPer100km=0) {
        this->brand = brand;
        this->model = model;
        this->plateNumber = plateNumber;
        this->consumptionPer100km = consumptionPer100km;
         if(plateNumber.length()!=7 || plateNumber.find(' ')!=string::npos) {
             throw InvalidPlateNumberException (plateNumber);
         }
    }
};
class Car : public Vehicle {
private:
    int passengers;
public:
    Car(string brand="",string model="",string plateNumber="SU444AB",float consumptionPer100km=0,int passengers=0):Vehicle(brand,model,plateNumber,consumptionPer100km) {
        this->passengers = passengers;
    }
    float calculateRange() override {
        if(passengers<=2) {
            consumptionPer100km*=0.1;
        }
        return 50.0f*100/consumptionPer100km;
    }
    void print() override {
        cout << "Car: " << brand << " " << model << ", Plate: " << plateNumber
             << ", Passengers: " << passengers
             << ", Range: " << calculateRange() << " km" << endl;
    }
};
class Truck : public Vehicle {
private:
    int loadCapacity;
public:
    Truck(string brand="",string model="",string plateNumber="SU444AB",float consumptionPer100km=0,int loadCapacity=0):Vehicle(brand,model,plateNumber,consumptionPer100km) {
        this->loadCapacity = loadCapacity;;
    }
    float calculateRange() override {
        int s=loadCapacity/1000;
        int total=s+consumptionPer100km;
        return 50.0f*100/total;
    }
    void print() override {
        cout << "Truck: " << brand << " " << model << ", Plate: " << plateNumber
             << ", Load: " << loadCapacity << "kg"
             << ", Range: " << calculateRange() << " km" << endl;
    }
};
void printVehicleTypes(Vehicle **vehicles, int n) {
    int cars=0;
    int trucks=0;
    for(int i=0;i<n;i++) {
        if(dynamic_cast<Car *>(vehicles[i])){
            cars++;
        }
        else if(dynamic_cast<Truck *>(vehicles[i])) {
            trucks++;
        }
    }
    cout<<"cars percentage is: "<<cars*100.0/n<<endl;
    cout<<"trucks percentage is: "<<trucks*100.0/n<<endl;
}
int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        Vehicle *v1 = new Car("Toyota", "Yaris", "SK1234A", 6.0, 4);
        Vehicle *v2 = new Car("Mazda", "3", "VE4567B", 5.5, 2);
        v1->print();
        v2->print();
    }
    else if (testCase == 2) {
        Vehicle *v1 = new Truck("Mercedes", "Actros", "BT9012C", 15.0, 5000);
        Vehicle *v2 = new Truck("Volvo", "FH16", "TE3456D", 14.5, 7000);
        v1->print();
        v2->print();
    }
    else if (testCase == 3) {
        try {
            Vehicle *v = new Car("BMW", "X5", "BAD123", 7.5, 3); // should throw
            v->print();
        }catch(InvalidPlateNumberException &e) {
            e.mssg();
        }
    }
    else if (testCase == 4) {
        int n;
        cin >> n;
        Vehicle **vehicles = new Vehicle*[n];
        for (int i = 0; i < n; i++) {
            int type;
            string brand, model, plate;
            float cons;
            cin >> type >> brand >> model >> plate >> cons;
            if (type == 1) {
                int pass;
                cin >> pass;
                try {
                    vehicles[i] = new Car(brand, model, plate, cons, pass);
                }catch(InvalidPlateNumberException &e) {
                    e.mssg();
                }
            } else {
                int load;
                cin >> load;
                try {
                    vehicles[i] = new Truck(brand, model, plate, cons, load);
                }catch(InvalidPlateNumberException &e) {
                    e.mssg();
                }
            }
        }
        for (int i = 0; i < n; i++) {
            vehicles[i]->print();
        }
        printVehicleTypes(vehicles, n);
        for (int i = 0; i < n; i++) delete vehicles[i];
        delete[] vehicles;
    }

    return 0;
}