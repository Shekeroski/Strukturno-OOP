#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Room {
protected:
    int brojnasoba;
    int cena;
public:
    Room(int brojnasoba=0, int cena=0) {
        this->brojnasoba = brojnasoba;
        this->cena = cena;
    }
    Room(const Room& room) {
        this->brojnasoba = room.brojnasoba;
        this->cena = room.cena;
    }
    Room& operator=(const Room& room) {
        if(this != &room) {
            this->brojnasoba = room.brojnasoba;
            this->cena = room.cena;
        }
        return *this;
    }
    virtual int getPrice() {
        return cena;
    }
    virtual void print() {
        cout<<brojnasoba<<"-"<<cena<<" euros"<<endl;
    }
};
class StandardRoom: public Room {
private:
    bool hasBalcony;
    public:
    StandardRoom(bool hasBalcony=false):Room() {
        this->hasBalcony = hasBalcony;
    }
    StandardRoom(int brojnasoba,int cena,bool hasBalcony):Room(brojnasoba,cena) {
        this->hasBalcony = hasBalcony;
    }
    StandardRoom& operator=(const StandardRoom& room) {
        if(this != &room) {
            Room::operator=(room);
            this->brojnasoba = room.brojnasoba;
        }
    }
    int getPrice() {
        if(hasBalcony) {
            return cena-(cena*0.05);
        }else {
            return cena;
        }
    }
    void print() override{
        cout<<brojnasoba<<"-"<<getPrice()<<" euros ";
        if(hasBalcony) {
            cout<<"has a Balcony"<<endl;
        }else {
            cout<<"without balcony"<<endl;
        }
    }
};
class LuxuryRoom: public Room {
private:
    bool hasJacuzzi;
public:
    LuxuryRoom(bool hasJacuzzi=false):Room() {}
    LuxuryRoom(int brojnasoba,int cena,bool hasJacuzzi):Room(brojnasoba,cena) {
        this->hasJacuzzi = hasJacuzzi;
    }
    LuxuryRoom& operator=(const LuxuryRoom& room) {
        if(this != &room) {
            Room::operator=(room);
            this->hasJacuzzi = room.hasJacuzzi;
        }
    }
    int getPrice() {
        if(hasJacuzzi) {
            return cena+(cena*0.2);
        }else {
            return cena;
        }
    }
    void print() override{
        cout<<brojnasoba<<"-"<<getPrice()<<" euros ";
        if(hasJacuzzi) {
            cout<<"has a Jacuzzi"<<endl;
        }else {
            cout<<"without Jacuzzi"<<endl;
        }
    }
};
int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        // Test Room class
        int number, price;
        cin >> number >> price;
        Room r1(number, price);
        Room r2 = r1;  // Copy constructor
        Room r3;
        r3 = r1;       // Assignment operator

        r1.print();
        r2.print();
        r3.print();
    }
    else if (testCase == 2) {
        // Test StandardRoom
        int number, price;
        bool hasBalcony;
        cin >> number >> price >> hasBalcony;

        StandardRoom sr(number, price, hasBalcony);
        sr.print();
    }
    else if (testCase == 3) {
        // Test LuxuryRoom
        int number, price;
        bool hasJacuzzi;
        cin >> number >> price >> hasJacuzzi;

        LuxuryRoom lr(number, price, hasJacuzzi);
        lr.print();
    }
    else if (testCase == 4) {
        // Polymorphism test
        int n;
        cin >> n;
        Room* rooms[100];

        for (int i = 0; i < n; ++i) {
            string type;
            cin >> type;

            int number, price;
            cin >> number >> price;

            if (type == "Standard") {
                bool hasBalcony;
                cin >> hasBalcony;
                rooms[i] = new StandardRoom(number, price, hasBalcony);
            } else if (type == "Luxury") {
                bool hasJacuzzi;
                cin >> hasJacuzzi;
                rooms[i] = new LuxuryRoom(number, price, hasJacuzzi);
            } else {
                rooms[i] = new Room(number, price);
            }
        }

        for (int i = 0; i < n; ++i) {
            rooms[i]->print();
        }

        for (int i = 0; i < n; ++i) {
            delete rooms[i];
        }
    }

    return 0;
}