#include<iostream>

using namespace std;

string reversIt(string sentence) {
    string result;
    for (int i = sentence.size() - 1; i >= 0 ; i--) {
        result += sentence[i];
    }
    return result;
}

int main() {
    string input;
    cout << "Masukkan kata untuk di reverse :";
    getline(cin, input);

    cout << reversIt(input) << endl;

    return 0;
}