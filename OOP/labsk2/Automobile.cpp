#include<iostream>
#include<cstring>
using namespace std;
class Automobile {
  char *marka;
  int *reg;
  int maks_brzina;
public:
  Automobile() {
    marka = NULL;
    reg = NULL;
    maks_brzina = 0;
  }
  Automobile(char *marka,int *reg, int maks_brzina) {
    this->marka = new char[strlen(marka)+1];
    strcpy(this->marka,marka);
    this->maks_brzina = maks_brzina;
    this->reg = new int[5];
    for(int i=0;i<5;i++) {
      this->reg[i] = reg[i];
    }
  }
  ~Automobile() {
    delete [] this->marka;
    delete [] this->reg;
  }
  Automobile &operator=(const Automobile &a) {
    if(this != &a) {
      delete [] this->marka;
      delete [] this->reg;
      this->marka = new char[strlen(a.marka)+1];
      strcpy(this->marka,a.marka);
      this->maks_brzina = a.maks_brzina;
      this->reg = new int[5];
      for(int i=0;i<5;i++){
        this->reg[i] = a.reg[i];
      }
    }
    return *this;
  }
  bool operator==(const Automobile &a) {
    if(this->reg != a.reg) {
      return true;
    }else {
      return false;
    }
  }
  friend ostream& operator<<(ostream &COUT, const Automobile &a) {
    COUT << a.marka;
    COUT << a.maks_brzina;
    return COUT;
  }
};
class RentACar {
  char name[10];
  Automobile *automobiles;
  int br;
public:
  RentACar() {
    automobiles = NULL;
    br = 0;
  }
  RentACar(char *name,Automobile *automobiles,int br) {
    this->br=br;
    strcpy(this->name,name);
    automobiles = new Automobile[br];
    for(int i=0;i<br;i++) {
      this->automobiles[i] = automobiles[i];
    }
  }
  RentACar &operator=(const RentACar &a) {
    if(this != &a) {
      delete [] automobiles;
      automobiles = new Automobile[a.br];
      for(int i=0;i<a.br;i++) {
        automobiles[i] = a.automobiles[i];
      }
    }
    return *this;
  }
  RentACar(const RentACar &a) {
    this->br = a.br;
    strcpy(this->name,a.name);
    automobiles = new Automobile[a.br];
    for(int i=0;i<a.br;i++) {
      automobiles[i] = a.automobiles[i];
    }
  }
  ~RentACar() {
    delete [] automobiles;
  }
  RentACar &operator+=(const Automobile &a) {
    automobiles[br] = a;
    br++;
  }

};