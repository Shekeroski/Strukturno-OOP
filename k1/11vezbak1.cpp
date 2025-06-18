#include<iostream>
using namespace std;
int main() {
    int br1,br2;
    int brojaczasitebroevi=0;
    cin>>br1>>br2;
    for(int i=br1+1;i<br2;i++) {
        int zaposlednono;
            int temp=i;
        bool flag=true;
        bool flagmnoz=true;
            int k;
            int firstandlast;
            int tempbrojcopy=i;
            int a=i;
            int b;
            int c;
            int brnaposlednoto=1;
            int mnozenje=1;
            int sobirac=0;
            int lastdigit;
            int firstdigit=i;
            int brnacifri=0;
            while (temp>0) {
                temp/=10;
                brnacifri++;
            }
            lastdigit=tempbrojcopy%10;
            while(firstdigit>10) {
                firstdigit/=10;
            }
           firstandlast=firstdigit*10+lastdigit;
            k=a/10;
            while(k>10) {
                b=k%10;
                if(b==0) {
                    flagmnoz=false;
                }
                sobirac=sobirac*10+b;
                k/=10;
            }
            while(sobirac>0) {
                c=sobirac%10;
                mnozenje=mnozenje*c;
                sobirac/=10;
            }
             if(mnozenje==0) {
                 flag=false;
             }
             if(mnozenje%firstandlast!=0) {
                 flag=false;
             }
             if(flag) {
                 if(flagmnoz) {
                     cout<<i<<" -> "<<"("<<mnozenje<<" == "<<firstandlast<<" * "<<mnozenje/firstandlast<<")"<<endl;
                     brojaczasitebroevi++;
                 }
             }
    }
    cout<<brojaczasitebroevi<<endl;
    return 0;
}