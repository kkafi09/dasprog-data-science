#include<iostream>

using namespace std;

int main () {
    cout << "-------- Menghitung Luas Permukaan dan Volume Bola --------";
    float jari_jari, luas_permukaan, volume;
    const float pi = 3.14;
    
    cout << "\nMasukkan jari-jari bola : ";
    cin >> jari_jari;
    
    luas_permukaan = 4 * pi * (jari_jari * jari_jari);
    volume = (4.0 / 3.0) * pi * (jari_jari * jari_jari * jari_jari);
    
    cout << "\nHasil Perhitungan" << endl;
    cout << "Luas Permukaan\t\t= " << luas_permukaan << endl;
    cout << "Volume\t\t\t\t= " << volume;
    
    return 0;
}
