#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class Product {
private:
    char name[20];
    char category[20];
    int cena;
    int kolicina;
    public:
    Product(){}
    Product(char* name, char* category, int cena, int kolicina) {
        strcpy(this->name, name);
        strcpy(this->category, category);
        this->cena = cena;
        this->kolicina = kolicina;
    }
    char* getName() {
        return name;
    }
    char* getCategory() {
        return category;
    }
    int getCena() {
        return cena;
    }
    int getKolicina() {
        return kolicina;
    }
    friend istream& operator>>(istream& is, Product& order) {
        is.getline(order.name, 20);
        is.getline(order.category, 20);
        is>>order.cena;
        is>>order.kolicina;
        is.ignore();
        return is;
    }
};
class Order {
private:
    char sifra[20];
    char imePrez[30];
    Product *products;
    int n;
    public:
    Order() {
        products = nullptr;
        n = 0;
    }
    Order(char *sifra,char *imePrez,Product *products,int n) {
        strcpy(this->sifra,sifra);
        strcpy(this->imePrez,imePrez);
        this->n=n;
        this->products=new Product[n];
        for(int i=0;i<n;i++) {
            this->products[i]=products[i];
        }
    }
    Order(const Order& order) {
        strcpy(this->sifra,order.sifra);
        strcpy(this->imePrez,order.imePrez);
        this->n=order.n;
        this->products=new Product[n];
        for(int i=0;i<n;i++) {
            this->products[i]=order.products[i];
        }
    }
    Order& operator=(const Order& order) {
        if(this!=&order) {
            delete [] products;
            strcpy(this->sifra,order.sifra);
            strcpy(this->imePrez,order.imePrez);
            this->n=order.n;
            this->products=new Product[n];
            for(int i=0;i<n;i++) {
                this->products[i]=order.products[i];
            }
        }
        return *this;
    }
    ~Order() {
        delete [] products;
    }
    Order &operator+=(const Product& order) {
        Product* newProducts = new Product[n+1];
        for(int i=0;i<n;i++) {
            newProducts[i]=products[i];
        }
        delete [] products;
        newProducts[n]=order;
        products=newProducts;
        n++;
        return *this;
    }
    Order&operator-=( Product& order) {
        if(n==0) {
            cout<<"Products cannot be empty"<<endl;
        }
        int counter=0;
        for(int i=0;i<n;i++) {
            if(products[i].getName()!=order.getName() &&  products[i].getCategory()!=order.getCategory() && products[i].getCena()!=order.getCena() && products[i].getKolicina()!=order.getKolicina()) {
                counter++;
            }
        }
        int j=0;
        Product* newProducts = new Product[counter];
        for(int i=0;i<n;i++) {
            if(products[i].getName()!=order.getName() &&  products[i].getCategory()!=order.getCategory() && products[i].getCena()!=order.getCena() && products[i].getKolicina()!=order.getKolicina()) {
                newProducts[j++]=products[i];
            }
        }
        delete [] products;
        products=newProducts;
        n=counter;
        return *this;
    }
    void print(ofstream &os) {
        os<<"Order ID: "<<sifra<<endl;
        os<<"Customer: "<<imePrez<<endl;
        os<<"Products: "<<endl;
        for(int i=0;i<n;i++) {
            os<<i+1<<". "<<products[i].getName()<<" ("<<products[i].getCategory()<<") "<<products[i].getCena()<<" x "<<products[i].getKolicina()<<endl;
        }
    }
    Order filterByCategory(char *category) {
        int counter=0;
        for(int i=0;i<n;i++) {
            if(strcmp(products[i].getCategory(),category)==0) {
                counter++;
            }
        }
        Product* newProducts = new Product[counter];
        int j=0;
        for(int i=0;i<n;i++) {
            if(strcmp(products[i].getCategory(),category)==0) {
                newProducts[j++]=products[i];
            }
        }
       Order r(sifra,imePrez,newProducts,counter);
        return r;
    }
    friend istream& operator>>(istream& is, Order& order) {
        is>>order.sifra;
        is.ignore();
        is>>order.imePrez;
        is.ignore();
        is>>order.n;
        delete [] order.products;
        order.products=new Product[order.n];
        for(int i=0;i<order.n;i++) {
            is>>order.products[i];
        }
        return is;
    }
};
void rff(const char* filename) {
    ifstream in(filename); // објект за читање од фајл
    if (!in) {
        cout << "Cannot open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close(); // затворање на фајлот
}
int main() {

    Order order;
    // TODO: Прочитај ги податоците од фајлот "vlez.txt" и зачувај ги во објектот `order`
    ifstream fin("vlez.txt");
    fin>>order;
    // НЕ МЕНУВАЈ НИШТО ПОМЕЃУ ОВИЕ КОМЕНТАРИ
    char category[20];
    cin>>category;
    // НЕ МЕНУВАЈ НИШТО ПОМЕЃУ ОВИЕ КОМЕНТАРИ

    // TODO: Запиши ги резултатите во фајловите izlez1.txt и izlez2.txt
     ofstream fout1("izlez1.txt");
    order.print(fout1);
    // НЕ МЕНУВАЈ НИШТО ПОДОЛУ
    ofstream fout2("izlez2.txt");
    Order o=order.filterByCategory(category);
    o.print(fout2);
    cout << "Full order information:" << endl;
    rff("izlez1.txt");
    cout << "Products from category " << category << ":" << endl;
    rff("izlez2.txt");

    return 0;
}