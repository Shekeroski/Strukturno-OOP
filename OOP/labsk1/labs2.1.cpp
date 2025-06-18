#include<iostream>
using namespace std;

class Flight {
    private:
    char name[10];
    char mestosletuvanje[10];
    char mestonazaminuvanje[10];
    int cena;
public:
    Flight(){};
    Flight(char *_name,char *_mestonasletuvanje,char *_mestonazaminuvanje,int _cena) {
        strcpy(name,_name);
        strcpy(mestosletuvanje,_mestonasletuvanje);
        strcpy(mestonazaminuvanje,_mestonazaminuvanje);
        cena=_cena;
    }
    Flight(const Flight &flight) {
        strcpy(name,flight.name);
        strcpy(mestosletuvanje,flight.mestosletuvanje);
        strcpy(mestonazaminuvanje,flight.mestonazaminuvanje);
        cena=flight.cena;
    }
    char * getName() {
        return name;
    }
    char * getMestosletuvanje() {
        return mestosletuvanje;
    }
    char * getMestonazaminuvanje() {
        return mestonazaminuvanje;
    }
    int getCena() {
        return cena;
    }
    void show() {
        cout<<"Flight: "<<name<<" | From: "<<mestosletuvanje
        <<"| To: "<<mestonazaminuvanje<<" | Cena: "<<cena<<endl;;
    }
    void read() {
        cin>>name;
        cin>>mestosletuvanje;
        cin>>mestonazaminuvanje;
        cin>>cena;
    }
};
class Airport {
    private:
    char name[10];
    int brletovi;
    Flight *flights;
public:
    Airport(char *_name,int _brletovi,Flight *_flights) {
        strcpy(name,_name);
        brletovi=_brletovi;
        flights=_flights;
    };
    Flight cheapestFlight() const {
        Flight temp=flights[0];
        for(int i=0;i<brletovi;i++) {
            if(flights[i].getCena()<temp.getCena()) {
                temp=flights[i];
            }
        }
        return temp;
    }
    void showflights()const {
        cout<<"Flight: "<<name;
        for(int i=0;i<brletovi;i++) {
            flights[i].show();
        }
    }
    void readflights() {
        cin>>name;
        cin>>brletovi;
    }
};

int main() {

    return 0;
}