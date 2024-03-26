#include <iostream>
#include "ctime"
#include "clocale"
using namespace std;


int main() {
    setlocale(0,"Rus");
    double seconds;
    time_t start,end;
    bool t = true;
    int a,n,timeS,timeE;

    cout << "Введите a:";
    cin >> a;
    cout << "Введите n: ";
    cin >> n;
    time(&start);
    for (int b=0;b<=a;b++){
        if( ((a * b) % n ) == 1){
            cout << b <<" - Значение обратного  элемента к числу a в кольце вычетов по модулю n"<< endl;
            t = false;
            break;
        }
    }
    if(t){
        cout << 0<<" Обратного  элемента к числу a в кольце вычетов по модулю n не существует" << endl;
    }
    time(&end);
    seconds = difftime(end,start);
    cout<<seconds<<" - Длительность работы в секундах"<<endl;
    cout<<"Корнюхин Виктор Сергеевич\n09.03.04-РПИб-о23";
    return 0;
}
//9185238495