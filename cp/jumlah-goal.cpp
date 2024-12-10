#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    unsigned long long G;
    cin >> G; 

    if (G == 0) {
        cout << "Terbilang: Nol Gol." << endl;
        return 0;
    }

    string result;
    vector<string> belowTwenty = {
        "Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh",
        "Delapan", "Sembilan", "Sepuluh", "Sebelas", "Dua Belas", 
        "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", 
        "Tujuh Belas", "Delapan Belas", "Sembilan Belas"
    };
    vector<string> tens = {
        "", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", 
        "Lima Puluh", "Enam Puluh", "Tujuh Puluh", 
        "Delapan Puluh", "Sembilan Puluh"
    };
    vector<string> units = {
        "", "Ribu", "Juta", "Miliar", "Triliun", "Kuadriliun", "Kuintiliun"
    };

    int unitIndex = 0;

    while (G > 0) {
        int part = G % 1000;  
        G /= 1000;  

        string partInWords;
        
        if (part >= 100) {
            if (part == 100) {
                partInWords += "Seratus "; 
            } else {
                partInWords += belowTwenty[part / 100] + " Ratus ";  
            }
            part %= 100;
        }
        
        if (part >= 20) {
            partInWords += tens[part / 10] + " "; 
            part %= 10;
        }
        
        if (part > 0) {
            partInWords += belowTwenty[part] + " ";
        }

        if (partInWords.length() > 0) {
            result = partInWords + units[unitIndex] + " " + result;
        }

        unitIndex++;
    }

    result += "Gol.";  

    result.erase(result.find_last_not_of(' ') + 1); 
    cout << "Terbilang: " << result << endl;

    return 0;
}
