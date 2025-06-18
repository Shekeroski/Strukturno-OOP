#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class NBAplayer {
protected:
    char *name;
    char tim[10];
    double prs_poeni;
    double prs_asistencii;
    double prs_skokovi;
    void copy(const NBAplayer &n) {
        this->name=new char[strlen(n.name)+1];
        strcpy(this->name,n.name);
        strcpy(this->tim,n.tim);
        this->prs_poeni=n.prs_poeni;
        this->prs_asistencii=n.prs_asistencii;
        this->prs_skokovi=n.prs_skokovi;
    }
public:
    NBAplayer() {}
    NBAplayer(char *name,char *tim,double prs_poeni=0,double prs_asistencii=0,double prs_skokovi=0) {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        strcpy(this->tim,tim);
        this->prs_poeni=prs_poeni;
        this->prs_asistencii=prs_asistencii;
        this->prs_skokovi=prs_skokovi;
    }
    NBAplayer(const NBAplayer &n) {
        copy(n);
    }
    NBAplayer& operator=(const NBAplayer &n) {
        if(this!=&n) {
            delete[] this->name;
            copy(n);
        }
        return *this;
    }
    ~NBAplayer() {
        delete[] name;
    }
    double rating() {
        return (0.45 * prs_poeni+ 0.30*prs_asistencii + 0.25*prs_skokovi);
    }
    void print() {
        cout<<"Name: "<<name<<" "<<"Tim "<<tim<<endl;
        cout<<"Prs poeni: "<<prs_poeni<<endl;
        cout<<"Prs asist: "<<prs_asistencii<<endl;
        cout<<"Prs skokov: "<<prs_skokovi<<endl;
        cout<<"rating: "<<rating()<<endl;
    }
};
class ALLStarPlayer : public NBAplayer {
private:
    double prss_poeni;
    double prss_asistencii;
    double prss_skokovi;
public:
    ALLStarPlayer() {}
    ALLStarPlayer(char *name,char *tim,double prs_poeni,double prs_asistencii,double prs_skokovi,double prss_poeni,double prss_asistencii,double prss_skokovi):NBAplayer(name,tim,prs_poeni,prs_asistencii,prs_skokovi) {
        this->prss_poeni=prss_poeni;
        this->prss_asistencii=prss_asistencii;
        this->prss_skokovi=prss_skokovi;
    }
    ALLStarPlayer(NBAplayer &n,double prss_poeni,double prss_asistencii,double prss_skokovi): NBAplayer(n){
          this->prss_poeni=prss_poeni;
        this->prss_asistencii=prss_asistencii;
        this->prss_skokovi=prss_skokovi;
        }
    ALLStarPlayer(const ALLStarPlayer &n): NBAplayer(n) {
        this->prss_poeni=n.prss_poeni;
        this->prss_asistencii=n.prss_asistencii;
        this->prss_skokovi=n.prss_skokovi;
    }
    ~ALLStarPlayer() {
    }
    ALLStarPlayer& operator=(const ALLStarPlayer &n) {
        if(this!=&n) {
            delete[] this->name;
            copy(n);
            this->prss_poeni=n.prss_poeni;
            this->prss_asistencii=n.prss_asistencii;
            this->prss_skokovi=n.prss_skokovi;
        }
        return *this;
    }
    double allStarRating() {
        return (0.3*prss_poeni+0.4*prss_asistencii+0.3*prss_skokovi);
    }
    void print() {
        NBAplayer::print();
        cout<<"all star rating: "<<allStarRating()<<endl;
        cout<<"new rating: "<<rating()<<endl;
    }
};
int main()
{

    char name[50];
    char team[40];
    double points;
    double assists;
    double rebounds;
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;

    NBAplayer *players = new NBAplayer[5];
    ALLStarPlayer *asPlayers = new ALLStarPlayer[5];
    int n;
    cin >> n;

    if (n == 1)
    {

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cin >> name >> team >> points >> assists >> rebounds;
            players[i] = NBAplayer(name, team, points, assists, rebounds);
            players[i].print();
        }
    }
    else if (n == 2)
    {

        for (int i = 0; i < 5; ++i)
        {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAplayer(name, team, points, assists, rebounds);
            asPlayers[i] = ALLStarPlayer(players[i], allStarPoints, allStarAssists, allStarRebounds);
        }

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            players[i].print();

        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();

    }
    else if (n == 3)
    {

        for (int i = 0; i < 5; ++i)
        {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = ALLStarPlayer(name, team, points, assists, rebounds,
                                         allStarPoints, allStarAssists, allStarRebounds);
        }
        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();

    }

    delete[] players;
    delete[] asPlayers;
}