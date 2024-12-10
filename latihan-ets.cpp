#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n = 11;
    // cout << "Masukkan panjang data : ";
    // cin >> n;
    
    // int data[n];

    int data[n] = {20, 19, 11, 12, 15, 18, 16, 13, 14, 30, 21};

    // Nomor 2 
    int X[n], Y[n];
    int nx = 0, ny = 0;

    for (int i = 0; i < n; i++) {
        if (data[i] % 2 == 0) { // genap
            X[nx] = data[i]; 
            nx++;
        } else {
            Y[ny] = data[i];
            ny++;
        }
    }

    cout << "\nData X : ";
    for (int i = 0; i < nx; i++) {
        cout << X[i] << " ";
    }

    cout << "\nData Y : ";
    for (int i = 0; i < ny; i++) {
        cout << Y[i] << " ";
    }

    // Nomor 3
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < nx; j++) {
            if (X[i] < X[j]) {
                int temp = X[i];
                X[i] = X[j];
                X[j] = temp;
            }
        }
    }

    for (int i = 0; i < ny; i++) {
        for (int j = 0; j < ny; j++) {
            if (Y[i] < Y[j]) {
                int temp = Y[i];
                Y[i] = Y[j];
                Y[j] = temp;
            }
        }
    }

    cout << "\nData X ascending : ";
    for (int i = 0; i < nx; i++) {
        cout << X[i] << " ";
    }

    cout << "\nData Y ascending : ";
    for (int i = 0; i < ny; i++) {
        cout << Y[i] << " ";
    }

    // Nomor 4
    float q1, b, w;
    int a = 0;
    w = (nx + 1) / 4;
    a = trunc(w);
    b = w - a;

    q1 = X[a] + b * (X[a + 1] - X[a]);
    cout << "Kuartil 1 : " << q1 << endl;
    
    return 0;
}