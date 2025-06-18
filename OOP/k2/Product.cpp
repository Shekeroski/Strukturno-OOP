#include <iostream>
#include<fstream>
#include <cstring>
using namespace std;
class NoProductFoundException : public exception {
private:
    string category;
public:
    NoProductFoundException(string category) {
        this->category = category;
    }
    void mssg() {
        cout<<"No products from category "<<category<<" were found in the store"<<endl;
    }
};
class Product {
private:
    string name;
    string category;
    int price;
    int quantity;
public:
    Product(string name="", string category="", int price=0, int quantity=0) {
        this->name = name;
        this->category = category;
        this->price = price;
        this->quantity = quantity;
    }
    int totalPrice() {
        return price*quantity;
    }
    friend ostream&operator<<(ostream &out,Product &p) {
        out<<p.name<<" ("<<p.category<<")"<<" "<<p.quantity<<" x "<<p.price<<" = "<<p.totalPrice()<<endl;
       return out;
    }
    string getCategory() {
        return category;
    }
};
class Store {
    Product *products;
    int n;
public:
    Store(Product *products=nullptr, int n=0) {
        this->n = n;
        this->products = nullptr;
        if(n>0 && products!=nullptr) {
            this->products = new Product[n];
            for (int i = 0; i < n; i++) {
                this->products[i] = products[i];
            }
        }
    }
    Store(const Store &p) {
        this->n = p.n;
        if(n>0 && p.products!=nullptr) {
            this->products = new Product[p.n];
            for (int i = 0; i < p.n; i++) {
                this->products[i] = p.products[i];
            }
        }
    }
    Store &operator=(const Store &p) {
        if(this!=&p) {
            this->n = p.n;
            if(n>0) {
                delete [] this->products;
                this->products = new Product[p.n];
                for (int i = 0; i < p.n; i++) {
                    this->products[i] = p.products[i];
                }
            }
        }
        return *this;
    }
    ~Store() {
        delete [] products;
        products = nullptr;
    }
    Store &operator+=(const Product &p) {
        Product *temp=new Product[n+1];
        for (int i = 0; i < n; i++) {
            temp[i] = products[i];
        }
        temp[n]=p;
        delete [] products;
        products = temp;
        n++;
        return *this;
    }
    friend ostream &operator<<(ostream &out,const Store &p) {
        for (int i = 0; i < p.n; i++) {
            out<<p.products[i];
        }
        return out;
    }
    Store fromCategory(string &category) {
        Store results;
        for (int i = 0; i < n; i++) {
            if(products[i].getCategory()==category) {
                results+=products[i];
            }
        }
        if(results.n==0) {
            throw NoProductFoundException(category);
        }
        return results;
    }
};
void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}


int main() {

    wtf();
    Store s;
    ifstream fin("input.txt");
    string name,category;
    int price,quantity;
    while(getline(fin,name)) {
        getline(fin,category);
        fin>>price>>quantity;
        fin.ignore();
            Product temp(name,category,price,quantity);
            s+=temp;

    }
    ofstream fout1("output1.txt");
    fout1 << s;
    cin >> category;
    ofstream fout2("output2.txt");
    try {
        Store filtered=s.fromCategory(category);
        fout2<<filtered;
    }catch(NoProductFoundException &e) {
        e.mssg();
    }

    cout << "All products:" << endl;
    rff("output1.txt");
    cout << "Products from category " << category << ": " << endl;
    rff("output2.txt");
    return 0;
}