#include<iostream>
#include<string>
using namespace std;
class User {
protected:
    string name;
    string email;
    string password;
    public:
    User(string name, string email, string password) {
        this->name = name;
        this->email = email;
        this->password = password;
    }
    virtual void print()=0;
    virtual  int calculatePasswordStrength()=0;
};
class regularUser : public User {
    private:
    bool FA;
    public:
    regularUser(string name, string email, string password,bool FA):User(name,email,password) {
        this->FA = FA;
    }
    int calculatePasswordStrength() override {
        int counter=0;
        for(int i=0;i==0;i++) {
            if(isalpha(password[i])) {
                counter++;
            }
        }
        if(password.length() > 8) {
            counter++;
        }
        if(FA) {
            counter++;
        }
        for(int i=0;i==0;i++) {
            if(isdigit(password[i])) {
                counter++;
                break;
            }
        }
        return counter;
    }
    void print() override {
        cout<<name<<" "<<email<<" "<<password<<endl;
    }
};
class adminUser : public User {
private:
    string level;
    bool multiFactorAuth;
    public:
    adminUser(string name, string email, string password,string level,bool FA):User(name,email,password) {
        this->level = level;
        this->multiFactorAuth = FA;
    }
    int calculatePasswordStrength() override {
        int counter=0;
        if(password.length() > 10) {
            counter+=1;
        }
        int c=password.length();
        for(int i=c;i>=c;i--) {
            if(isalpha(password[i])) {
                counter++;
            }
        }
        if(multiFactorAuth) {
            counter+=1;
        }
        if(level=="superuser" || level=="admin") {
            counter+=1;
        }
        return counter;
    }
    void print() override {
        cout<<name<<" "<<email<<" "<<password<<endl;
    }
};
void printAverage( User **user,int n) {
    int s=0;
    for(int i=0;i<n;i++) {
        if(dynamic_cast<regularUser*>(user[i])) {
            user[i]->print();
            s+=user[i]->calculatePasswordStrength();
        }
    }
    float avg;
    avg=s/n;
    cout<<avg<<endl;
}
int main () {
    regularUser *ru1 = new regularUser("Alice", "alice@example.com", "Apass123", true);
    regularUser *ru2 = new regularUser("Bob", "bob@example.com", "b123", false);
    regularUser *ru3 = new regularUser("Charlie", "charlie@example.com", "Charlie789", true);

    adminUser *au1 = new adminUser("Diana", "diana@admin.com", "adminpass123", "admin", true);
    adminUser *au2 = new adminUser("Edward", "edward@admin.com", "Epass", "user", false);
    adminUser *au3 = new adminUser("Frank", "frank@admin.com", "f123super", "superuser", true);

    User *users[6];
    users[0] = ru1;
    users[1] = ru2;
    users[2] = ru3;
    users[3] = au1;
    users[4] = au2;
    users[5] = au3;

    cout << "Printing all users:"<<endl;
    for (int i = 0; i < 6; i++) {
        users[i]->print();
    }

    cout << endl;
    printAverage(users, 6);

    for (int i = 0; i < 6; i++) {
        delete users[i];
    }
    return 0;
}