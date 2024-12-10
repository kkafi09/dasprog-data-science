#include <iostream>

using namespace std;

int main() {
    cout << "-------- Menghitung BMI --------" << endl;
    float bb, tb, bmi;

    cout << "Masukkan BB : ";
    cin >> bb;
    cout << "Masukkan TB : ";
    cin >> tb;

    bmi = bb / (tb * tb);
    
    if (bmi >= 30) {
        cout << "Obses II";
    } else if (bmi >= 25 && bmi <= 29.99) {
        cout << "Obses I";
    } else if (bmi >= 23 && bmi <= 24.99) {
        cout << "Obses I";
    } else if (bmi >= 18.5 && bmi <= 22.99) {
        cout << "Obses I";
    } else {
        cout << "underweight";   
    }

    return 0;
}