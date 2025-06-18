#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
class TennisPlayer {
protected:
  char *name;
  char *surname;
  bool playing;
  void copy(const TennisPlayer &p) {
    this->name=new char[strlen(p.name)+1];
    strcpy(this->name,p.name);
    this->surname=new char[strlen(p.surname)+1];
    strcpy(this->surname,p.surname);
    this->playing=p.playing;
  }
public:
  TennisPlayer(char *name="",char *surname="",bool playing=false) {
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    this->surname=new char[strlen(surname)+1];
    strcpy(this->surname,surname);
    this->playing=playing;
  }
  TennisPlayer(const TennisPlayer &p) {
   copy(p);
  }
  TennisPlayer& operator=(const TennisPlayer &p) {
    if(this!=&p) {
      delete[] this->name;
      delete[] this->surname;
      copy(p);
    }
    return *this;
  }
  friend ostream& operator<<(ostream &os,TennisPlayer &p) {
    os<<p.name<<" "<<p.surname;
    if(p.playing) {
      cout<<" playing "<<endl;
    }else {
      cout<<"no "<<endl;
    }
    return os;
  }
  ~TennisPlayer() {
    delete [] name;
    delete [] surname;
  }
};
class RankedTennisPlayer : public TennisPlayer {
private:
  int rank;
  public:
  RankedTennisPlayer(char *name="",char *surname="",int rank=0):TennisPlayer(name,surname,false) {
    this->rank=rank;
  }
  RankedTennisPlayer(TennisPlayer tp,int rank=3) {
    TennisPlayer :: copy(tp);
    this->rank=rank;
  }
  RankedTennisPlayer(const RankedTennisPlayer &p):TennisPlayer(p) {
    this->rank=p.rank;
  }
  RankedTennisPlayer& operator=(const RankedTennisPlayer &p) {
    if(this!=&p) {
      TennisPlayer :: operator=(p);
      this->rank=p.rank;
    }
    return *this;
  }
  friend ostream& operator<<(ostream &os,RankedTennisPlayer &p) {
    TennisPlayer tp(p);
    os<<tp;
    os<<" "<<p.rank;
    return os;
  }
};
int main() {
  TennisPlayer tennisPlayer1("Rafael", "Nadal", true);
  cout << tennisPlayer1 << endl;
  RankedTennisPlayer tennisPlayer2(tennisPlayer1,2);
  cout << tennisPlayer2 << endl;
}