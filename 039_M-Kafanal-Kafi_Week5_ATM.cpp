#include<iostream>

using namespace std;

// NB: Didalam code saya memberikan return 1 disetiap terjadi kesalahan. 
// hanya sebagai penanda seperti http status code hehe
int main() {
    int input_pin, action, amount, pin = 1234, saldo = 1000000;

    cout << "Enter pin: ";
    cin >> input_pin;

    if (input_pin != pin) {
        cout << "PIN Anda salah!!";
        return 1;
    }

    cout << "1. Cek Saldo" << endl;
    cout << "2. Tarik Tunai" << endl;
    cout << "3. Setor Tunai" << endl;
    cout << "\nInput pilihan : ";
    cin >> action;

    switch (action) {
        case 1:
            cout << "Saldo anda : " << saldo;
            break;
        case 2:
            cout << "Saldo yang di tarik : ";
            cin >> amount;

            if (amount > saldo) {
                cout << "Saldo anda tidak cukup";
                return 1;
            }

            saldo -= amount;
            cout << "Saldo anda sekarang : " << saldo;
            break;
        case 3:
            cout << "Saldo yang di setor : ";
            cin >> amount;

            saldo += amount;
            cout << "Saldo anda sekarang : " << saldo;
            break;
        default: 
            cout << "Pilihan menu tidak tersedia";
    }

    return 0;
}