#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
enum tip_kniga {
    strucna_literatura,roman
};
class Book {
    char naslov[30];
    int ser;
    static int seriski_broj;
    int tip;
    float cena;
public:
    Book() {}
    Book(char *naslovv,int tipp,float cenaa) {
        strcpy(this->naslov,naslovv);
        this->tip=tipp;
        this->cena=cenaa;
        this->ser=seriski_broj;
        seriski_broj++;
    }
     void setNaslov(char *naslovv) {
        strcpy(this->naslov,naslovv);
    }
    void setTip(tip_kniga tip) {
        this->tip=tip;
    }
    void setCena(float cenaa) {
        this->cena=cenaa;
    }
    int getTip() {
        return this->tip;
    }
    float getCena() {
        return this->cena;
    }
    int getSeriskiBroj() {
        return this->seriski_broj;
    }
    const char *getNaslov() const{
        return this->naslov;
    }
    void print() {
        cout<<ser<<"-"<<naslov<<" ";
        if(tip==strucna_literatura) {
            cout<<"Strucna_literatura ";
        }else {
            cout<<"ROMAN"<<" ";
        }
        cout<<cena<<endl;
    }
    void increasePrice(float p) {
        cena+=p;
    }
};
class BookStore {
    char ime[20];
    Book knigi[100];
    int br_knigi;
    public:
    BookStore() {
        br_knigi=0;
    }
    BookStore(const char *ime) {
        strcpy(this->ime,ime);
    }
    void setNaslov(char *naslov) {
        strcpy(this->ime,naslov);
    }
    char *getNaslov() {
        return this->ime;
    }
    int getBr_knigi() {
        return this->br_knigi;
    }
    void print() {
        cout<<ime<<" ";
        for(int i=0;i<br_knigi;i++) {
            knigi[i].print();
        }
    }
    void addBook(const Book &b) {
        if(br_knigi<100) {
           for(int i=0;i<br_knigi;i++) {
               if(strcmp(b.getNaslov(),knigi[i].getNaslov())==0) {
                   return;
               }
           }
            knigi[br_knigi++]=b;
        }
    }
    bool greaterThan(const BookStore &s) {
        return(this->br_knigi>s.br_knigi);
    }
    void createMarketPrice() {
        for(int i=0;i<br_knigi;i++) {
            if(knigi[i].getTip()==roman) {
                knigi[i].increasePrice(knigi[i].getCena()*0.05);
            }else {
                knigi[i].increasePrice(knigi[i].getCena()*0.03);
            }
        }
    }
};
BookStore best(BookStore bs[],int number) {
    BookStore max=bs[0];
    for(int i=0;i<number;i++) {
        if(bs[i].getBr_knigi()>max.getBr_knigi()) {
            max=bs[i];
        }
    }
    return max;
}
int Book::seriski_broj=777551;
int main() {
    int testCase;
    cin>>testCase;
    if(testCase==0)
    {
        cout<<"TESTING BOOK CONSTRUCTOR"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==1)
    {
        cout<<"TESTING BOOK print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        book1.print();
        book2.print();
        book3.print();
        cout<<"TEST PASSED"<<endl;
    } else if(testCase==2)
    {
        cout<<"TESTING BOOK increasePrice"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        book1.print();
        book2.print();
        book3.print();
        book1.increasePrice(200);
        book2.increasePrice(300);
        book3.increasePrice(150);
        cout<<"===== INCREASE ====="<<endl;
        book1.print();
        book2.print();
        book3.print();
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==3)
    {
        cout<<"TESTING BOOKSTORE CONSTRUCTOR"<<endl;
        BookStore bookStore1("The Book Cellar");
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==4)
    {
        cout<<"TESTING BOOKSTORE addBook() and print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==5)
    {
        cout<<"TESTING BOOKSTORE OPERATOR addBook() and print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Object-oriented programming",0,2300);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        bookStore1.addBook(book4);
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==6)
    {
        cout<<"TESTING BOOKSTORE COPY-CONSTRUCTOR"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        BookStore bookStore2(bookStore1);

        bookStore1.print();
        bookStore2.print();
        cout<<"TEST PASSED"<<endl;

    }else if(testCase==7)
    {
        cout<<"TESTING BOOKSTORE greaterThan "<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        BookStore bookStore3("Word Wizardry Books");
        bookStore3.addBook(book4);
        bookStore3.addBook(book5);
        if(bookStore1.greaterThan(bookStore3))
        {
            cout<<"TEST PASSED"<<endl;
        }
        else
        {
            cout<<"TEST FAILED"<<endl;
        }
    }else if(testCase==8)
    {
        cout<<"TESTING METHOD createMarketPrice()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10];
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i].addBook(books[j]);
            }
        }
        for(int i=0;i<numofBookStores;i++)
        {
            bookStores[i].print();
            cout<<"CREATED MARKET PRICES"<<endl;
            bookStores[i].createMarketPrice();
            bookStores[i].print();
        }

    }else if(testCase==9)
    {
        cout<<"TESTING METHOD best()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10];
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i].addBook(books[j]);
            }
        }
        best(bookStores,numofBookStores).print();
    }
    return 0;
}