#include<iostream>
#include<cstring>
using namespace std;

class StockRecord {
    private:
    char id[12];
    char name[50];
    double price;
    double momentalprice;
    int brnaakciikupeni;
    public:
    StockRecord() {}
    StockRecord(char * _id, char * _name, double _price,int _brnakupeniakcii) {
        price = _price;
        brnaakciikupeni = _brnakupeniakcii;
        strcpy(id,_id);
        strcpy(name,_name);
    }
    void setNewPrice(double c) {
        momentalprice = c;
    }
    double value() const{
        int s=0;
        s+=brnaakciikupeni*momentalprice;
        return s;
    }
    double profit() const{
        int s=0;
        s+=brnaakciikupeni*(momentalprice-price);
        return s;
    }
    friend ostream &operator<<(ostream &out,const StockRecord &sr) {
        out << sr.name<<" "<<sr.brnaakciikupeni<<" "<<sr.price<<" "<<sr.momentalprice<<" "<<sr.profit()<<endl;
    }
    ~StockRecord() {};
};
class Client {
    private:
    char name[20];
    int id;
    StockRecord *companies;
    int brnaobjektivoniza;
public:
    Client() {}
    Client(char * _name, int _id, StockRecord *_companies) {
        id = _id;
        companies = _companies;
        strcpy(name,_name);
    }
    ~Client() {}
    double totalValue() const{
        int s=0;
        for(int i=0;i<brnaobjektivoniza;i++) {
            s+=companies[i].value();
        }
        return s;
    }
    Client & operator+=(const StockRecord &sr) {
        StockRecord *temp=new StockRecord[brnaobjektivoniza+1];
        for(int i=0;i<brnaobjektivoniza;i++) {
            temp[i]=companies[i];
        }
        temp[brnaobjektivoniza]=sr;
        companies=temp;
        brnaobjektivoniza++;
        return *this;
    }
    friend ostream &operator<<(ostream &out,const Client &c) {
        out<<c.id<<" "<<c.totalValue()<<endl;
        for(int i=0;i<c.brnaobjektivoniza;i++) {
             out<<c.companies[i];
        }
        return out;
    }
};
int main(){

    int test;
    cin >> test;

    if(test == 1){
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if(flag){
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}