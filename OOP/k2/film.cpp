#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Film {
    private:
    string naslov;
    string reziser;
    string kuca;
    int year;
public:
    Film(){}
    Film(string naslov, string reziser, string kuca,int year) {
        this->naslov = naslov;
        this->reziser = reziser;
        this->kuca = kuca;
        this->year = year;
    }
    void print (ofstream& os) {
        os<<"Title: "<<naslov<<", Director: "<<reziser<<", Producer: "<<kuca<<", Year: "<<year<<endl;
    }
    bool operator==(const Film& f) {
        return naslov==f.naslov && reziser==f.reziser && kuca==f.kuca && year==f.year;
    }
    string getNaslov() {
        return naslov;
    }
    string getReziser() {
        return reziser;
    }
    string getKuca() {
        return kuca;
    }
    int getYear() {
        return year;
    }
};
class Festival {
private:
    string ime;
    string lokacija;
    Film *filmovi;
    int n;
    public:
    Film getFilm() {
        ime="";
        lokacija="";
        n=0;
        filmovi=nullptr;
    }
    Festival(string ime, string lokacija,Film *filmovi,int n) {
        this->ime = ime;
        this->lokacija = lokacija;
        this->n=n;
       this->filmovi = new Film[n];
        for(int i=0;i<n;i++) {
            this->filmovi[i]=filmovi[i];
        }
    }
    Festival(const Festival& f) {
        this->ime=f.ime;
        this->lokacija=f.lokacija;
        this->n=f.n;
        this->filmovi=new Film[f.n];
        for(int i=0;i<f.n;i++) {
            this->filmovi[i]=f.filmovi[i];
        }
    }
    Festival& operator=(const Festival& f) {
        if(this!=&f) {
            this->ime=f.ime;
            this->lokacija=f.lokacija;
            this->n=f.n;
            delete [] filmovi;
            this->filmovi=new Film[f.n];
            for(int i=0;i<f.n;i++) {
                this->filmovi[i]=f.filmovi[i];
            }
        }
        return *this;
    }
    void print (ofstream& os) {
        os<<"Festival: "<<ime<<", Location: "<<lokacija<<endl;
        os<<"Films: "<<endl;
        for(int i=0;i<this->n;i++) {
            filmovi[i].print(os);
        }
    }
    Festival& operator-(Film &film) {
        int counter=0;
        for(int i=0;i<this->n;i++) {
            if(filmovi[i].getNaslov()!=film.getNaslov()) {
                counter++;
            }
        }
        Film *temp=new Film[counter];
        int index=0;
        for(int i=0;i<this->n;i++) {
            if(filmovi[i].getNaslov()!=film.getNaslov()) {
                temp[index++]=filmovi[i];
            }
        }
        delete [] filmovi;
        this->filmovi=temp;
        this->n=counter;
        return *this;
    }
    Festival notFromProducer(string producer) {
        int counter=0;
        for(int i=0;i<this->n;i++) {
            if(producer!=filmovi[i].getReziser()) {
                counter++;
            }
        }
        Film *temp=new Film[counter];
        int index=0;
        for(int i=0;i<this->n;i++) {
            if(producer!=filmovi[i].getReziser()) {
                temp[index++]=filmovi[i];
            }
        }
        Festival r(ime,lokacija,temp,counter);
        return r;
    }
};
int main() {
    ifstream fin("vlez_films.txt");
    ofstream fout1("izlez1.txt");
    ofstream fout2("izlez2.txt");

    if (!fin) {
        cout << "Не може да се отвори vlez_films.txt" << endl;
        return 1;
    }

    string imeFest, lokacija;
    int n;

    getline(fin, imeFest);
    getline(fin, lokacija);
    fin >> n;
    fin.ignore();

    Film* filmovi = new Film[n];

    for (int i = 0; i < n; i++) {
        string naslov, reziser, producent;
        int godina;

        getline(fin, naslov);
        getline(fin, reziser);
        getline(fin, producent);
        fin >> godina;
        fin.ignore();

        filmovi[i] = Film(naslov, reziser, producent, godina);
    }

    Festival fest(imeFest, lokacija, filmovi, n);
    fest.print(fout1);

    Festival filt = fest.notFromProducer("CJ Entertainment");
    filt.print(fout2);

    delete[] filmovi;
    fin.close();
    fout1.close();
    fout2.close();

    return 0;
}