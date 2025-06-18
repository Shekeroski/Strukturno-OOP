#include <iostream>
using namespace std;

bool isCikCak(int broj) {
    int prethodna_cifra = -1;
    bool porak = true; // true ако последната цифра треба да биде помала, false ако треба да биде поголема

    // Проверка за минимален број на цифри
    if (broj < 10) {
        return false; // Броевите со една цифра не се цик-цак
    }

    while (broj > 0) {
        int trenutna_cifra = broj % 10; // Земете ја последната цифра
        broj /= 10; // Отстранете ја последната цифра

        // Прва цифра нема претходна цифра, па ја прескокнуваме проверката
        if (prethodna_cifra != -1) {
            // Проверуваме дали следната цифра е поголема или помала во споредба со претходната
            if (porak) { // Ако очекуваме помала цифра
                if (trenutna_cifra >= prethodna_cifra) {
                    return false; // Ако не е помала, не е цик-цак
                }
            } else { // Ако очекуваме поголема цифра
                if (trenutna_cifra <= prethodna_cifra) {
                    return false; // Ако не е поголема, не е цик-цак
                }
            }
        }

        // Променете го статусот на поредокот
        porak = !porak; // Ако беше помала, сега очекуваме поголема, и обратно

        // Ажурирајте ја претходната цифра
        prethodna_cifra = trenutna_cifra;
    }

    return true; // Ако стигнавме тука, бројот е цик-цак
}

int main() {
    int broj;
    while (true) {
        cout << "Внесете број (или 0 за завршување): ";
        cin >> broj;

        if (broj == 0) {
            break; // Заврши ако е внесен 0
        }

        // Проверка дали е цик-цак
        if (isCikCak(broj)) {
            cout << broj << " е цик-цак." << endl; // Печати цик-цак број
        } else {
            cout << broj << " не е цик-цак." << endl; // Печати дека не е цик-цак
        }
    }

    return 0; // Завршува програмата
}
/* #include <iostream>

using namespace std;

int counterLenght(int num){
    int counter = 0;

    while(num!=0){
        counter++;
        num/=10;
    }
    return counter;
}

int main() {
    int n;

    while(cin>>n){
        bool flag;

        if(counterLenght(n)==1){
            continue;
        }

        if(n<0){
            continue;
        }

        if(n%10>(n/10)%10){
            flag = false;
        }else if(n%10<(n/10)%10){
            flag = true;
        }else{
            continue;
        }


        int tmp = n;
        tmp/=10;
        bool checkNumberTrue = true;

        while(tmp>10){
            if(flag && tmp%10>(tmp/10)%10){
                flag = false;
                tmp/=10;
            }else if(!flag && tmp%10<(tmp/10)%10){
                flag = true;
                tmp/=10;
            }else{
                checkNumberTrue = false;
                break;
            }
        }

        if(checkNumberTrue){
            cout<<n<<endl;
        }
    }

    return 0;
}
 */