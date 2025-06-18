#include<iostream>
#include<cstring>
using namespace std;
enum tip {
    employer,worker,scientist
};
class Robot {
    char ime[10];
    int battery;
    tip cat;
public:
    Robot() {}
    Robot(char *ime,int battery, tip cat) {
        strcpy(this->ime,ime);
        this->battery = battery;
        this->cat = cat;
    }
    Robot(const Robot &robot) {
        strcpy(this->ime,robot.ime);
        this->battery = robot.battery;
        this->cat = robot.cat;
    }
    int addbatery(int increase) {
        int sum = 0;
        sum+=battery+increase;
        if(sum>100) {
            battery=100;
        }else {
            battery+=increase;
        }
    }
    void print() {
        cout<<ime<<" "<<battery<<endl;
        if(cat==scientist) {
            cout<<"scientist"<<endl;
        }
        else if(cat==employer) {
            cout<<"employer"<<endl;
        }
        else if(cat==worker) {
            cout<<"worker"<<endl;
        }
    }
    char *getime() {
        return ime;
    }
    tip getcat() {
        return cat;
    }
};
class Colony {
    char ime[10];
    Robot robots[10];
    int br_roboti;
public:
    Colony() {}
    Colony(char *ime,Robot robots[],int br_roboti) {
        strcpy(this->ime,ime);
        this->br_roboti = br_roboti;
        for(int i=0;i<br_roboti;i++) {
            this->robots[i] = robots[i];
        }
    }
    void addrobot(Robot &r) {
        for(int i=0;i<br_roboti;i++) {
            if(strcmp(robots[i].getime(),r.getime())==0 && robots[i].getcat()==r.getcat()) {
                cout<<"ovoj robot nemoze da se dodade"<<endl;
            }else {
                robots[br_roboti++] = r;
            }
        }
    }
    int getbr_roboti() {
        return br_roboti;
    }
    Robot getrobot(int i) {
        return robots[i];
    }
};
 void addbateryforOtherCategory(Colony *c,int n,tip t,int amount) {
     for(int i=0;i<n;i++) {
         for(int j=0;j<c[i].getbr_roboti();j++) {
             if(c[i].getrobot(j).getcat()!=t) {
                 c[i].getrobot(j).addbatery(amount);
             }
         }
     }
 }
int main() {

}