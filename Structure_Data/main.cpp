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

    cout << "������� a:";
    cin >> a;
    cout << "������� n: ";
    cin >> n;
    time(&start);
    for (int b=0;b<=a;b++){
        if( ((a * b) % n ) == 1){
            cout << b <<" - �������� ���������  �������� � ����� a � ������ ������� �� ������ n"<< endl;
            t = false;
            break;
        }
    }
    if(t){
        cout << 0<<" ���������  �������� � ����� a � ������ ������� �� ������ n �� ����������" << endl;
    }
    time(&end);
    seconds = difftime(end,start);
    cout<<seconds<<" - ������������ ������ � ��������"<<endl;
    cout<<"�������� ������ ���������\n09.03.04-����-�23";
    return 0;
}
//9185238495