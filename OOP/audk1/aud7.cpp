#include<iostream>
#include<cstring>
using namespace std;

class Book {
private:
    char name[10];
    char author[10];
    bool availability;
    friend class Library;
    friend class LibraryMember;
    friend void checkOutBook(LibraryMember &l,Library &lib,int id);
public:
    Book() {}
    Book(const char *n, const char *a,bool _a) {
        strcpy(name,n);
        strcpy(author,a);
        availability = _a;
    }
    Book(const Book &b) {
        strcpy(name,b.name);
        strcpy(author,b.author);
        availability = b.availability;
    }
    ~Book(){}
};
class Library {
  char name[10];
    Book books[30];
    int brknigi;
    friend class LibraryMember;
    friend void checkOutBook(LibraryMember &l,Library &lib,int id);
public:
    Library() {
        brknigi = 0;
        strcpy(name,"Braca miladinovci");
    }
    void addBook(Book &b) {
        if(brknigi<30) {
            books[brknigi++] = b;
        }else {
            cout<<"library is full"<<endl;
        }
    }
    void print() {
        for(int i=0;i<brknigi;i++) {
            cout<<books[i].name<<" "<<books[i].author<<books[i].availability<<endl;
        }
    }

};
class LibraryMember {
    char name[10];
    int id;
    friend void checkOutBook(LibraryMember &l,Library &lib,int id);
public:
    LibraryMember(){}
    LibraryMember(const char *n, int _id) {
        strcpy(name,n);
        id=_id;
    }
};
void checkOutBook(LibraryMember &l,Library &lib,int id) {
    if(lib.books[id].availability) {
        cout<<l.name<<" "<<l.id<<lib.books[id].name<<endl;
        lib.books[id].availability = false;
    }
    else {
        cout<<"sorry"<<endl;
    }
}
int main() {
    Library l1;
    int n;
    cout << "Enter the number of books" << endl;
    cin >> n;
    char name[30], author[30];
    bool availability;
    for (int i = 0; i < n; i++) {
        cin >> name >> author >> availability;
        Book b = Book(name, author, availability);
        l1.addBook(b);
    }
    l1.print();
    LibraryMember m1("Marko", 9541);
    int index;
    cin >> index;
    checkOutBook(m1, l1, index);
    return 0;
}