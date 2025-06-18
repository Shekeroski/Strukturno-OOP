#include <iostream>
using namespace std;

int main() {
     int studenti;
    float poeni,max_poeni;
    cin>>studenti;
    for(int i=1;i<=studenti;i++) {
        cin>>poeni>>max_poeni;
        float procent;
        procent=(poeni/max_poeni)*100;
        cout<<procent<<endl;
        if(procent<50) {
            cout<<"nepolozi"<<endl;
        }
         if(procent>=50 && procent<60) {
            cout<<"6"<<endl;
        }
        if(procent>=60 && procent<70) {
            cout<<"7"<<endl;
        }
         if(procent>=70 && procent<80) {
            cout<<"8"<<endl;
        }
         if(procent>=80 && procent<90) {
            cout<<"9"<<endl;
        }
         if(procent>=90 && procent<=100) {
            cout<<"10"<<endl;
        }
    }
    return 0;
}