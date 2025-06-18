#include<iostream>
#include<cstring>
using namespace std;
int MAX=20;
class UserExistsException {
public:
  UserExistsException() {}
  void mssg() {
    cout<<"The user already exists in the list!"<<endl;
  }
};
enum typeC {
  STANDARDNI,LOJALNI,VIP
};
class Customer {
private:
  char ime[20];
  char elektronskaAdresa[50];
  typeC t;
  int popust;
  int dopolnitelenPopust;
  int brKupeniProizvodi;
public:
  Customer(){}
  Customer( char *ime,char*elektronskaAdresa,typeC t,int brKupeniProizvodi) {
    strcpy(this->ime,ime);
    strcpy(this->elektronskaAdresa,elektronskaAdresa);
    this->t=t;
    this->brKupeniProizvodi=brKupeniProizvodi;
  }
  int getBrKupeniProizvodi() {
    return brKupeniProizvodi;
  }
  char *getElektronskaAdresa() {
    return elektronskaAdresa;
  }
  void setDiscount1(int popust) {
    this->popust=popust;
  }
  typeC getType() {
    return t;
  }
  typeC setType(typeC t) {
    return this->t=t;
  }
  char *getIme() {
    return ime;
  }
  int getPopust(){
    if(t==STANDARDNI) {
      popust=0;
    }else if(t==LOJALNI) {
      popust=10;
    }else {
      popust=30;
    }
  return popust;
  }
  friend ostream& operator<<(ostream& os, Customer& c);
};
  ostream& operator<<(ostream& os,Customer& c) {
  os<<c.getIme()<<endl;
  os<<c.getElektronskaAdresa()<<endl;
  os<<c.getBrKupeniProizvodi()<<endl;
  if(c.getType()==STANDARDNI) {
    os<<"standard "<<c.getPopust();
  }else if(c.getType()==LOJALNI) {
    os<<"loyal "<<c.getPopust();
  }else if(c.getType()==VIP) {
    os<<"vip "<<c.getPopust();
  }
  return os;
}
class FINKI_bookstore{
private:
  Customer *customers;
  int brCustomers;
  public:
  FINKI_bookstore() {
    customers=nullptr;
    brCustomers=0;
  }
  FINKI_bookstore(Customer *customers,int brCustomers) {
    this->brCustomers=brCustomers;
    this->customers=new Customer[brCustomers];
    for(int i=0;i<brCustomers;i++) {
      this->customers[i]=customers[i];
    }
  }
  FINKI_bookstore(const FINKI_bookstore &b) {
    this->brCustomers=b.brCustomers;
    this->customers=new Customer[brCustomers];
    for(int i=0;i<brCustomers;i++) {
      this->customers[i]=b.customers[i];
    }
  }
  FINKI_bookstore &operator=(const FINKI_bookstore &b) {
    if(this!=&b) {
      this->brCustomers=b.brCustomers;
      delete []this->customers;
      this->customers=new Customer[brCustomers];
      for(int i=0;i<brCustomers;i++) {
        this->customers[i]=b.customers[i];
      }
    }
    return *this;
  }
  ~FINKI_bookstore() {
    delete [] customers;
  }
  FINKI_bookstore& operator+=( Customer &b) {
for(int i=0;i<brCustomers;i++) {
  if(strcmp(customers[i].getElektronskaAdresa(),b.getElektronskaAdresa())==0) {
    throw UserExistsException();
  }
}
    Customer *temp=new Customer[brCustomers+1];
    for(int i=0;i<brCustomers;i++) {
      temp[i]=customers[i];
    }
    temp[brCustomers]=b;
    delete [] customers;
    customers=temp;
    brCustomers++;
    return *this;
  }
  void update() {
    for(int i=0;i<brCustomers;i++) {
      if(customers[i].getType()==STANDARDNI && customers[i].getBrKupeniProizvodi()>5) {
        customers[i].setType(LOJALNI);
      }else if(customers[i].getType()==LOJALNI && customers[i].getBrKupeniProizvodi()>10) {
        customers[i].setType(VIP);
      }
    }
  }
  friend ostream& operator<<(ostream& os, const FINKI_bookstore& b) {
    for(int i=0;i<b.brCustomers;i++) {
      os<<b.customers[i]<<endl;
    }
    return os;
  }
  void setCustomers(Customer *customers,int brCustomers) {
    this->brCustomers=brCustomers;
    this->customers=new Customer[brCustomers];
    for(int i=0;i<brCustomers;i++) {
      this->customers[i]=customers[i];
    }
  }
};
int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;

    cout << fc;
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    try {
      fc+=c;
    }catch (UserExistsException &e) {
      e.mssg();
    }
    cout << fc;
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;

}
