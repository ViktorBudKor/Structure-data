#include <iostream>
#include "clocale"
using namespace std;

int Euclid(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = Euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int mod(int a, int n) {
    int x, y;
    int gcd = Euclid(a, n, x, y);
    if (gcd != 1) {
        cerr << 0 << endl;
        return -1;
    }

    return (x % n + n) % n;
}

int main() {
    setlocale(LC_ALL, "rus");
    int a, n;
    cin >> a;
    cin >> n;

    int inv = mod(a, n);
    if (inv != -1) {
        cout << inv << endl;
    }
    cout << "Корнюхин Виктор Сергеевич\n090304-РПИб-023";

    return 0;
}
