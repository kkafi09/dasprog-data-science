#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int x_musuh = 0, y_musuh = 0, v0_musuh = 0;
    int x_kita = 0, y_kita = 0, v0_kita = 0;
    int x_bola = 0, y_bola = 0;

    cin >> x_musuh >> y_musuh >> v0_musuh;
    cin >> x_kita >> y_kita >> v0_kita;
    cin >> x_bola >> y_bola;

    float jarak_musuh = sqrt((x_musuh - x_bola) * (x_musuh - x_bola) + (y_musuh - y_bola) * (y_musuh - y_bola));
    float jarak_kita = sqrt((x_kita - x_bola) * (x_kita - x_bola) + (y_kita - y_bola) * (y_kita - y_bola));

    float waktu_kita = jarak_kita / v0_kita;
    float waktu_musuh = jarak_musuh / v0_musuh;

    if (v0_kita > v0_musuh) {
        cout << "Robot kita lebih ngebut kayak roket ";
    } else if (v0_kita == v0_musuh) {
        cout << "Robot kita sama cepat kayak kembar ";
    } else {
        cout << "Robot kita lebih lelet kayak siput ";
    }

    if (waktu_musuh > waktu_kita) {
        cout << "dan bisa ngerebut bola kayak ninja!";
    } else if(waktu_kita == waktu_musuh) {
        cout << "dan mereka tabrakan kayak adegan film!";
    } else {
        cout << "tapi gak bisa ngerebut bola, kayak keong!";
    }

    return 0;
}
