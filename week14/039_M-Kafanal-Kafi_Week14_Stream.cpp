#include<iostream>
#include<fstream>

using namespace std;

struct Nilai {
    int roll;
    string name;
    int task, midterm, quiz, final;
};

int main() {
    int n = 0;
    cout << "Masukkan jumlah data : ";
    cin >> n;

    Nilai data_nilai[n];
    ofstream writefile("latihan-csv-file.csv");

    writefile << "roll" << "," << "name" << "," << "task" << "," << "midterm" << "," << "quiz" << "," << "final" << "\n";

    for (int i = 0; i < n; i++) {
        cout << "\nMasukkan data nilai ke-" << i + 1 << ": " << endl;
        data_nilai[i].roll = i+1;
        cout << "Masukkan name : ";
        cin >> data_nilai[i].name;
        cout << "Masukkan task : ";
        cin >> data_nilai[i].task;
        cout << "Masukkan midterm : ";
        cin >> data_nilai[i].midterm;
        cout << "Masukkan quiz : ";
        cin >> data_nilai[i].quiz;
        cout << "Masukkan final : ";
        cin >> data_nilai[i].final;

        writefile << data_nilai[i].roll << "," << data_nilai[i].name << "," << data_nilai[i].task << "," << data_nilai[i].midterm << "," << data_nilai[i].quiz << "," << data_nilai[i].final <<  endl;
    }

    // useless biar estetik
    writefile << "\n\n";

    for (int i = 0; i < n; i++) {
        double result = (data_nilai[i].task * 0.15) + (data_nilai[i].midterm * 0.30) + (data_nilai[i].quiz * 0.25) + (data_nilai[i].final * 0.30);
        writefile << "Nilai Akhir dari " << data_nilai[i].name << " : " << result << endl;
    }
}
