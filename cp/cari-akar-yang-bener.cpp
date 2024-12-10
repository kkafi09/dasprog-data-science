#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // f(x) = ax^2 + bx + c
    int a = 0, b = 0, c = 0;
    float root_1, root_2;

    cin >> a >> b >> c;

    if (a == 0) return 0;

    float discriminant = (b*b) - 4 * a * c;
    
    if (discriminant > 0) {
        root_1 = (-b - sqrt(discriminant)) / (2 * a);
        root_2 = (-b + sqrt(discriminant)) / (2 * a);

        cout << root_1 << " " << root_2 << endl;
    }

    if (discriminant == 0) {
        root_1 = -b / (2 * a);

        cout << root_1;
    }

    return 0;
}
