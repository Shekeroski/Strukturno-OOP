#include <iostream>
#include <cstring>

using namespace std;

class Museum {
protected:
    string name;
    string city;
    double cena;
    int casNedelno;
public:
    virtual void printDetail()=0;
    virtual double calculateTicketCost()=0;
    Museum(string name="", string city="",double cena=0, int casNedelno=0) {
        this->name=name;
        this->city=city;
        this->cena=cena;
        this->casNedelno=casNedelno;
    }
    int getCasNedelno() {
        return casNedelno;
    }
};
class ScientificMuseum : public Museum {
private:
    bool interaktivniPostavki;
    int brPrezentacii;
    public:
    ScientificMuseum(string name="", string city="",double cena=0, int casNedelno=0,bool interaktivniPostavki=false,int brPrezentacii=0):Museum(name,city,cena,casNedelno) {
        this->brPrezentacii = brPrezentacii;
        this->interaktivniPostavki = interaktivniPostavki;
    }
    double calculateTicketCost() override {
        double c=cena;
        if(interaktivniPostavki) {

            c= c + (c*0.12);
        }
        c = c + (brPrezentacii*6);
        return c;
    }
    void printDetail() override {
        cout<<name<<" - "<<"(Scientific) "<<city<<" "<<brPrezentacii<<" "<<calculateTicketCost()<<endl;
    }
    int getCasNedelno() {
        return casNedelno;
    }
};
class ArtMuseum : public Museum {
private:
    bool amaterskiIzlozbi;
    int originalniDela;
public:
    ArtMuseum(string name="", string city="",double cena=0, int casNedelno=0,bool amaterskiIzlozbi=false,int originalniDela=0):Museum(name,city,cena,casNedelno) {
        this->amaterskiIzlozbi = amaterskiIzlozbi;
        this->originalniDela = originalniDela;
    }
    double calculateTicketCost() override {
        if(amaterskiIzlozbi) {
            cena=cena-cena*0.18;
        }
        cena+=originalniDela*3;
        return cena;
    }
    void printDetail() override {
        cout<<name<<" - "<<"(Art) "<<city<<" "<<amaterskiIzlozbi<<" "<<calculateTicketCost()<<endl;
    }
};
int findCheapestScientificMuseum(Museum **m, int n) {
    int temp=-1;
    float najeftin=999999;
    for(int i=0;i<n;i++) {
        if(dynamic_cast<ScientificMuseum*>(m[i])){
            float segasen=m[i]->calculateTicketCost();
            if(segasen<najeftin) {
                najeftin=segasen;
                temp=i;
            }else if(segasen==najeftin) {
                if(m[i]->getCasNedelno() > m[temp]->getCasNedelno()) {
                    temp=i;
                }
            }
        }
    }
    return temp;
}
int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Museum** m = new Museum*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        int working_hours;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> working_hours;
        cin.ignore();

        if (type == 1) {
            bool interactive_shows;
            int multimedia_pres;

            cin >> interactive_shows >> multimedia_pres;
            cin.ignore();

            m[i] = new ScientificMuseum(name, city, base_price, working_hours, interactive_shows, multimedia_pres);
        } else {
            bool amateur_shows;
            int original_artwork;

            cin >> amateur_shows >> original_artwork;
            cin.ignore();

            m[i] = new ArtMuseum(name, city, base_price, working_hours, amateur_shows, original_artwork);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateTicketCost() << endl;
        }
        cout << "calculateTicketCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int cheapest_sci_museum_index = findCheapestScientificMuseum(m, n);
        if(cheapest_sci_museum_index>=0){
            m[cheapest_sci_museum_index]->printDetail();
        }else{
            cout << "Scientific Museum not found in the array!"<<endl;
        }
        cout << "findCheapestOnlineOrder method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}