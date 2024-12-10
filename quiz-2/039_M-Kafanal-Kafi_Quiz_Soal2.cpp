#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Atlet {
    int id_atlet;
    string nama_atlet;
    float waktu_atlet;
};

Atlet get_minimum(Atlet atlet[], int panjang) {
    Atlet minimum = atlet[0];
    for (int i = 1; i < panjang; i++) {
        if (atlet[i].waktu_atlet < minimum.waktu_atlet) {
            minimum = atlet[i];
        }
    }
    return minimum;
}

void display(Atlet atlet) {
    string first_name = atlet.nama_atlet.substr(0, atlet.nama_atlet.find(" "));
    cout << "\nAtlet dengan waktu tercepat pada uji program adalah:\n";
    cout << "ID    : " << atlet.id_atlet << '\n';
    cout << "Nama  : " << first_name << '\n';
    cout << "Waktu : " << fixed << setprecision(2) << atlet.waktu_atlet << " Detik.\n";
}

int main() {
    int panjang;
    cout << "Masukkan jumlah atlet: ";
    cin >> panjang;
    cin.ignore();

    Atlet atlet[panjang];

    for (int i = 0; i < panjang; i++) {
        cout << "\nMasukkan Atlet ke-" << i + 1 << ":\n";
        cout << "Masukkan ID Atlet    : ";
        cin >> atlet[i].id_atlet;
        cin.ignore();

        while (true) {
            cout << "Masukkan Nama Atlet (maks 50 karakter): ";
            getline(cin, atlet[i].nama_atlet);
            if (atlet[i].nama_atlet.length() <= 50) {
                break;
            }
            cout << "Nama terlalu panjang. Silakan masukkan ulang.\n";
        }

        cout << "Masukkan Waktu Atlet : ";
        cin >> atlet[i].waktu_atlet;
    }

    Atlet atlet_tercepat = get_minimum(atlet, panjang);
    display(atlet_tercepat);

    return 0;
}
