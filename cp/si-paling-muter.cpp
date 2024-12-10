#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void rotatePoint(float x, float y, float angle, float &newX, float &newY) {
    float rad = angle * M_PI / 180.0;
    newX = x * cos(rad) - y * sin(rad);
    newY = x * sin(rad) + y * cos(rad);
}

int main() {
    float x, y, theta;

    cin >> x >> y >> theta;

    float prabowoX, prabowoY;
    float aniesX, aniesY;
    float wasitX, wasitY;

    rotatePoint(x, y, theta, prabowoX, prabowoY);
    rotatePoint(x, y, theta + 180, aniesX, aniesY);
    rotatePoint(x, y, -45, wasitX, wasitY);

    cout << fixed << setprecision(2);
    
    if (abs(prabowoY) < 0.01) prabowoY = 0.0;
    if (abs(aniesY) < 0.01) aniesY = 0.0;
    if (abs(wasitY) < 0.01) wasitY = 0.0;

    cout << prabowoX << " " << prabowoY << endl;
    cout << aniesX << " " << aniesY << endl;
    cout << wasitX << " " << wasitY << endl;

    return 0;
}
