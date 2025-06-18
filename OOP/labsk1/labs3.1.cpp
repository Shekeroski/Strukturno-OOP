#include<iostream>
#include<cstring>
using namespace std;
int MAX=50;
class List {
    int br;
    int a[50];
public:
    List(){}
    List(int _br,int _a[]) {
        br=_br;
        for(int i=0;i<br;i++) {
            a[i]=_a[i];
        }
    }
    List(const List &l) {
        br=l.br;
        for(int i=0;i<br;i++) {
            a[i]=l.a[i];
        }
    }
    ~List() {}
    int sum() {
        int s=0;
        for(int i=0;i<br;i++) {
            s += a[i];
        }
        return s;
    }
    double average() {
        return (sum()/br);
    }
    void pecati() {
        cout<<"["<<br>>"]"<<": ";
        for(int i=0;i<br;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<"sum: "<<sum()<<endl;
            cout<<endl;
        cout<<"avg"<<average()<<endl;
    }
};
class ListContainer {
    List *l;
    int n;
    int obidi;
public:
    ListContainer() {
        l = new List[MAX];
        n=0;
        obidi=0;
    }
    ListContainer(List *_l,int _n,int _obidi) {
        l=new List[MAX];
        for(int i=0;i<n;i++) {
            l[i]=_l[i];
        }
        n=_n;
        obidi=_obidi;
    }
    ListContainer(const ListContainer &li) {
        n=li.n;
        obidi=li.obidi;
        li.l;
    }
    ~ListContainer() {}
    void pecati() {
        for(int i=0;i<n;i++) {
            cout<<"List number: "<<i<<"List info: ";
            l[i].pecati();
        }
        cout<<"succesful attempts: "<<n<<" failed atempts :"<<obidi<<endl;
    }
    void addNewList(List li) {
        obidi++;
        for(int i=0;i<n;i++) {
            if(l[i].sum()==li.sum()) {
                return;
            }
        }
        l[n]=li;
        n++;
    }
};
int main()
{

    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> niza[j];

        }

        List l = List(niza, n);

        lc.addNewList(l);
    }


    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();

    }
    else
    {
        lc.print();
    }
}