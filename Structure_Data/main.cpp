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

    cout << "Ââåäèòå a:";
    cin >> a;
    cout << "Ââåäèòå n: ";
    cin >> n;
    time(&start);
    for (int b=0;b<=a;b++){
        if( ((a * b) % n ) == 1){
            cout << b <<" - Çíà÷åíèå îáðàòíîãî  ýëåìåíòà ê ÷èñëó a â êîëüöå âû÷åòîâ ïî ìîäóëþ n"<< endl;
            t = false;
            break;
        }
    }
    if(t){
        cout << 0<<" Îáðàòíîãî  ýëåìåíòà ê ÷èñëó a â êîëüöå âû÷åòîâ ïî ìîäóëþ n íå ñóùåñòâóåò" << endl;
    }
    time(&end);
    seconds = difftime(end,start);
    cout<<seconds<<" - Äëèòåëüíîñòü ðàáîòû â ñåêóíäàõ"<<endl;
    cout<<"Êîðíþõèí Âèêòîð Ñåðãååâè÷\n09.03.04-ÐÏÈá-î23";
    return 0;
}
