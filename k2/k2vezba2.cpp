#include<iostream>
using namespace std;
int main() {
    int n;
    float N;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cin>>N;
    for(int i=0;i<n-N;i++) {
        float s=0;
        for(int j=i;j<i+N;j++) {
            s+=a[j];
        }
        cout<<s/N<<endl;
    }
}