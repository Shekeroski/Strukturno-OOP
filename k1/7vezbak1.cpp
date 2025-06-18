#include <iostream>
using namespace std;
int main()
{
    int m;
    cin>>m;
    if(m>2){
        for (int i = 0; i <m; ++i) {
            for (int j = 0; j < m; ++j) {
                if(j==0 || j==m-1)cout<<'%';
                else if((i==0 || i==m-1)&&(j>0 && j<m-1))cout<<'@';
                else cout<<'.';
            }
            cout<<endl;
        }
    }
    else
        cout<<"FINKI nema zgrada";
    return 0;
}