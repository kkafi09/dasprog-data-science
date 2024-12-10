#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n = 3, m = 3;
    int matrix[n][m];

    cout << "Masukkan nilai untuk matriks berukuran 3x3 :" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Masukkan nilai untuk elemen [" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
    }

    /*
    * Mean / rata rata 
    */
    int mean = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }
    mean = sum / (m * n);


    /*
    * Median
    */
    int temp[n*m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[k] = matrix[i][j];
            k++;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }
    int median = temp[4]; 

    /*
    * Standar Deviasi
    */
    float standar_deviasi = 0;
    float varians = 0;
    for (int i = 0; i < n*m; i++) {
        varians += (temp[i] - mean) * (temp[i] - mean); 
    }

    varians /= (n*m);
    standar_deviasi = sqrt(varians);

    cout << "Statistik Deskriptif : " << endl;
    cout << "Mean : " << mean << endl;
    cout << "Median : " << median << endl;
    cout << "Standar Deviasi : " << standar_deviasi << endl;

    return 0;
}
