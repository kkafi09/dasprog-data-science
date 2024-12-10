#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float x1, x2, y1, y2, deltaTime;
    cin >> x1 >> x2 >> y1 >> y2 >> deltaTime;

    float vx = (x2 - x1) / deltaTime;
    float vy = (y2 - y1) / deltaTime;

    float timeToZero = -y1 / vy;

    float xAtZero = x1 + vx * timeToZero;

    cout << fixed << setprecision(2);
    cout << "Posisi bola x pada y: 0.00 cm adalah " << xAtZero << " cm" << endl;

    if (xAtZero >= -300 && xAtZero <= 500) {
        cout << "Bola bergerak menuju tiang gawang" << endl;
    } else {
        cout << "Bola tidak bergerak menuju tiang gawang" << endl;
    }

    return 0;
}
