#include<iostream>
#include<cstring>
using namespace std;

class SMS {
protected:
	float osnovnacena;
	char broj[12];
public:
	SMS(char *broj,float osnovnacena) {
		for(int i=0;i<12;i++) {
			this->broj[i]=broj[i];
		}
		this->osnovnacena=osnovnacena;
	}
	virtual float SMS_cena()=0;
	friend ostream &operator<<(ostream &out, const SMS &s) {
		out << "Tel.broj: " << s.broj << " - cena: " << s.osnovnacena << endl;
		return out;
	}
};
class RegularSMS : public SMS {
private:
	bool roaming;
	char *msg;
	public:
	RegularSMS(char *broj,float osnovnacena,char *msg,bool roaming):SMS(broj,osnovnacena) {
		this->roaming=roaming;
		strcpy(this->msg,msg);
	}
	RegularSMS(const RegularSMS &other):SMS(other) {
		this->roaming=other.roaming;
		this->msg=new char[strlen(other.msg)+1];
		strcpy(this->msg,other.msg);
	}
	RegularSMS &operator=(const RegularSMS &other) {
		if(this!=&other) {
			delete [] this->msg;
			this->roaming=other.roaming;
			this->msg=new char[strlen(other.msg)+1];
			strcpy(this->msg,other.msg);
		}
		return *this;
	}
	~RegularSMS() {
		delete [] this->msg;
	}
	float SMS_cena() override{
		if(roaming) {
			osnovnacena+=osnovnacena*300.0;
		}else {
			osnovnacena+=osnovnacena*0.18;;
		}
		if(strlen(this->msg)>160) {
			osnovnacena+=osnovnacena*2;
		}
		return osnovnacena;
	}
};
class SpecialSMS : public SMS {
private:
	bool hum;
public:
	SpecialSMS(char *broj,float osnovnacena,bool hum):SMS(broj,osnovnacena) {
		this->hum=hum;
	}
};
void vkupno_SMS(SMS **poraka,int n) {
	int regular=0;
	int special=0;
	float sr=0,ss=0;
	for(int i=0;i<n;i++) {
		if(dynamic_cast<RegularSMS *>(poraka[i])) {
			regular++;
			sr+=poraka[i]->SMS_cena();
		}else if(dynamic_cast<SpecialSMS *>(poraka[i])) {
			special++;
			ss+=poraka[i]->SMS_cena();
		}
	}
    cout<<"regular: "<<regular<<" "<<sr<<endl;
	cout<<"special: "<<special<<" "<<ss<<endl;
}
int main(){
	char tel[20], msg[1000];
	float cena;
	float price;
    int p;
	bool roam, hum;
	SMS  **sms;
	int n;
	int tip;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing RegularSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new RegularSMS(tel, cena, msg, roam);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 2){
		cout << "====== Testing SpecialSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
			cin >> hum;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new SpecialSMS(tel, cena, hum);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 3){
		cout << "====== Testing method vkupno_SMS() ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i<n; i++){

			cin >> tip;
			cin >> tel;
			cin >> cena;
			if (tip == 1) {

				cin.get();
				cin.getline(msg, 1000);
                cin >> roam;

				sms[i] = new RegularSMS(tel, cena, msg, roam);

			}
			else {
				cin >> hum;

				sms[i] = new SpecialSMS(tel, cena, hum);
			}
		}

		vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
    if (testCase == 4){
		cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        	cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			sms1 = new RegularSMS(tel, cena, msg, roam);
			cout << *sms1;

            cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
        	cin >> p;
        	RegularSMS::set_rProcent(p);
        	sms2 = new RegularSMS(tel, cena, msg, roam);
        	cout << *sms2;

        delete sms1, sms2;
	}
    if (testCase == 5){
		cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        	cin >> tel;
			cin >> cena;
			cin >> hum;
			sms1 = new SpecialSMS(tel, cena, hum);
			cout << *sms1;

            cin >> tel;
			cin >> cena;
			cin >> hum;
        	cin >> p;
        	SpecialSMS::set_sProcent(p);
        	sms2 = new SpecialSMS(tel, cena, hum);
        	cout << *sms2;

        delete sms1, sms2;
	}

	return 0;
}
