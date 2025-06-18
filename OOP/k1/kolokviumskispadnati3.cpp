#include<iostream>
#include<cstring>
using namespace std;
enum zanr {
    pop,rock,jazz
};
class Song {
    char naslov[10];
    char izveduvac[10];
    zanr z;
    int vreme;
    int _id;
    static int id;
public:
    Song() {}
    Song(const char* naslov, const char* izveduvac,zanr z,int vreme,int _id) {
        strcpy(this->naslov,naslov);
        strcpy(this->izveduvac,izveduvac);
        this->vreme=vreme;
        this->z=z;
        this->_id=id;
        id++;
    }
    Song(const Song &s) {
        strcpy(this->naslov,s.naslov);
        strcpy(this->izveduvac,s.izveduvac);
        this->vreme=s.vreme;
        this->z=s.z;
        this->_id=s._id;
    }
    int getVreme() {
        return this->vreme;
    }
    zanr getZanr() {
        return this->z;
    }
};
class Playlist {
    char ime[20];
    Song songs[10];
    int br_songs;
public:
    Playlist() {}
    Playlist(const Playlist &p) {
        strcpy(ime,p.ime);
        br_songs=p.br_songs;
        for(int i=0;i<br_songs;i++) {
            songs[i]=p.songs[i];
        }
    }
    Playlist(const char *ime,int br_songs,Song songs[]) {
        strcpy(this->ime,ime);
        this->br_songs=br_songs;
        for(int i=0;i<br_songs;i++) {
            this->songs[i]=songs[i];
        }
    }
    void addSong(const Song &s) {
        if(br_songs<100) {
            songs[br_songs]=s;
            br_songs++;
        }
    }
   int totalDuration() {
        int s=0;
        for(int i=0;i<br_songs;i++) {
            s+=songs[i].getVreme();
        }
        return s;
    }
    void increaseTime(int seconds) {
        for(int i=0;i<br_songs;i++) {
            if(songs[i].getZanr()==pop) {
                songs[i].getVreme()+seconds;
            }
        }
    }
};
int Song::id=1000;
int main() {
int n;
    cin>>n;
    Playlist p;
    Song songs[10];
    char naslov[10];
    char izveduvac[10];
    int vreme;
    int zanr;
    int _id;
    int br_songs;
    for(int i=0;i<n;i++) {
        cin>>naslov>>izveduvac>>zanr>>vreme;
    }
    Song song1(naslov,izveduvac,rock,vreme,_id);
    p.addSong(song1);
    p.increaseTime(10);
    p.totalDuration();
}