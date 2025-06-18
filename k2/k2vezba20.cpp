#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }

    int r1,r2,k1,k2;
    cin>>r1>>k1>>r2>>k2;
    for(int i=r1;i<=r2;i++) {
        int flag=1;
        for(int j=k1;j<=k2;j++) {

            if(j==k2) {
                for(int w=0;w<=1;w++) {
                    int r=k2;
                    for(int e=0;e<=1;e++) {
                        int b=i+w;
                        int b1=r;
                        r--;
                        flag=0;
                    }
                }
            }
            if(flag) {
                for(int k=0;k<=1;k++) {
                    for(int l=0;l<=1;l++) {
                        int a1=0,a2=0;
                        a1+=i+k;
                        a2+=j+l;
                        int sum=0;
                        sum+=a[a1][a2];
                    }
                }
            }
            if(flag) {
                if(j>k1) {
                    for(int q=0;q==0;q++) {
                        for(int p=0;p<=1;p++) {
                            int z=p+i;
                            int z2=q+(j-1);
                            int sum1=0;
                            sum1+=a[z][z2];
                        }
                    }
                }
            }
            if(flag) {
                if(i>r1) {
                    for(int q=0;q==0;q++) {
                        for(int p=0;p<=2;p++) {
                            int c1=q+(i-1);
                            int c2=p+j;
                        }
                    }
                }
            }
        }
    }

    return 0;
}