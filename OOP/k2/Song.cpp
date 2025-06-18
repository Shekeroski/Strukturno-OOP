#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Song {
private:
    string title;
    string name;
    string izveduvac;
    int time_sec;
public:
    Song(string title="",string name="",string izveduvac="",int time_sec=0) {
        this->title=title;
        this->name=name;
        this->izveduvac=izveduvac;
        this->time_sec=time_sec;
    }
    Song(const Song& s) {
        this->title=s.title;
        this->name=s.name;
        this->izveduvac=s.izveduvac;
        this->time_sec=s.time_sec;
    }
    void setTitle(string title) {
        this->title=title;
    }
    void setName(string name) {
        this->name=name;
    }
    void setIzveduvac(string izveduvac) {
        this->izveduvac=izveduvac;
    }
    void setTimeSec(int time_sec) {
        this->time_sec=time_sec;
    }
    string getTitle() {
        return this->title;
    }
    string getName() {
        return this->name;
    }
    string getIzveduvac() {
        return this->izveduvac;
    }
    int getTimeSec() {
        return this->time_sec;
    }
    void print(ofstream &out) {
        out << "Song title: " << title
        << ", Author: " << name
        << ", Interpreted by: " << izveduvac
        << ", " << time_sec << " sek." << endl;
    }
    friend istream& operator>>(istream &in, Song& s) {
        getline(in, s.title);
        getline(in, s.name);
        getline(in, s.izveduvac);
        in >> s.time_sec;
        in.ignore();
        return in;
    }
    bool operator==(const Song& s) const {
        return title==s.title &&
            name==s.name &&
                izveduvac==s.izveduvac &&
                        time_sec==s.time_sec;
    }
};
class Festival {
private:
    string name;
    string town;
    string date;
    Song *songs;
    int n;
public:
    Festival(string name="",string town="",string date="00/00/00",Song *songs=nullptr,int n=0) {
      this->name=name;
        this->town=town;
        this->date=date;
        this->n=n;
        if(n>0 && songs!=nullptr) {
            this->songs= new Song[n];
            for(int i=0;i<n;i++) {
                this->songs[i]=songs[i];
            }
        }else {
            this->songs=nullptr;
        }
    }
    Festival(const Festival& f) {
        this->name=f.name;
        this->town=f.town;
        this->date=f.date;
        this->n=f.n;
        if(n>0 && f.songs!=nullptr) {
            songs= new Song[n];
            for(int i=0;i<n;i++) {
                this->songs[i]=f.songs[i];
            }
        }else {
            this->songs=nullptr;
        }
    }
    Festival& operator=(const Festival &f) {
        if(this!=&f) {
            delete[] songs;
            this->name=f.name;
            this->town=f.town;
            this->date=f.date;
            this->n=f.n;
            songs=nullptr;
            if(n>0) {
                songs = new Song[n];
                for(int i=0;i<n;i++) {
                    songs[i]=f.songs[i];
                }
            }
        }
        return *this;
    }
    ~Festival() {
        delete[] songs;
    }
   Festival& operator-=(Song &s) {
      if(n==0) {
          cout<< "Trying to delete from an empty list!"<<endl;
          return *this;
      }
        int newSize=0;
        for(int i=0;i<n;i++) {
            if(!(songs[i]==s)) {
                newSize++;
            }
        }
        if(newSize==n) {
            return *this;
        }
        Song *temp=new Song[newSize];
        int idx=0;
        for(int i=0;i<n;i++) {
            if(!(songs[i]==s)) {
                temp[idx++]=songs[i];
            }
        }
        delete[] songs;
        songs=temp;
        n=newSize;
        return *this;
    }
    void print(ofstream& out) {
        out << "Festival: " << name << " - " << town << ", " << date << endl;
        for(int i=0; i<n; i++) {
            songs[i].print(out);
        }
    }
    friend istream&operator>>(istream &in, Festival& f) {
        getline(in, f.name);
        getline(in, f.town);
        getline(in, f.date);
        in>>f.n;
        in.ignore();
        delete[] f.songs;
        f.songs= new Song[f.n];
        for(int i=0;i<f.n;i++) {
            in>>f.songs[i];
        }
        return in;
    }
    Festival FestivalNotFromAuthor(string author) {
    int count=0;
        for(int i=0;i<n;i++) {
            if(songs[i].getName()!=author) {
                count++;
            }
        }

        Song* temp=new Song[count];
        int j=0;
        for(int i=0;i<n;i++) {
            if(songs[i].getName()!=author) {
                temp[j++]=songs[i];
            }
        }
        Festival result(name,town,date,temp,count);
        return result;
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
    //TODO Read the data from the file and store them in `festival`
    ifstream fin("vlezna.txt");
    fin>>festival;
    fin.close();

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string author;
    getline(cin, author);
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files izlezna1.txt and izlezna2.txt after this line
ofstream fout1("izlezna1.txt");
    festival.print(fout1);
    fout1.close();
    Festival filtered = festival.FestivalNotFromAuthor(author);
ofstream fout2("izlezna2.txt") ;
    filtered.print(fout2);
     fout2.close();

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");


    return 0;
}