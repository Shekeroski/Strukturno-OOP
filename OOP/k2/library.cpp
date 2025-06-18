#include <iostream>
#include<cstring>
using namespace std;

class Library {
protected:
    string name;
    string city;
    float price;
    bool daliRaboti;
    public:
    Library(string name="", string city="", float price=0.0, bool daliRaboti=false) {
        this->name=name;
        this->city=city;
        this->price=price;
        this->daliRaboti=daliRaboti;
    }
    virtual void printDetail()=0;
    virtual double calculateMembershipCardCost()=0;
    bool get() {
        return daliRaboti;
    }
};
class AcademicLibrary:public Library {
private:
    bool moznosti;
    int kolelkciibr;
public:
    AcademicLibrary(string name="", string city="", float price=0.0, bool daliRaboti=false,bool moznosti=false,int kolekciibr=0):Library(name,city,price,daliRaboti) {
        this->moznosti=moznosti;
        this->kolelkciibr=kolekciibr;
    }
    double calculateMembershipCardCost() override{
        float s=price;
        if(moznosti) {
            s+=price*0.24;
        }
        s+=kolelkciibr*6;
        return s;
    }
    void printDetail() override{
        cout<<name<<" - "<<"(Academic) "<<city<<" "<<kolelkciibr<<" "<<calculateMembershipCardCost()<<endl;
    }
};
class NationalLibrary:public Library {
private:
    bool nudi;
    int rakopisibr;
public:
    NationalLibrary(string name="", string city="", float price=0.0, bool daliRaboti=false,bool nudi=false,int rakopisibr=0):Library(name,city,price,daliRaboti) {
        this->nudi=nudi;
        this->rakopisibr=rakopisibr;
    }
    double calculateMembershipCardCost() override{
        float s=price;
        if(nudi) {
            s-=price*0.07;
        }
        s+=rakopisibr*15;
        return s;
    }
    void printDetail() override{
        cout<<name<<" - "<<"(National) "<<city<<" "<<rakopisibr<<" "<<calculateMembershipCardCost()<<endl;
    }
};
int findMostExpensiveNationalLibrary(Library **I,int n) {
    int temp=-1;
    float maxcost=0;
    for(int i=0;i<n;i++) {
        if(dynamic_cast<NationalLibrary *>(I[i])) {
            double current=I[i]->calculateMembershipCardCost();
            if(current>maxcost) {
                temp=i;
                maxcost=current;
            }else if(current==maxcost) {
                if(I[i]->get() && !I[temp]->get()) {
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

    Library** m = new Library*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        bool weekend_working;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> weekend_working;
        cin.ignore();

        if (type == 1) {
            bool open_cooperation;
            int specialized_articles;

            cin >> open_cooperation >> specialized_articles;
            cin.ignore();

            m[i] = new AcademicLibrary(name, city, base_price, weekend_working, open_cooperation, specialized_articles);
        } else {
            bool cultural_program;
            int national_articles;

            cin >> cultural_program >> national_articles;
            cin.ignore();

            m[i] = new NationalLibrary(name, city, base_price, weekend_working, cultural_program, national_articles);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateMembershipCardCost() << endl;
        }
        cout << "calculateMembershipCardCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int most_expensive_nat_lib_index = findMostExpensiveNationalLibrary(m, n);
        if(most_expensive_nat_lib_index>=0){
            m[most_expensive_nat_lib_index]->printDetail();
        }else{
            cout << "National Library not found in the array!"<<endl;
        }
        cout << "findMostExpensiveNationalLibrary method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}
