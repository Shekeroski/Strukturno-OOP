#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class InvalidFileSizeException {
private:
    double size;
    public:
    InvalidFileSizeException(double size) {
        this->size = size;
    }
    void print() {
        cout << "no valid" <<" Size: "<<size<< endl;
    }
};
class InvalidFormatException {
private:
string message;
    public:
    InvalidFormatException(string message) {
    }
    void print() {
        cout << message << endl;
    }
};
class Book {
protected:
    string title;
    string author;
    public:
    Book(string t="", string a="") {
        this->title=t;
        this->author=a;
    }
    virtual void print() const{
        cout<<"Title: "<<title<<" "<<"Author: "<<author<<endl;
    }
};
class DigitalCopy {
    protected:
    double fileSize;
    string formats[3];
    bool isValid(const string& s) {
        return s=="PDF" || s=="EPUB" || s=="MOBI";
    }
    public:
    DigitalCopy(): formats{"PDF","EPUB","MOBI"} {
        this->fileSize=0;
    }
    DigitalCopy(double fileSize,string formats[3]) {
        if(fileSize<=0 || fileSize>1000) {
            throw InvalidFileSizeException(fileSize);
        }
        this->fileSize=fileSize;
        for(int i=0;i<3;i++) {
            if(!isValid(formats[i])) {
                throw InvalidFormatException("no valid");
            }
            this->formats[i]=formats[i];
        }
    }
    virtual void print() const {
        cout<<"File Size: "<<this->fileSize<<endl;
        for(int i=0;i<3;i++) {
            cout<<this->formats[i]<<endl;
        }
    }
};
class EBook : public Book, public DigitalCopy {
public:
    EBook(string title, string author, double fileSize, string formats[3])
            : Book(title, author), DigitalCopy(fileSize, formats) {}

    void print() const override {
        cout << "EBook:" << endl;
        Book::print();
        DigitalCopy::print();
    }
};

class AudioBook : public Book, public DigitalCopy {
public:
    AudioBook(string title, string author, double fileSize, string formats[3])
            : Book(title, author), DigitalCopy(fileSize, formats) {}

    void print() const override {
        cout << "AudioBook:" << endl;
        Book::print();
        DigitalCopy::print();
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string title, author;
        double fileSize;
        string formats[3];

        getline(cin, title);
        getline(cin, author);
        cin >> fileSize;

        for (int j = 0; j < 3; ++j) {
            cin >> formats[j];
        }
        cin.ignore();

        try {
            if (i % 2 == 0) {
                EBook eb(title, author, fileSize, formats);
                eb.print();
            } else {
                AudioBook ab(title, author, fileSize, formats);
                ab.print();
            }
        }
        catch (InvalidFileSizeException &e) {
            e.print();
        }
        catch (InvalidFormatException &e) {
            e.print();
        }
    }

    return 0;
}