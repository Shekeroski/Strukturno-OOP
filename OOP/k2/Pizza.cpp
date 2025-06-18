#include <cstring>
#include <iostream>
using namespace std;

class Pizza {
protected:
  char ime[20];
  char sostojki[100];
  double cena;
  public:
  Pizza() {}
  Pizza(const char* ime, const char* sostojki,double cena) {
    strcpy(this->ime, ime);
    strcpy(this->sostojki, sostojki);
    this->cena = cena;
  }
  virtual double price()const =0;
  virtual void print(ostream &os)const=0;
  bool operator<(const Pizza& pizza) {
    return this->price()<pizza.price();
  }
};
enum Size {
  mala,golema,familijarna
};
class FlatPizza : public Pizza {
private:
  Size size;
  public:
  FlatPizza():Pizza() {
    size = mala;
  }
  FlatPizza(const char* ime, const char* sostojki,double cena,Size size=mala):
  Pizza(ime,sostojki,cena) {
    this->size = size;
  }
  double price()const override{
    double s=this->cena;
    if(size==mala) {
      s+=s*0.1;
    }else if(size==golema) {
      s+=s*0.2;
    }else if(size==familijarna) {
      s+=s*0.3;
    }
    return s;
  }
  void print(ostream &os)const override {
    os<<ime<<": "<<sostojki<<", ";
    if(size==mala) {
      os<<"small ";
    }
    else if(size==golema) {
      os<<"golema ";
    }else if(size==familijarna) {
      os<<"family ";
    }
      os<<"- "<<price()<<endl;
  }
};
class FoldedPizza : public Pizza {
private:
  bool daliBelo;
public:
  FoldedPizza():Pizza() {
    daliBelo = true;
  }
  FoldedPizza(const char* ime, const char* sostojki,double cena,bool daliBelo=true):
  Pizza(ime,sostojki,cena) {
    this->daliBelo =daliBelo;
  }
  void setWhiteFlour(bool daliBelo) {
    this->daliBelo = daliBelo;
  }
  double price() const override{
    double s=this->cena;
    if(daliBelo) {
      s+=s*0.1;
      return s;
    }else {
      s+=s*0.3;
      return s;
    }
  }
  void print(ostream &os)const override {
    os<<ime<<": "<<sostojki<<", ";
    if(daliBelo) {
      os<<"wf ";
    }else {
      os<<"nwf ";
    }
    os<<"- "<<price()<<endl;
  }
};
ostream& operator<<(ostream& os, const Pizza& p) {
  p.print(os);
  return os;
}
void expensivePizza(Pizza** p,int n) {
  int indexmax=0;
  double najpoce=p[0]->price();
  for(int i=1;i<n;i++) {
    if(p[i]->price()>najpoce) {
      najpoce=p[i]->price();
      indexmax=i;
    }
  }
  cout<<*p[indexmax];
}
int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;

  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;

    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;

    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;

    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;

    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } else if (test_case == 6) {
	// Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);

        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setWhiteFlour(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}
