#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Shape {
protected:
    int a;
    public:
    Shape(){}
    Shape(int a=0) {
        this->a = a;
    }
    virtual double plostina()=0;
    virtual void pecati()=0;
    virtual int getType()=0;
};
class Square : public Shape {
public:
    Square(int a=0):Shape(a) {
    }
    double plostina() {
        return a*a;
    }
    void pecati() {
        cout << "area Square: " << plostina() << endl;
    }
    int getType() {
        return 1;
    }
};
class Circle : public Shape {
    public:
    Circle(int a=0):Shape(a) {}
    double plostina() {
        return 3.14*a*a;
    }
    void pecati() {
        cout << "area Circle: " << plostina() << endl;
    }
    int getType() {
        return 2;
    }
};
class Triangle : public Shape {
    public:
    Triangle(int a=0):Shape(a) {}
    double plostina() {
        return (sqrt(3)*a*a);
    }
    void pecati() {
        cout << "area Triangle: " << plostina() << endl;
    }
    int getType() {
        return 3;
    }
};
void checkNumTypes(Shape **niza,int n) {
    int s=0,t=0,c=0;
    for(int i=0;i<n;i++) {
        if(niza[i]->getType()==1) {
            s++;
        }
        if(niza[i]->getType()==2) {
            c++;
        }
        if(niza[i]->getType()==3) {
            t++;
        }
    }
    cout << "Broj na kvadrati vo nizata = " << s << endl;
    cout << "Broj na krugovi vo nizata = " << c << endl;
    cout << "Broj na triagolnici vo nizata = " << t << endl;
}
int main()
{
    int n;
    cin >> n;

    Shape **shape = new Shape *[n];

    int classType;
    int side;

    for (int i = 0; i < n; ++i)
    {
        cin >> classType;
        cin >> side;

        if (classType == 1)
            shape[i] = new Square(side);
        else if (classType == 2)
            shape[i] = new Circle(side);
        else if (classType == 3)
            shape[i] = new Triangle(side);
    }

    for (int i = 0; i < n; ++i)
        shape[i]->pecati();

    checkNumTypes(shape, n);

    return 0;
}