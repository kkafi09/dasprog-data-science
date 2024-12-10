#include <iostream>
using namespace std;

int main() {
    // Input format: ax^p + bx^q + cx^r -> a,b,c,p,q,r
    int a = 0, b = 0, c = 0, p = 0, q = 0, r = 0;
    cin >> a >> b >> c >> p >> q >> r;

    if (p >= 1) {
        a *= p;
        p--;
    } else {
        a = 0;
    }

    if (q >= 1) {
        b *= q;
        q--;
    } else {
        b = 0;
    }

    if (r >= 1) {
        c *= r;
        r--;
    } else {
        c = 0;
    }

    cout << "Turunan = ";
    bool isFirst = true; 

    if (a != 0) {
        if (a < 0) {
            cout << a;
        } else {
            if (!isFirst) cout << "+";
            cout << a;
        }
        if (p > 0) cout << "x";
        if (p > 1) cout << "^" << p;
        isFirst = false;
    }

    if (b != 0) {
        if (b < 0) {
            cout << b;
        } else {
            if (!isFirst) cout << "+";
            cout << b;
        }
        if (q > 0) cout << "x";
        if (q > 1) cout << "^" << q;
        isFirst = false;
    }

    if (c != 0) {
        if (c < 0) {
            cout << c;
        } else {
            if (!isFirst) cout << "+";
            cout << c;
        }
        if (r > 0) cout << "x";
        if (r > 1) cout << "^" << r;
    }

    if (a == 0 && b == 0 && c == 0) {
        cout << "0";
    }

    cout << endl;
    return 0;
}
