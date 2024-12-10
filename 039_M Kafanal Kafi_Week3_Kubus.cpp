#include<iostream>

using namespace std;

int main () {
    cout << "-------- Menghitung Luas Permukaan dan Volume Kubus --------";
    int sisi, lp, volume;
    
    cout << "\nMasukkan panjang sisi kubus : ";
    cin >> sisi;
    
    lp = 6 * sisi * sisi;
    volume = sisi * sisi * sisi;
    
    cout << "\nHasil Perhitungan" << endl;
    cout << "Luas Permukaan\t\t= " << lp << endl;
    cout << "Volume\t\t\t\t= " << volume;
    
    return 0;
}
