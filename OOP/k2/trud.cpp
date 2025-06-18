#include<iostream>
#include<cstring>
using namespace std;
class InvalidTrudException:public exception {
	public:
	InvalidTrudException(){}
	void mssg() {
		cout<<"Ne moze da se vnese dadeniot trud"<<endl;
	}
};
class Trud {
private:
	char vidNaTrud;
	int godinaNaIzdavanje;
public:
	Trud(){}
	Trud(char vidNaTrud, int godinaNaIzdavanje) {
		this->vidNaTrud = vidNaTrud;
		this->godinaNaIzdavanje = godinaNaIzdavanje;
	}
	char getVidNaTrud() {
		return vidNaTrud;
	}
	int getGodinaNaIzdavanje() {
		return godinaNaIzdavanje;
	}
	friend istream& operator>>(istream& is, Trud& trud) {
		is>>trud.vidNaTrud;
		is>>trud.godinaNaIzdavanje;
		return is;
	}
};
class Student {
protected:
	char name[30];
	int index;
	int godinaUpis;
	int *polozeni;
	int brPolozeni;
	public:
	Student(char *name,int index,int godinaUpis,int *polozeni,int brPolozeni) {
		strcpy(this->name,name);
		this->index=index;
		this->godinaUpis=godinaUpis;
		this->brPolozeni=brPolozeni;
		this->polozeni=new int[brPolozeni];
		for(int i=0;i<brPolozeni;i++) {
			this->polozeni[i]=polozeni[i];
		}
	}
	Student(const Student &student) {
		strcpy(this->name,student.name);
		this->index=student.index;
		this->godinaUpis=student.godinaUpis;
		this->brPolozeni=student.brPolozeni;
		this->polozeni=new int[brPolozeni];
		for(int i=0;i<brPolozeni;i++) {
			this->polozeni[i]=student.polozeni[i];
		}
	}
	Student& operator=(const Student &student) {
		if(this!=&student) {
			strcpy(this->name,student.name);
			this->index=student.index;
			this->godinaUpis=student.godinaUpis;
			this->brPolozeni=student.brPolozeni;
			delete []this->polozeni;
			this->polozeni=new int[brPolozeni];
			for(int i=0;i<brPolozeni;i++) {
				this->polozeni[i]=student.polozeni[i];
			}
		}
		return *this;
	}
	~Student() {
		delete []this->polozeni;
	}
	virtual float rang() {
		float r=0;
		for(int i=0;i<brPolozeni;i++) {
			r+=this->polozeni[i];
		}
		return r/brPolozeni;
	}
	friend ostream& operator<<(ostream &os,Student &s) {
		os<<s.index<<" "<<s.name<<" "<<s.godinaUpis<<" "<<s.rang()<<endl;
		return os;
	}
	int getIndex() {
		return this->index;
	}
};
class PhDStudent : public Student {
private:
	Trud *objaveni;
	int brTrudovi;
	public:
	PhDStudent(char *name,int index,int godinaUpis,int *polozeni,int brPolozeni,Trud *objaveni,int brTrudovi):
	Student(name,index,godinaUpis,polozeni,brPolozeni) {
		this->brTrudovi=brTrudovi;
		this->objaveni=new Trud[brTrudovi];
		for(int i=0;i<brTrudovi;i++) {
			this->objaveni[i]=objaveni[i];
		}
	}
	PhDStudent(const PhDStudent &student):Student(student) {
		this->brTrudovi=student.brTrudovi;
		this->objaveni=new Trud[student.brTrudovi];
		for(int i=0;i<brTrudovi;i++) {
			this->objaveni[i]=student.objaveni[i];
		}
	}
	PhDStudent& operator=(const PhDStudent &student){
		if(this!=&student) {
			strcpy(this->name,student.name);
			this->index=student.index;
			this->godinaUpis=student.godinaUpis;
			this->brPolozeni=student.brPolozeni;
			delete []this->polozeni;
			this->polozeni=new int[brPolozeni];
			for(int i=0;i<brPolozeni;i++) {
				this->polozeni[i]=student.polozeni[i];
			}
			this->brTrudovi=student.brTrudovi;
			delete [] this->objaveni;
			this->objaveni=new Trud[student.brTrudovi];
			for(int i=0;i<brTrudovi;i++) {
				this->objaveni[i]=student.objaveni[i];
			}
		}
		return *this;
	}
	~PhDStudent() {
		delete []this->objaveni;
	}
	float rang() override {
		float s=Student::rang();
		for(int i=0;i<brTrudovi;i++) {
			if(objaveni[i].getVidNaTrud()=='C') {
				s+=1;
			}else if(objaveni[i].getVidNaTrud()=='J') {
				s+=3;
			}
		}
		return s;
	}
	PhDStudent& operator+=( Trud &trud) {
		Trud *temp=new Trud[brTrudovi+1];
		for(int i=0;i<brTrudovi;i++) {
			temp[i]=objaveni[i];
		}
		if(trud.getGodinaNaIzdavanje()<godinaUpis) {
			throw InvalidTrudException();
		}
			temp[brTrudovi]=trud;
			delete []objaveni;
			objaveni=temp;
			brTrudovi++;
return *this;
	}
};
int main(){
	int testCase;
	cin >> testCase;

	int god, indeks, n, god_tr, m, n_tr;
	int izbor; //0 za Student, 1 za PhDStudent 
	char ime[30];
	int oceni[50];
	char tip;
	Trud trud[50];

	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		Student s(ime, indeks, god, oceni, n);
		cout << s;

		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++) {
			cout << *niza[i];

			// dodavanje nov trud za PhD student spored indeks
			Trud t;
			cin >> indeks;
			cin >> t;
			PhDStudent *phd=dynamic_cast<PhDStudent*>(niza[i]);
			// vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
			if(phd && niza[i]->getIndex()==indeks) {
				try {
					*phd+=t;
				}catch (InvalidTrudException &e) {
					e.mssg();
				}
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 3){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++) {
			cout << *niza[i];

			// dodavanje nov trud za PhD student spored indeks
			Trud t;
			cin >> indeks;
			cin >> t;
			PhDStudent *phd=dynamic_cast<PhDStudent*>(niza[i]);
			// vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
			if(phd && niza[i]->getIndex()==indeks) {
				try {
					*phd+=t;
				}catch (InvalidTrudException &e) {
					e.mssg();
				}
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 4){
		cout << "===== Testiranje na isklucoci ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 5){
		cout << "===== Testiranje na isklucoci ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++) {
			cout << *niza[i];
			Trud t;
			cin >> indeks;
			cin >> t;
			// dodavanje nov trud za PhD student spored indeks
			PhDStudent *phd=dynamic_cast<PhDStudent*>(niza[i]);
			if(phd && niza[i]->getIndex()==indeks) {
				try {
					*phd+=t;
				}catch (InvalidTrudException &e) {
					e.mssg();
				}
			}
		}
		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot

		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 6){
		cout << "===== Testiranje na static clenovi ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		int conf, journal;
		cin >> conf;
		cin >> journal;
		
        //postavete gi soodvetnite vrednosti za statickite promenlivi 
        
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}

	return 0;
}