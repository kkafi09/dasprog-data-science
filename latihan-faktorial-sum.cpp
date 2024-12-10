#include<iostream>
#include<cmath>

using namespace std;

int Factorial(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result *= i;
    }

    return result;
}

int Sum(int array[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += array[i];
    }
    return result;
}

int Mean(int array[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += array[i];
    }
    return result / n;
}

int Varians(int array[], int n) {
    int result = 0;
    int mean = Mean(array, n);
    for (int i = 0; i < n; i++) {
        result += (array[i] - mean) * (array[i] - mean);
    }

    return result / n;
}

int main() {

    cout << "Ini adalah fungsi untuk sum dan faktorial yahh..." << endl;

    /*
    * Factorial
    */
    int angka_faktorial = 0;
    cout << "Masukkan faktorial : ";
    cin >> angka_faktorial;
    cout << "Hasil faktorial : " << Factorial(angka_faktorial) << endl;

    /*
    * Sum
    */
    int n;
    cout << "Masukkan panjang array untuk di sum : ";
    cin >> n;

    int array_sum[n];
    for (int i = 0; i < n; i++) {
        cout << "masukkan data ke- " << i+1 << " : ";
        cin >> array_sum[i];
    }

    cout << "Hasil sum : " << Sum(array_sum, n) << endl;
    cout << "Hasil mean : " << Mean(array_sum, n) << endl;

    float varians = Varians(array_sum, n);
    cout << "Hasil varians : " << varians << endl;
    cout << "Hasil Standar Deviasi : " << sqrt(varians) << endl;

    return 0;
}