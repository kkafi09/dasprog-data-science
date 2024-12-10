#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string number;
    int from_basis, to_basis;

    cin >> number >> from_basis >> to_basis;

    long long decimal_value = 0; 
    int length = number.length();  

    for (int i = 0; i < length; i++) {
        char digit = number[length - 1 - i]; 
        int digit_value;

        if (digit >= '0' && digit <= '9') {
            digit_value = digit - '0'; 
        } else if (digit >= 'A' && digit <= 'F') {
            digit_value = digit - 'A' + 10; 
        } else {
            cout << "Karakter tidak valid" << endl; 
            return 1; 
        }

        decimal_value += digit_value * pow(from_basis, i); 
    }

    if (decimal_value == 0) {
        cout << "0" << endl;
    } else {
        string result = ""; 

        while (decimal_value > 0) {
            int remainder = decimal_value % to_basis; 
            if (remainder < 10) {
                result += (char)(remainder + '0');
            } else {
                result += (char)(remainder - 10 + 'A'); 
            }
            decimal_value /= to_basis; 
        }

        reverse(result.begin(), result.end());
        cout << result << endl; 
    }

    return 0;
}
