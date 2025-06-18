#include <iostream>
#include <cstring>
using namespace std;
class InvalidProductionDate : public exception {
	public:
	void mssg() {
		cout<<"Невалидна година на производство"<<endl;
	}
};
enum tip {
	smartfon,kompjuter
};
class Device {
private:
	char model[20];
	tip t;
	static float potrebniCasovi;
	int godina;
public:
	Device() {
	}
	Device(char *model,tip t,int godina) {
		strcpy(this->model,model);
		this->t = t;
		this->godina = godina;
	}
	static void setPocetniCasovi(float casovi) {
		potrebniCasovi=casovi;
	}
	friend ostream &operator<<(ostream &os, const Device &device) {
		os<<device.model<<endl;
		if(device.t==kompjuter) {
			os<<"Laptop "<<device.getPotrebniCasovi()<<endl;
		}else if(device.t==smartfon) {
			os<<"Mobilen "<<device.getPotrebniCasovi()<<endl;
		}
		return os;
	}
	int getGodina() const{
		return godina;
	}
	char *getModel()  {
		return model;
	}
	float getPotrebniCasovi() const {
		float vkupno=potrebniCasovi;
		if(godina>2015) {
			vkupno+=2;
		} if(t==kompjuter) {
			vkupno+=2;
		}
		return vkupno;
	}

};
class MobileServis {
private:
	char adresa[100];
	Device *devices;
	int brojUredi;
public:
	MobileServis() {
		this->brojUredi=0;
		strcpy(this->adresa,"");
		this->devices=nullptr;
	}
	MobileServis(char *adresa) {
		strcpy(this->adresa,adresa);
		this->brojUredi=0;
		this->devices=nullptr;
	}
	MobileServis(char *adresa,Device *device,int brojUredi) {
		strcpy(this->adresa,adresa);
		this->brojUredi=brojUredi;
		this->devices=new Device[brojUredi];
		for(int i=0;i<brojUredi;i++) {
			this->devices[i]=device[i];
		}
	}
	MobileServis(const MobileServis &m) {
		strcpy(this->adresa,m.adresa);
		this->brojUredi=m.brojUredi;
		this->devices=new Device[brojUredi];
		for(int i=0;i<brojUredi;i++) {
			this->devices[i]=m.devices[i];
		}
	}
	MobileServis &operator=(const MobileServis &m) {
		if(this!=&m) {
			strcpy(this->adresa,m.adresa);
			this->brojUredi=m.brojUredi;
			delete [] this->devices;
			this->devices=new Device[brojUredi];
			for(int i=0;i<brojUredi;i++) {
				this->devices[i]=m.devices[i];
			}
		}
		return *this;
	}
	~MobileServis() {
		delete [] this->devices;
	}
	MobileServis& operator+=(const Device &device) {
		if(device.getGodina()<2000 || device.getGodina()>2019) {
			throw InvalidProductionDate();
		}
		Device *temp=new Device[brojUredi+1];
		for(int i=0;i<brojUredi;i++) {
			temp[i]=devices[i];
		}
		temp[brojUredi]=device;
		delete [] this->devices;
		this->devices=temp;
		brojUredi++;
		return *this;
	}
	void pecatiCasovi() {
		cout<<"Ime: "<<adresa<<endl;
		for(int i=0;i<brojUredi;i++) {
			cout<<devices[i];
		}
	}
	void pecatiuredi() {
		cout<<"CASOVITE"<<endl;
	}
};
float Device::potrebniCasovi=1;
int main()
{
	int testCase;
	cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
		MobileServis t(ime);
        cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
			try {
				Device tmp(ime,(tip)tipDevice,godina);
				t+=tmp;
			}catch (InvalidProductionDate &e) {
				e.mssg();
			}
        }
        t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
			try {
				Device tmp(ime,(tip)tipDevice,godina);
				t+=tmp;
			}catch (InvalidProductionDate &e) {
				e.mssg();
			}
        }
        t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
		 cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
			try {
				Device tmp(ime,(tip)tipDevice,godina);
				t+=tmp;
			}catch (InvalidProductionDate &e) {
				e.mssg();
			}
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
			try {
				Device tmp(ime,(tip)tipDevice,godina);

				t+=tmp;
			}catch (InvalidProductionDate &e) {
				e.mssg();
			}
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
        t.pecatiCasovi();
	}

		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
			try {
				Device tmp(ime,(tip)tipDevice,godina);
				t+=tmp;
			}catch (InvalidProductionDate &e) {
				e.mssg();
			}
        }
		Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}

	return 0;

}

