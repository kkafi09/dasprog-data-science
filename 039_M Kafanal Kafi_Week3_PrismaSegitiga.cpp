#include<iostream>

using namespace std;

int main () {
    cout << "-------- Menghitung Luas Permukaan dan Volume Prisma Segitiga --------";
    float alas, tinggi_segitiga, tinggi_prisma, luas_permukaan, volume, luas_alas;
    
    cout << "\nMasukkan panjang alas prisma : ";
    cin >> alas;
    cout << "Masukkan panjang tinggi segitiga prisma : ";
    cin >> tinggi_segitiga;
    cout << "Masukkan panjang tinggi prisma : ";
    cin >> tinggi_prisma;
    
    luas_alas = 0.5 * alas * tinggi_segitiga;
    
    luas_permukaan = 2 * luas_alas + 3 * alas * tinggi_prisma;
    volume = luas_alas * tinggi_prisma;
    
    cout << "\nHasil Perhitungan" << endl;
    cout << "Luas Permukaan\t\t= " << luas_permukaan << endl;
    cout << "Volume\t\t\t\t= " << volume;
    
    return 0;
}
