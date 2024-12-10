#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    
    for (int i = a; i <= b; i++) {
        int count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++;
            }
        }
        
        if (count == 2) cout << i << " ";
    }
    return 0;
}
