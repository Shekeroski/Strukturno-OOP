#include<iostream>
#include<cstring>
using namespace std;

class Gitara {
	char seriskibroj[25];
	float nabavnacena;
	int godina;
	char tip[20];
public:
	Gitara();
	Gitara(char *t,char *s,int g,float c) {
		strcpy(seriskibroj,s);
		strcpy(tip,t);
		nabavnacena=c;
		godina=g;
	}
	char *getSeriski() {
		return seriskibroj;
	}
	float getNabavna() {
		return nabavnacena;
	}
	int getGodina() {
		return godina;
	}
	char *getTip() {
		return tip;
	}
	~Gitara() {}
	bool daliisti(const Gitara &other) {
		if(strcmp(tip,other.tip)) {
			return true;
		}
		return false;
	}
	void pecati() {
		cout<<seriskibroj<<" "<<tip<<" "<<nabavnacena<<endl;;
	}
};
class Magacin {
	string name;
	string location;
	Gitara *gitara;
	int brobjekti;
	int godinanaotvoranje;
public:
	Magacin(string n,string l,int g=0) {
		this->name=n;
		this->location=l;
		godinanaotvoranje=g;
		gitara=0;
		brobjekti=0;
	}
	Magacin() {}
	double vrednost() {
		float s=0;
		for(int i=0;i<brobjekti;i++) {
			s+=gitara[i].getNabavna();
		}
		return s;
	}
	~Magacin() {}
	void dodadi(Gitara d) {
		gitara[brobjekti++]=d;
	}
	void prodadi(Gitara p) {
		int novbroj=0;
		for(int i=0;i<brobjekti;i++) {
			if(gitara[i].daliisti(p)==false) {
				novbroj++;
			}
		}
		int j=0;
		Gitara * tmp = new Gitara[novbroj];
		for (int i=0;i<brobjekti;i++) {
			if(gitara[i].daliisti(p)==false) {
				tmp[j]=gitara[i];
				j++;
			}
		}
		delete [] gitara;
		brobjekti=novbroj;
		gitara=tmp;
	}
	void pecati(bool daliNovi) {
		cout<<name<<" "<<location<<endl;
		for(int i=0;i<brobjekti;i++) {
			if(daliNovi==true && gitara[i].getGodina()>godinanaotvoranje) {
				gitara[i].pecati();
			}else {
				gitara[i].pecati();
			}
		}
	}
};
   int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, godina;
	float cena;
	char seriski[50],tip[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin>>tip;
        cin>>seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip,seriski, godina,cena);
		cout<<g.getTip()<<endl;
		cout<<g.getSeriski()<<endl;
		cout<<g.getGodina()<<endl;
		cout<<g.getNabavna()<<endl;
    } else if(testCase == 2){
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
		Magacin kb("Magacin1","Lokacija1");
        kb.pecati(false);
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2005);
		cin>>n;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;
                Gitara g(tip,seriski, godina,cena);
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
    }

    else if(testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2012);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
                cout<<"gitara dodadi"<<endl;
				kb.dodadi(g);
			}
        kb.pecati(true);
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        Magacin kb3;
        kb3=kb;
        kb3.pecati(true);
    }
   else if(testCase ==6)
        {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
            cin>>n;
            Gitara brisi;
			for (int i=0;i<n;i++){
                cin>>tip;
                cin>>seriski;
                cin >> godina;
                cin >> cena;

                Gitara g(tip,seriski, godina,cena);
                if(i==2)
                    brisi=g;
				kb.dodadi(g);
			}
        cout<<kb.vrednost()<<endl;
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        cout<<kb.vrednost();
        Magacin kb3;
        kb3=kb;
        }
    return 0;
}
