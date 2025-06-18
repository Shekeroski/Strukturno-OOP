#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Number {
public:
    virtual double doubleValue()=0;
    virtual int intValue()=0;
    virtual void print()=0;
    bool operator==(Number &n) {
        return (this->doubleValue()==n.doubleValue() && this->intValue()==n.intValue());
    }
};
class Integer : public Number {
private:
    int broj;
public:
    Integer(int broj):Number() {
        this->broj = broj;
    }
    double doubleValue() {
        return (double) this->broj;
    }
    int intValue() {
        return (int)this->broj;
    }
    void print() {
        cout<<"integer value: "<<this->broj<<endl;
    }
};
class Double : public Number {
    private:
    double broj;
public:
    Double(double broj):Number() {
        this->broj = broj;
    }
    double doubleValue() {
        return (double) this->broj;
    }
    int intValue() {
        return (int)this->broj;
    }
    void print() {
        cout<<"double value: "<<this->broj<<endl;
    }
};
class Numbers {
private:
    Number **numbers;
    int br_elementi;
    public:
    Numbers() {
        numbers = new Number*[0];
        br_elementi=0;
    }
    Numbers(Number **numbers,int br_elementi) {
        this->br_elementi = br_elementi;
        this->numbers = new Number*[br_elementi+1];
        for(int i=0;i<br_elementi;i++) {
            this->numbers[i]=numbers[i];
        }
    }
    ~Numbers() {
        delete [] this->numbers;
    }
    Numbers &operator+=(Number *n) {
        for(int i=0;i<br_elementi;i++) {
            if(*numbers[i]==*n) {
                return *this;
            }
        }
        Number **temp=new Number*[br_elementi+1];
        for(int i=0;i<br_elementi;i++) {
            temp[i]=this->numbers[i];
        }
        temp[br_elementi]=n;
        delete [] this->numbers;
        this->numbers=temp;
        br_elementi++;
        return *this;
    }
    void statistics() {
        int s1=0,s2=0,s3=0,s4=0;
        cout<<"count of numbers: "<<br_elementi<<endl;
        for(int i=0;i<br_elementi;i++) {
            cout<<"count of integer numbers: ";
            for(int j=0;j<br_elementi;j++) {
                if(dynamic_cast<Integer *>(numbers[i])) {
                    s2++;
                    s1+=numbers[i]->intValue();
                }
                if(dynamic_cast<Double *>(numbers[i])) {
                    s3++;
                    s4+=numbers[i]->doubleValue();
                }
            }
            cout<<s2<<endl;
            cout<<"count of double numbers: "<<s3<<endl;
        }
        }
};
int main() {
    int n;
    cin >> n;
    Numbers numbers;
    for (int i = 0; i < n; i++)
    {
        int type;
        double number;
        cin >> type >> number;
        if (type == 0)
        {//Integer object
            Integer *integer = new Integer((int) number);
            numbers += integer;
        }
        else
        {
            Double *doublee = new Double(number);
            numbers += doublee;
        }
    }

    int lessThan;
    double biggerThan;

    cin >> lessThan;
    cin >> biggerThan;

    cout << "STATISTICS FOR THE NUMBERS\n";
    numbers.statistics();
    cout << "INTEGER NUMBERS LESS THAN " << lessThan << endl;
    numbers.integersLessThan(Integer(lessThan));
    cout << "DOUBLE NUMBERS BIGGER THAN " << biggerThan << endl;
    numbers.doublesBiggerThan(Double(biggerThan));

    return 0;
}