#include<iostream>
#include<cstring>
using namespace std;

class List {
private:
    int *nizabroevi;
    int brnabroevi;
public:
    List(int *n,int _brnabroevi) {
        brnabroevi=_brnabroevi;
        for(int i=0;i<brnabroevi;i++) {
            nizabroevi[i]=n[i];
        }
    }
    List( const List &l) {
        brnabroevi=l.brnabroevi;
        nizabroevi=l.nizabroevi;
    }
    ~List() {
    }
    void pecati() {
        cout<<"["<<brnabroevi<<"]"<<": ";
        for(int i=0;i<brnabroevi;i++) {
            cout<<nizabroevi[i]<<" ";
        }
        cout<<"sum:"<<sum()<<" average:"<<average()<<endl;
    }
    int sum() {
        int s=0;
        for(int i=0;i<brnabroevi;i++) {
            s+=nizabroevi[i];
        }
        return s;
    }
    double average() {
        return (double)sum()/brnabroevi;
    }
};
class ListContainer {
    private:
    List *list;
    int brelem;
    int brobidizadodavanje=0;
public:
    ListContainer() {
    }
    listContainer(const ListContainer &l) {
        brelem=l.brelem;
        brobidizadodavanje=l.brobidizadodavanje;
        list=new list(brelem);
        for(int i=0;i<brelem;i++) {
            list[i]=l.list[i];
        }
    }
    ~ListContainer() {}

    void addNewList(List l) {
       for(int i=0;i<brelem;i++) {
           if(list[i].sum()==l.sum()) {
               return;
           }
       }
        List *temp=new List[brelem++];
        for(int i=0;i<brelem;i++) {
            temp[i]=list[i];
        }
        temp[brelem]=l;
        list=temp;
        brelem++;
    }
};

int main() {

    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0;i<N;i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0;j<n;j++){
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }
}