#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Igrachka {
public:
    Igrachka() {}
    virtual float getMasa()=0;
    virtual float getVolumen()=0;
    virtual float getPlostina()=0;
};
class Forma {
protected:
    int gustina;
    char boja[10];
public:
    Forma(char *boja="",int gustina=0) {
        strcpy(boja,boja);
        this->gustina=gustina;
    }
};
class Kocka : public Igrachka,public Forma {
private:
    int visina,sirina,dlabocina;
    public:
    Kocka(int visina=0,int sirina=0,int dlabocina=0,char *boja="",int gustina=0):Forma(boja,gustina) {
        this->visina=visina;
        this->sirina=sirina;
        this->dlabocina=dlabocina;
    }
    float getMasa() {
        return getVolumen()*gustina;
    }
    float getVolumen() {
        return (float)sirina*(float)visina*(float)dlabocina;
    }
    float getPlostina() {
        return 2*visina *sirina+2*visina*dlabocina+2*sirina*dlabocina;
    }
};
class Topka : public Igrachka, public Forma {
    private:
  int radius;
public:
    Topka(int radius,char *boja="",int gustina=0):Forma(boja,gustina) {
        this->radius=radius;
    }
    float getMasa() {
        return getVolumen()*radius;
    }
    float getVolumen() {
        return(4.0/3.0)*3.14*radius*radius*radius;
    }
    float getPlostina() {
        return 4.0*3.14*radius*radius;
    }
};
int main()
{
    int n;
    int t;
    char boja[30];
    int gustina;
    int radius;
    int height;
    int width;
    int depth;

    cin >> n;

    Igrachka **kupche = new Igrachka *[n];

    for (int i = 0; i < n; i++)
    {
        cin >> t;

        if (t == 1)
        {
            cin >> boja >> gustina >> radius;

            kupche[i] = new Topka(radius, boja, gustina);
        }
        else
        {
            cin >> boja >> gustina >> height >> width >> depth;

            kupche[i] = new Kocka(height, width, depth, boja, gustina);
        }
    }

    cin >> boja >> gustina >> height >> width >> depth;

    Kocka petra(height, width, depth, boja, gustina);

    float mass = 0;
    float max = kupche[0]->getVolumen();
    float min = kupche[0]->getVolumen();

    for (int i = 0; i < n; i++)
    {
        mass += kupche[i]->getMasa();

        if (max < kupche[i]->getVolumen())
            max = kupche[i]->getVolumen();

        if (min > kupche[i]->getPlostina())
            min = kupche[i]->getPlostina();
    }

    if (petra.getMasa() < mass)
        cout << "DA" << endl;
    else
        cout << "NE" << endl;

    cout << "Razlikata e: " << abs(max - petra.getVolumen()) << endl;

    cout << "Razlikata e: " << abs(min - petra.getPlostina()) << endl;

    delete[] kupche;

    return 0;
}