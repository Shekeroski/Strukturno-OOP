#include<iostream>
using namespace std;

class basketballplayer {
private:
 char name[10];
 char surname[10];
 int brdres;
 float p1;
 float p2;
 float p3;
    float avg;
public:
   basketballplayer(char *n,char *s, int broj,float p11,float p22, float p33, float avgg) {
       strcpy(name,n);
       strcpy(surname,s);
       brdres=broj;
       p1=p11;
       p2=p22;
       p3=p33;
       avg=avgg;
   }

    void setAVG(float avgg) {
       avg==avgg;
   }
 void setName(char *n) {
       strcpy(name,n);
   }
    void setSurname(char *s) {
       strcpy(surname,s);
   }
    void setBrdres(int broj) {
       brdres=broj;
   }
    void setP1(float p11) {
       p1=p11;
   }
    void setP2(float p22) {
       p2=p22;
   }
    void setP3(float p33) {
       p3=p33;
   }
    char * getName() {
       return name;
   }
    char * getSurname() {
       return surname;
   }
    int getBrdres() {
       return brdres;
   }
    float  getP1() {
       return p1;
   }
    float getP2() {
       return p2;
   }
    float getP3() {
       return p3;
   }


    void display() {
       cout<<"Name: "<<name<<endl;
       cout<<"Surname: "<<surname<<endl;
       cout<<"Brdres: "<<brdres<<endl;
       cout<<"avg: "<<avg<<endl;
   }
};

int main() {
    char name[10];
    char surname[10];
    int brdres;
    float p1;
    float p2;
    float p3;
    float avg;
    cin>>name;
    cin>>surname;
    cin>>brdres;
    cin>>p1;
    cin>>p2;
    cin>>p3;
    avg=(p1+p2+p3)/3;
    basketballplayer player(name,surname,brdres,p1,p2,p3,avg);
    player.display();
    return 0;

}