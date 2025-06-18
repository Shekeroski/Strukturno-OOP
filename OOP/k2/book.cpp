#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Book {
private:
    string naslov;
    string imePrez;
    string izdavac;
    int godina;
public:
    Book(){}
    Book(string naslov,string imePrez,string izdavac,int godina) {
        this->naslov=naslov;
        this->imePrez=imePrez;
        this->izdavac=izdavac;
        this->godina=godina;
    }
    string getNaslov() {
        return naslov;
    }
    string getImePrez() {
        return imePrez;
    }
    int getGodina() {
        return godina;
    }
    string getizdavac() {
        return izdavac;
    }
    friend istream& operator>>(istream& is, Book& b) {
        getline(is,b.naslov);
        getline(is,b.imePrez);
        is >> b.izdavac;
        is >> b.godina;
    }
};
class Library {
private:
    string imeBiblioteka;
    string grad;
    Book *books;
    int n;
    public:
    Library() {
        this->imeBiblioteka="";
        this->grad="";
        this->books=nullptr;
        this->n=0;
    }
    Library(string imeBiblioteka,string grad,Book *books,int n) {
        this->imeBiblioteka=imeBiblioteka;
        this->grad=grad;
        this->n=n;
        if(n>0 && books!=nullptr) {
            this->books=new Book[n];
            for(int i=0;i<n;i++) {
                this->books[i]=books[i];
            }
        }
    }
    Library(const Library& library) {
        this->imeBiblioteka=library.imeBiblioteka;
        this->grad=library.grad;
        this->n=library.n;
        if(n>0) {
            this->books=new Book[library.n];
            for(int i=0;i<n;i++) {
                this->books[i]=library.books[i];
            }
        }
    }
    Library& operator=(const Library& library) {
        if(this!=&library) {
            this->imeBiblioteka=library.imeBiblioteka;
            this->grad=library.grad;
            this->n=library.n;
            if(n>0) {
                this->books=new Book[library.n];
                for(int i=0;i<n;i++) {
                    this->books[i]=library.books[i];
                }
            }
        }
        return *this;
    }
    ~Library() {
        delete[] this->books;
    }
    Library& operator-( Book& library) {
        int counter=0;
        if(n==0) {
            cout<<"Trying to delete from an empty Library!"<<endl;
        }
        for(int i=0;i<n;i++) {
            if(books[i].getNaslov()!=library.getNaslov() && books[i].getImePrez()!=library.getImePrez() && books[i].getizdavac()!=library.getizdavac()) {
                counter++;
            }
        }
        Book *temp=new Book[counter];
        int index=0;
        for(int i=0;i<n;i++) {
            if(books[i].getNaslov()!=library.getNaslov() && books[i].getImePrez()!=library.getImePrez() && books[i].getizdavac()!=library.getizdavac()) {
                temp[index++]=books[i];
            }
        }
        delete[] this->books;
        this->books=temp;
        this->n=counter;
        return *this;
    }
    void print(ofstream& out) {
        out<<"Library: "<<imeBiblioteka<<", City: "<<grad<<endl;
        out<<"Books: "<<endl;
        for(int i=0;i<n;i++) {
            out<<"Title: "<<books[i].getNaslov()<<", "<<"Author: "<<books[i].getImePrez()<<", Publisher: "<<books[i].getizdavac()<<", Year: "<<books[i].getGodina()<<endl;
        }
    }
    friend istream& operator>>(istream& is, Library& library) {
        getline(is,library.imeBiblioteka);
        is>>library.grad;
        is>>library.n;
        is.ignore();
        delete[] library.books;
        library.books=new Book[library.n];
        for(int i=0;i<library.n;i++) {
            is>>library.books[i];
        }
    }
    Library notFromPublisher(string publisher) {
        int counter=0;
        for(int i=0;i<n;i++) {
            if(books[i].getizdavac()!=publisher) {
                counter++;
            }
        }
        Book *temp=new Book[counter];
        int index=0;
        for(int i=0;i<n;i++) {
            if(books[i].getizdavac()!=publisher) {
                temp[index++]=books[i];
            }
        }
        Library r(imeBiblioteka,grad,temp,counter);
        return r;
    }
};
int main() {
    ifstream fin("vlezna.txt");
    ofstream fout1("izlez1.txt");
    ofstream fout2("izlez2.txt");

    if (!fin) {
        cout << "Не може да се отвори vlezna.txt" << endl;
        return 1;
    }

    string name, city;
    int n;

    getline(fin, name);
    getline(fin, city);
    fin >> n;
    fin.ignore(); // за да скокнеме нов ред по бројот

    Book* books = new Book[n];

    for (int i = 0; i < n; i++) {
        string title, author, publisher;
        int year;

        getline(fin, title);
        getline(fin, author);
        getline(fin, publisher);
        fin >> year;
        fin.ignore(); // за да скокнеме нов ред

        books[i] = Book(title, author, publisher, year);
    }

    Library lib(name, city, books, n);
    lib.print(fout1);

    // Генерирај нова библиотека без книги од "Три"
    Library filtered = lib.notFromPublisher("Три");
    filtered.print(fout2);

    delete[] books;
    fin.close();
    fout1.close();
    fout2.close();

    return 0;
}