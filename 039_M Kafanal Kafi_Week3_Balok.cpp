#include<iostream>

using namespace std;

int main () {
    cout << "-------- Menghitung Luas Permukaan dan Volume Balok --------";
    int panjang, lebar, tinggi, lp, volume;
    
    cout << "\nMasukkan panjang sisi balok\t: ";
    cin >> panjang;
    cout << "Masukkan lebar sisi balok\t: ";
    cin >> lebar;
    cout << "Masukkan tinggi sisi balok\t: ";
    cin >> tinggi;
    
    lp = 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
    volume = panjang * lebar * tinggi;
    
    cout << "\nHasil Perhitungan" << endl;
    cout << "Luas Permukaan\t= " << lp << endl;
    cout << "Volume\t\t\t= " << volume;
    
    return 0;
}
