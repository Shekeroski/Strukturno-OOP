#include <iostream>
#include<string>
#include <fstream>
using namespace std;
class Song {
private:
    string naslov;
    string imePrez;
    string izveduvac;
    int vremetraenje;
    public:
    Song(){}
    Song(string naslov, string imePrez, string izveduvac,int vremetraenje) {
        this->naslov = naslov;
        this->imePrez = imePrez;
        this->izveduvac = izveduvac;
        this->vremetraenje = vremetraenje;
    }
    string getNaslov() {
        return naslov;
    }
    string getImePrez() {
        return imePrez;
    }
    int getVremetraenje() {
        return vremetraenje;
    }
    string getizveduvac() {
        return izveduvac;
    }
    void setNaslov(string naslovv) {
        this->naslov = naslovv;
    }
    void setImePrez(string imePrez) {
        this->imePrez = imePrez;
    }
    void setVremetraenje(int vremetraenje) {
        this->vremetraenje = vremetraenje;
    }
    void setizveduvac(string izveduvac) {
        this->izveduvac = izveduvac;
    }
    void print(ofstream &out) {
        out<<"Song title: "<<naslov<<", Author: "<<imePrez<<", Interpreted by: "<<izveduvac<<", "<<vremetraenje<<" sek."<<endl;
    }
    friend istream &operator>>(istream &in, Song &song) {
        getline(in, song.naslov);
        getline(in, song.imePrez);
        getline(in, song.izveduvac);
        in >> song.vremetraenje;
        in.ignore();
        return in;
    }
    bool operator==(const Song &song) {
        return naslov==song.naslov && imePrez==song.imePrez && izveduvac==song.izveduvac && vremetraenje==song.vremetraenje;
    }
};
class Festival {
    private:
    string ime;
    string grad;
    string datum;
    Song *songs;
    int brojPesni;
    public:
    Festival() {
        ime = "";
        grad = "";
        datum = "00/00/0000";
        brojPesni = 0;
        songs = nullptr;
    }
    Festival(string ime, string grad, string datum,Song *songs,int brojPesni) {
        this->ime = ime;
        this->grad = grad;
        this->datum = datum;
        this->brojPesni = brojPesni;
        this->songs = new Song[brojPesni];
        for (int i = 0; i < brojPesni; i++) {
            this->songs[i] = songs[i];
        }
    }
    Festival(const Festival &f) {
        this->ime = f.ime;
        this->grad = f.grad;
        this->datum = f.datum;
        this->brojPesni = f.brojPesni;
        this->songs = new Song[f.brojPesni];
        for (int i = 0; i < f.brojPesni; i++) {
            this->songs[i] = f.songs[i];
        }
    }
    Festival &operator=(const Festival &f) {
        if(this != &f) {
            delete [] this->songs;
            this->ime = f.ime;
            this->grad = f.grad;
            this->datum = f.datum;
            this->brojPesni = f.brojPesni;
            this->songs = new Song[f.brojPesni];
            for (int i = 0; i < f.brojPesni; i++) {
                this->songs[i] = f.songs[i];
            }
        }
        return *this;
    }
    ~Festival() {
        delete [] this->songs;
    }
    Festival& operator-=(Song &s) {
        if(brojPesni==0) {
            cout<< "Trying to delete from an empty list!"<<endl;
            return *this;
        }
        int newSize=0;
        for(int i=0;i<brojPesni;i++) {
            if((songs[i]!=s)) {
                newSize++;
            }
        }
        if(newSize==brojPesni) {
            return *this;
        }
        Song *temp=new Song[newSize];
        int idx=0;
        for(int i=0;i<brojPesni;i++) {
            if((songs[i]!=s)) {
                temp[idx++]=songs[i];
            }
        }
        delete[] songs;
        songs=temp;
        brojPesni=newSize;
        return *this;
    }
    void print(ofstream& out) {
        out<<"Festival: "<<ime<<" - "<<grad<<", "<<datum<<endl;
        for (int i = 0; i < brojPesni; i++) {
            songs[i].print(out);
        }
    }
    friend istream &operator>>(istream &in, Festival &f) {
        getline(in, f.ime);
        getline(in, f.grad);
        in >> f.datum;
        in >> f.brojPesni;
        in.ignore();
        delete [] f.songs;
        f.songs = new Song[f.brojPesni];
        for (int i = 0; i < f.brojPesni; i++) {
            in >> f.songs[i];
        }
        return in;
    }
    Festival notFromAuthor(string author) {
        int counter=0;
        for (int i = 0; i < brojPesni; i++) {
            if(songs[i].getImePrez()!=author) {
                counter++;
            }
        }
        Song *temp = new Song[counter];
        int j=0;
        for (int i = 0; i < brojPesni; i++) {
            if(songs[i].getImePrez()!=author) {
                temp[j++] = songs[i];
            }
        }
        Festival f(ime, grad, datum, temp, counter);
        return f;
    }
};

void wtf() {
    ofstream fout("vlezna.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----"){
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

    Festival festival;
    //TODO your code here
    //TODO Read the data from the file and store them in `festival`
    ifstream fin("vlezna.txt");
    fin >> festival;
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string author;
    getline(cin, author);
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files izlezna1.txt and izlezna2.txt after this line
    ofstream fout1("izlezna1.txt");
    festival.print(fout1);
    ofstream fout2("izlezna2.txt");
    Festival fes=festival.notFromAuthor(author);
    fes.print(fout2);

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");


    return 0;
}