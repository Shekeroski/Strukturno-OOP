#include<iostream>
#include<cstring>
using namespace std;
enum zanr {
    ACTION,COMEDY,DRAMA
};
class Movie {
    char naslov[20];
    zanr zanrr;
    int vreme;
    float rating;
public:
    Movie() {}
    Movie(const char *naslov,zanr zanrr,int vreme,float rating) {
        strcpy(this->naslov,naslov);
        this->zanrr=zanrr;
        this->vreme=vreme;
        this->rating=rating;
    }
    Movie(const Movie &m) {
        strcpy(this->naslov,m.naslov);
        this->zanrr=m.zanrr;
        this->vreme=m.vreme;
        this->rating=m.rating;
    }
    const char *getNaslov() const{
        return naslov;
    }
    void setVreme(int v) {
        this->vreme=v;
    }
    int getVreme() {
        return this->vreme;
    }
    void print() {
        cout<<naslov<<" "<<vreme<<" "<<rating<<endl;
        if(zanrr==ACTION) {
            cout<<"ACTION"<<endl;
        }else if(zanrr==COMEDY) {
            cout<<"COMEDY"<<endl;
        }else {
            cout<<"DRAMA"<<endl;
        }
    }
    zanr getZanrr() const {
        return zanrr;
    }
};
class CinemaHall {
    char name[20];
    Movie movie[20];
    int br_filmoj;
public:
    CinemaHall() {}
    CinemaHall(const char *name,int br_filmoj,Movie movies[]){
        strcpy(this->name,name);
        this->br_filmoj=br_filmoj;
        for(int i=0;i<20;i++) {
            this->movie[i]=movies[i];
        }
    }
    CinemaHall(const char *name) {
        strcpy(this->name,name);
    }
    CinemaHall(const CinemaHall &m) {
        strcpy(this->name,m.name);
        this->br_filmoj=m.br_filmoj;
        for(int i=0;i<20;i++) {
            this->movie[i]=m.movie[i];
        }
    }
    void addMovie(const Movie &m) {
        for(int i=0;i<br_filmoj;i++) {
            if(strcmp(m.getNaslov(),movie[i].getNaslov())==0){
                return;
            }
        }
        movie[br_filmoj]=m;
        br_filmoj++;
    }
    Movie getmovie(int i) {
        return movie[i];
    }
    void print() {
        for(int i=0;i<br_filmoj;i++) {
            movie[i].print();
        }
    }
    void filterByGenre(zanr r) {
        for(int i=0;i<br_filmoj;i++) {
           if(movie[i].getZanrr()==r) {
               movie[i].print();
           }
        }
    }
    Movie longestMovie() {
        int temp=0;
        for(int i=0;i<br_filmoj;i++) {
                if(movie[i].getVreme()>movie[temp].getVreme()) {
                    temp=i;
                }
        }
       return movie[temp];
    }
};

int main() {
    CinemaHall c("Cineplex");

    Movie m1("Inception", ACTION, 148, 8.8);
    Movie m2("The Hangover", COMEDY, 100, 7.5);
    Movie m3("The Godfather", DRAMA, 175, 9.2);
    Movie m4("Inception", ACTION, 148, 8.8); // дупликат, не се додава

    c.addMovie(m1);
    c.addMovie(m2);
    c.addMovie(m3);
    c.addMovie(m4); // нема да биде додаден

    c.print();

    cout << "\nФилмови од жанр DRAMA:\n";
    c.filterByGenre(DRAMA);

    Movie longest = c.longestMovie();
    cout << "\nНајдолг филм:\n";
    longest.print();

    return 0;
}