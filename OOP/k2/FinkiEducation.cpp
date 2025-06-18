#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Book {
protected:
	char ISBN[20];
	char naslov[50];
	char avtor[30];
	double cena;
public:
	Book() {}
	Book(const char *ISBN, const char *naslov, const char *avtor, double cena) {
		strcpy(this->ISBN, ISBN);
		strcpy(this->naslov, naslov);
		strcpy(this->avtor, avtor);
		this->cena = cena;
	}
	Book& operator=(const Book& b) {
		if (this != &b) {
			strcpy(this->ISBN, b.ISBN);
			strcpy(this->naslov, b.naslov);
			strcpy(this->avtor, b.avtor);
			this->cena = b.cena;
		}
		return *this;
	}
	void setISBN(const char *isbn) {
		strcpy(this->ISBN, isbn);
	}
	bool operator>(const Book &b) {
		return(this->cena > b.cena);
	}
	virtual double bookPrice()const =0;

	virtual void print(ostream &os)const = 0;
	friend ostream &operator<<(ostream &os, const Book &b) {
		b.print(os);
		return os;
	}
};
class OnlineBook : public Book {
private:
	char *url;
	int MB;
public:
	OnlineBook(const char *ISBN, const char *naslov, const char *avtor,double cena,const char *url, int MB):Book(ISBN,naslov,avtor,cena) {
		this->url = new char[strlen(url)+1];
		strcpy(this->url, url);
		this->MB = MB;
	}
	OnlineBook(const OnlineBook &o):Book(o) {
		this->url = new char[strlen(o.url)+1];
		strcpy(this->url,o.url);
		this->MB = o.MB;
	}
	OnlineBook &operator=(const OnlineBook &o) {
		if (this != &o) {
			delete [] this->url;
			Book::operator=(o);
			this->url = new char[strlen(o.url)+1];
			strcpy(this->url,o.url);
			this->MB = o.MB;
		}
		return *this;
	}
	~OnlineBook() {
		delete[] url;
	}
	double bookPrice()const override {
		if(MB>20) {
			return cena + (cena*0.2);
		}else {
			return cena;
		}
	}
	void print(ostream &os)const override {
		os << "ISBN: " << ISBN << endl
		   << "Title: " << naslov << endl
		   << "Author: " << avtor << endl
		   << "Price: " << bookPrice() << endl
		   << "URL: " << url << endl
		   << "Size: " << MB << "MB" << endl;
	}
};
class PrintBook : public Book {
private:
	double masa;
	bool daliIma;
public:
	PrintBook(const char *ISBN, const char *naslov, const char *avtor,double cena,double masa,bool daliIma):Book(ISBN,naslov,avtor,cena) {
		this->masa = masa;
		this->daliIma = daliIma;
	}
	PrintBook(const PrintBook &o):Book(o) {
		this->masa = o.masa;
		this->daliIma = o.daliIma;
	}
	PrintBook &operator=(const PrintBook &o) {
		if (this != &o) {
			Book::operator=(o);
			this->masa = o.masa;
			this->daliIma = o.daliIma;
		}
		return *this;
	}
	double bookPrice()const override{
		if(masa>0.7) {
			return cena + (cena*0.15);
		}else {
			return cena;
		}
	}
	void print(ostream &os) const override {
		os << "ISBN: " << ISBN << endl
		   << "Title: " << naslov << endl
		   << "Author: " << avtor << endl
		   << "Price: " << bookPrice() << endl
		   << "Weight: " << masa << "kg" << endl
		   << "In stock: " << (daliIma ? "true" : "false") << endl;
	}
};
void mostExpensiveBook (Book** books, int n) {
	int online=0;
	int printed=0;
	Book *maxbook=books[0];
	for(int i=1;i<n;i++) {
		if(dynamic_cast<OnlineBook*>(books[i])) {
			online++;
		}
		if(dynamic_cast<PrintBook*>(books[i])) {
			printed++;
		}
		if(*books[i]>*maxbook) {
			maxbook=books[i];
		}
	}
	cout << "Total number of online books: " << online << endl;
	cout << "Total number of print books: " << printed << endl;
	cout << "The most expensive book is:" << endl;
	cout << *maxbook;
}
int main(){

	char isbn[20], title[50], author[30], url[100];
	int size, tip;
	float price, weight;
	bool inStock;
	Book  **books;
	int n;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> url;
			cin >> size;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn;
		cin.get();
		cin.getline(title, 50);
		cin.getline(author, 30);
		cin >> price;
		cin >> url;
		cin >> size;
		cout << "CONSTRUCTOR" << endl;
		OnlineBook ob1(isbn, title, author, price, url, size);
		cout << ob1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		OnlineBook ob2(ob1);
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
		cout << "OPERATOR =" << endl;
		ob1 = ob2;
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> weight;
			cin >> inStock;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i<n; i++){

			cin >> tip >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			if (tip == 1) {

				cin >> url;
				cin >> size;

				books[i] = new OnlineBook(isbn, title, author, price, url, size);

			}
			else {
				cin >> weight;
				cin >> inStock;

				books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			}
		}

		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) delete books[i];
		delete[] books;
	return 0;
}
