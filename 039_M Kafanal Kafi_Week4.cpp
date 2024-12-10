#include<iostream>

using namespace std;

int main () {
    int kind_shape, mark, lp, volume;
    const float pi = 3.14;

    cout << "Mau menghitung apa hari ini..." << endl;
    cout << "1. Kubus" << endl;
    cout << "2. Balok" << endl;
    cout << "3. Prisma segitiga" << endl;
    cout << "4. Bola" << endl;

    cout << "Pilih 1 - 4 : ";
    cin >> kind_shape;

    cout << "Luas permukaan apa volume banggg ?? " << endl;
    cout << "1. Volume " << endl;
    cout << "2. Luas permukaan" << endl;
    cout << "Ketik 1 untuk volume... : ";
    cin  >> mark;

    switch (kind_shape) {
        case 1:
            float sisi;

            cout << "\nMasukkan panjang sisi kubus : ";
            cin >> sisi;

            switch (mark) {
                case 1:
                    volume = sisi * sisi * sisi;
                    break;
                case 2:
                    lp = 6 * sisi * sisi;
                    break;
            }            
            break;
        case 2:
            float panjang, lebar, tinggi;
    
            cout << "\nMasukkan panjang sisi balok\t: ";
            cin >> panjang;
            cout << "Masukkan lebar sisi balok\t: ";
            cin >> lebar;
            cout << "Masukkan tinggi sisi balok\t: ";
            cin >> tinggi;

            switch (mark) {
                case 1:
                    volume = panjang * lebar * tinggi;
                    break;
                case 2:
                    lp = 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
                    break;
            }    
            
            break;
        case 3:
            float alas, tinggi_segitiga, tinggi_prisma, luas_alas;
    
            cout << "\nMasukkan panjang alas prisma : ";
            cin >> alas;
            cout << "Masukkan panjang tinggi segitiga prisma : ";
            cin >> tinggi_segitiga;
            cout << "Masukkan panjang tinggi prisma : ";
            cin >> tinggi_prisma;
            
            luas_alas = 0.5 * alas * tinggi_segitiga;
        
            switch (mark) {
                case 1:
                    volume = luas_alas * tinggi_prisma;
                    break;
                case 2:
                    lp = 2 * luas_alas + 3 * alas * tinggi_prisma;
                    break;
            }
            break;
        case 4:
            float jari_jari;
            
            cout << "\nMasukkan jari-jari bola : ";
            cin >> jari_jari;

            switch (mark) {
                case 1:
                    volume = (4.0 / 3.0) * pi * (jari_jari * jari_jari * jari_jari);
                    break;
                case 2:
                    lp = 4 * pi * (jari_jari * jari_jari);
                    break;
            }
            
            break;
        default:
            cout << "Pilihan mu tidak ada bng";
    }

    cout << "\nHasil Perhitungan" << endl;
    if (volume != 0) {
        cout << "Volume\t\t\t\t= " << volume;
    }
    if (lp != 0) {
        cout << "Luas Permukaan\t\t= " << lp << endl;
    }

    return 0;
}