#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class MovieActor {
protected:
    char *name;
    char drzava[40];
    double prosek_ocena;
    int vkupnoFilmovi;
    double vkupnaZarabotka;
public:
    MovieActor(char *name="",char *drzava="",double prosek=0.0,int vkupnoFilmovi=0,double vkupnaZarabotka=0) {
        this->name = new char [strlen(name)+1];
        strcpy(this->name,name);
        strcpy(this->drzava,drzava);
        this->prosek_ocena=prosek;
        this->vkupnoFilmovi=vkupnoFilmovi;
        this->vkupnaZarabotka=vkupnaZarabotka;
    }
    MovieActor(const MovieActor &movie) {
        this->name = new char [strlen(movie.name)+1];
        strcpy(this->name,movie.name);
        strcpy(this->drzava,movie.drzava);
        this->prosek_ocena=movie.prosek_ocena;
        this->vkupnoFilmovi=movie.vkupnoFilmovi;
        this->vkupnaZarabotka=movie.vkupnaZarabotka;
    }
    MovieActor &operator=(const MovieActor &movie) {
        if(this!=&movie) {
            delete [] this->name;
            this->name = new char [strlen(movie.name)+1];
            strcpy(this->name,movie.name);
            strcpy(this->drzava,movie.drzava);
            this->prosek_ocena=movie.prosek_ocena;
            this->vkupnoFilmovi=movie.vkupnoFilmovi;
            this->vkupnaZarabotka=movie.vkupnaZarabotka;
        }
        return *this;
    }
    ~MovieActor() {
        delete [] this->name;
    }
    virtual double rating() {
        return (prosek_ocena*0.4)+(vkupnoFilmovi*0.2)+(vkupnaZarabotka*0.4);
    }
    virtual void print() {
        cout<<name<<"-"<<drzava<<endl;
        cout<<"Average rating: "<<prosek_ocena<<endl;
        cout<<"Movies this year: "<<vkupnoFilmovi<<endl;
        cout<<"Total earnings: "<<vkupnaZarabotka<<endl;
        cout<<"Rating: "<<rating()<<endl;
    }
};
class OscarWinner : public MovieActor {
private:
    double ratingOscar;
    int brfilmoviOscar;
    double vkupnaZarabotkaOskar;
public:
    OscarWinner():MovieActor() {
        this->ratingOscar=0;
        this->brfilmoviOscar=0;
        this->vkupnaZarabotkaOskar=0;
    }
    OscarWinner(const MovieActor &m,double ratingOscar,int brfilmoviOscar,double vkupnaZarabotkaOskar):MovieActor(m) {
        this->ratingOscar=ratingOscar;
        this->brfilmoviOscar=brfilmoviOscar;
        this->vkupnaZarabotkaOskar=vkupnaZarabotkaOskar;
    }
    OscarWinner(const OscarWinner &o):MovieActor(o) {
        this->ratingOscar=o.ratingOscar;
        this->brfilmoviOscar=o.brfilmoviOscar;
        this->vkupnaZarabotkaOskar=o.vkupnaZarabotkaOskar;
    }
    OscarWinner &operator=(const OscarWinner &o) {
        if(this!=&o) {
            MovieActor::operator=(o);
            this->ratingOscar=o.ratingOscar;
            this->brfilmoviOscar=o.brfilmoviOscar;
            this->vkupnaZarabotkaOskar=o.vkupnaZarabotkaOskar;
        }
        return *this;
    }
    OscarWinner(char *name,char *drzava,double prosek,int vkupnoFilmovi,double vkupnaZarabotka,double ratingOscar,int brfilmoviOscar,double vkupnaZarabotkaOskar):MovieActor(name,drzava,prosek,vkupnoFilmovi,vkupnaZarabotka) {
        this->ratingOscar=ratingOscar;
        this->brfilmoviOscar=brfilmoviOscar;
        this->vkupnaZarabotkaOskar=vkupnaZarabotkaOskar;
    }
    ~OscarWinner() {}
    double OscarRating() {
        return (ratingOscar*0.6)+(brfilmoviOscar*0.1)+(vkupnaZarabotkaOskar*0.3);
    }
    double rating() override {
        return (MovieActor::rating()+OscarRating())/2;
    }
    void print() override {
        MovieActor::print();
        cout<<"Oscar Rating: "<<OscarRating()<<endl;
        cout<<"New rating: "<<rating()<<endl;
    }
};
int main() {
    char name[100];
    char country[41];
    double avg_rating;
    int num_movies;
    double earnings;
    double post_avg_rating;
    int post_num_movies;
    double post_earnings;

    int n;
    cin >> n;

    if (n == 1) {
        // Test MovieActor basic functionality
        cout << "MOVIE ACTORS:" << endl;
        cout << "=====================================" << endl;
        int numActors;
        cin >> numActors;

        MovieActor* actors = new MovieActor[numActors];

        for (int i = 0; i < numActors; ++i) {
            cin >> name >> country >> avg_rating >> num_movies >> earnings;
            actors[i] = MovieActor(name, country, avg_rating, num_movies, earnings);
            actors[i].print();
            cout << "-------------------------" << endl;
        }

        delete[] actors;
    }
    else if (n == 2) {
        // Test MovieActor and create OscarWinner from it
        int numActors;
        cin >> numActors;

        MovieActor* actors = new MovieActor[numActors];
        OscarWinner* oscarWinners = new OscarWinner[numActors];

        for (int i = 0; i < numActors; ++i) {
            cin >> name >> country >> avg_rating >> num_movies >> earnings;
            cin >> post_avg_rating >> post_num_movies >> post_earnings;

            actors[i] = MovieActor(name, country, avg_rating, num_movies, earnings);
            oscarWinners[i] = OscarWinner(actors[i], post_avg_rating, post_num_movies, post_earnings);
        }

        cout << "MOVIE ACTORS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < numActors; ++i) {
            actors[i].print();
            cout << "-------------------------" << endl;
        }

        cout << "OSCAR WINNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < numActors; ++i) {
            oscarWinners[i].print();
            cout << "-------------------------" << endl;
        }

        delete[] actors;
        delete[] oscarWinners;
    }
    else if (n == 3) {
        // Test OscarWinner with all arguments constructor
        int numWinners;
        cin >> numWinners;

        OscarWinner* oscarWinners = new OscarWinner[numWinners];

        for (int i = 0; i < numWinners; ++i) {
            cin >> name >> country >> avg_rating >> num_movies >> earnings;
            cin >> post_avg_rating >> post_num_movies >> post_earnings;

            oscarWinners[i] = OscarWinner(name, country, avg_rating, num_movies, earnings,
                                          post_avg_rating, post_num_movies, post_earnings);
        }

        cout << "OSCAR WINNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < numWinners; ++i) {
            oscarWinners[i].print();
            cout << "-------------------------" << endl;
        }

        delete[] oscarWinners;
    }
    else if (n == 4) {
        // Test copy constructor and operator= for MovieActor
        MovieActor actor1;
        cin >> name >> country >> avg_rating >> num_movies >> earnings;
        actor1 = MovieActor(name, country, avg_rating, num_movies, earnings);

        MovieActor actor2(actor1); // Using copy constructor
        MovieActor actor3;
        actor3 = actor1;           // Using operator=

        cout << "ORIGINAL:" << endl;
        actor1.print();
        cout << "-------------------------" << endl;

        cout << "COPY CONSTRUCTOR:" << endl;
        actor2.print();
        cout << "-------------------------" << endl;

        cout << "OPERATOR=:" << endl;
        actor3.print();
        cout << "-------------------------" << endl;
    }
    else if (n == 5) {
        // Test copy constructor and operator= for OscarWinner
        OscarWinner winner1;
        cin >> name >> country >> avg_rating >> num_movies >> earnings;
        cin >> post_avg_rating >> post_num_movies >> post_earnings;

        winner1 = OscarWinner(name, country, avg_rating, num_movies, earnings,
                              post_avg_rating, post_num_movies, post_earnings);

        OscarWinner winner2(winner1); // Using copy constructor
        OscarWinner winner3;
        winner3 = winner1;            // Using operator=

        cout << "ORIGINAL:" << endl;
        winner1.print();
        cout << "-------------------------" << endl;

        cout << "COPY CONSTRUCTOR:" << endl;
        winner2.print();
        cout << "-------------------------" << endl;

        cout << "OPERATOR=:" << endl;
        winner3.print();
        cout << "-------------------------" << endl;
    }

    return 0;
}