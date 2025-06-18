#include<iostream>
#include<cstring>
using namespace std;

class Email {
    private:
   char to[20];
    char from[20];
    char subject[20];
    public:
    Email(char *too, char *fromm, char *subjectt) {
        strcpy(this->to, too);
        strcpy(this->from, fromm);
        strcpy(this->subject, subjectt);
    }
    ~Email() {}
    void setTo(char *too) {
        strcpy(this->to, too);
    }
    void setFrom(char *fromm) {
        strcpy(this->from, fromm);
    }
    void setSubject(char *subject) {
        strcpy(this->subject, subject);
    }
    char *getTo() {
        return to;
    }
    char *getFrom() {
        return from;
    }
    char *getSubject() {
        return subject;
    }
    void print() {
        cout << to << " " <<endl;
        cout<<from << " " <<endl;
        cout<<subject << endl;
    }
};

bool checkEmail(char *niza) {
    int j=0;
    for(int i = 0; i < strlen(niza); i++) {
        if(niza[i] == '@') {
            j = i;
        }
    }
    if(j!=0)
    {    for(int k=j; k < strlen(niza); k++) {
        if(niza[k] == '.') {
            return true;
        }
    }
    }
}

int main() {
   char to[20];
    char from[20];
    char subject[20];
    cin>>to;
    if(checkEmail(to)) {
        cin>>from;
        cin>>subject;
        Email poraka(to,from,subject);
        poraka.print();
    }
    else {
        cout<<"Not a valid Email";
    }
    return 0;
}