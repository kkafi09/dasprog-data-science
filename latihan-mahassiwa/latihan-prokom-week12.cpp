#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MataKuliah {
    string nama_matkul;
    int sks;
    int nilai;
    double nilai_conv_numeric;
    string nilai_conv_letter;
};

struct Mahasiswa {
    string NRP;
    string nama;
    MataKuliah matkul[5];
};

double get_ip_semester(MataKuliah matkul[]);
double get_conversion_numeric(MataKuliah matkul);
int get_sks_semester(MataKuliah matkul[]);
int get_index_mahasiswa(vector<Mahasiswa>& data_mahasiswa, string& nrp);
string get_conversion_letter(MataKuliah matkul);
Mahasiswa get_by_nrp(vector<Mahasiswa>& data_mahasiswa, string& nrp);
bool delete_by_nrp(vector<Mahasiswa>& data_mahasiswa, string& nrp);

int main() {
    int input = 0;
    vector<Mahasiswa> data_mahasiswa;

    do {
        cout << "========MENU========\n";
        cout << "1. Input data mahasiswa" << endl;
        cout << "2. Tampilkan data mahasiswa" << endl;
        cout << "3. Cari data mahasiswa" << endl;
        cout << "4. Hapus data mahasiswa" << endl;
        cout << "5. Edit data mahasiswa" << endl;
        cout << "0. Keluar dari program" << endl;

        cout << "Masukkan pilihan anda : ";
        cin >> input;

        switch (input) {
            case 0: {
                cout << "\nAnda berhasil keluar dari program" << endl;
                break;
            }
            case 1: {
                Mahasiswa data_temp;

                cout << "========INPUT DATA MAHASISWA========\n" << endl;
                cin.ignore();
                cout << "Masukkan nama mahasiswa : ";
                getline(cin, data_temp.nama);
                cout << "Masukkan NRP mahasiswa : ";
                cin >> data_temp.NRP;

                for (int i = 0; i < 5; i++) {
                    cin.ignore();

                    cout << "Masukkan nama MK " << i + 1 << ": ";
                    getline(cin, data_temp.matkul[i].nama_matkul);
                    cout << "Masukkan bobot SKS MK " << data_temp.matkul[i].nama_matkul << " : ";
                    cin >> data_temp.matkul[i].sks;
                    cout << "Masukkan nilai " << data_temp.matkul[i].nama_matkul << " : ";
                    cin >> data_temp.matkul[i].nilai;

                    data_temp.matkul[i].nilai_conv_numeric = get_conversion_numeric(data_temp.matkul[i]);
                    data_temp.matkul[i].nilai_conv_letter = get_conversion_letter(data_temp.matkul[i]);
                }

                data_mahasiswa.push_back(data_temp);
                break;
            }
            case 2: {
                cout << "\n========Tampilkan data mahasiswa========" << endl;
                for (int i = 0; i < (int)data_mahasiswa.size(); i++) {
                    cout << "=== MAHASISWA " << i + 1 << " ===" << endl;
                    cout << "Nama mahasiswa : " << data_mahasiswa[i].nama << endl;
                    cout << "NRP mahasiswa : " << data_mahasiswa[i].NRP << endl;

                    cout << "Nama MK\t\t" << "SKS\t" << "Nilai Huruf" << endl;
                    for (int j = 0; j < 5; j++) {
                        cout << data_mahasiswa[i].matkul[j].nama_matkul << "\t\t"
                             << data_mahasiswa[i].matkul[j].sks << "\t"
                             << data_mahasiswa[i].matkul[j].nilai_conv_letter << endl;
                    }

                    double sks_semester = get_sks_semester(data_mahasiswa[i].matkul);
                    double ip_semester = get_ip_semester(data_mahasiswa[i].matkul);

                    cout << "IPS Semester : " << ip_semester << endl;
                    cout << "SKS Semester : " << sks_semester << endl;
                }
                break;
            }
            case 3: {
                string input_nrp;

                cout << "\n========MENCARI DATA MAHASISWA========" << endl;
                cout << "Masukkan NRP mahasiswa : ";
                cin >> input_nrp;

                Mahasiswa mahasiswa_found = get_by_nrp(data_mahasiswa, input_nrp);

                if (!mahasiswa_found.nama.empty()) {
                    cout << "Nama mahasiswa : " << mahasiswa_found.nama << endl;
                    cout << "NRP mahasiswa : " << mahasiswa_found.NRP << endl;

                    cout << "Nama MK\t\t" << "SKS\t" << "Nilai Huruf" << endl;
                    for (int j = 0; j < 5; j++) {
                        cout << mahasiswa_found.matkul[j].nama_matkul << "\t\t"
                             << mahasiswa_found.matkul[j].sks << "\t"
                             << mahasiswa_found.matkul[j].nilai_conv_letter << endl;
                    }

                    double sks_semester = get_sks_semester(mahasiswa_found.matkul);
                    double ip_semester = get_ip_semester(mahasiswa_found.matkul);

                    cout << "IPS Semester : " << ip_semester << endl;
                    cout << "SKS Semester : " << sks_semester << endl;
                } else {
                    cout << "Mahasiswa dengan NRP tersebut tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string input_nrp;

                cout << "\n========MENGHAPUS DATA MAHASISWA========" << endl;
                cout << "Masukkan NRP mahasiswa : ";
                cin >> input_nrp;

                bool deleted_mahasiswa = delete_by_nrp(data_mahasiswa, input_nrp);
                if (!deleted_mahasiswa) {
                    cout << "NRP yang anda masukkan tidak ada di database ini." << endl;
                } else {
                    cout << "Mahasiswa dengan NRP " << input_nrp << " berhasil di hapus." << endl;
                }
                break;
            }
            case 5: {
                string input_nrp;
                int pilihan;

                cout << "\n========MENGEDIT DATA MAHASISWA========" << endl;
                cout << "Masukkan NRP mahasiswa : ";
                cin >> input_nrp;

                cout << "Data apa yang ingin anda edit ?" << endl;
                cout << "1. Nama" << endl;
                cout << "2. NRP" << endl;
                cout << "3. Mata Kuliah" << endl;
                cout << "Pilihan anda : ";
                cin >> pilihan;

                int index_mahasiswa = get_index_mahasiswa(data_mahasiswa, input_nrp);

                switch (pilihan) {
                    case 1: {
                        cout << "Masukkan nama baru: ";
                        cin.ignore();
                        getline(cin, data_mahasiswa[index_mahasiswa].nama);
                        cout << "Nama berhasil diperbarui!" << endl;
                        break;
                    }
                    case 2: {
                        cout << "Masukkan NRP baru: ";
                        cin >> data_mahasiswa[index_mahasiswa].NRP;
                        cout << "NRP berhasil diperbarui!" << endl;
                        break;
                    }
                    case 3: {
                        int matkul_index;
                        cout << "Pilih mata kuliah yang ingin diedit (1-5): ";
                        cin >> matkul_index;
                        if (matkul_index < 1 || matkul_index > 5) {
                            cout << "Pilihan mata kuliah tidak valid!" << endl;
                            break;
                        }
                        matkul_index--;

                        cout << "Masukkan nama mata kuliah baru: ";
                        cin.ignore();
                        getline(cin, data_mahasiswa[index_mahasiswa].matkul[matkul_index].nama_matkul);

                        cout << "Masukkan jumlah SKS: ";
                        cin >> data_mahasiswa[index_mahasiswa].matkul[matkul_index].sks;

                        cout << "Masukkan nilai: ";
                        cin >> data_mahasiswa[index_mahasiswa].matkul[matkul_index].nilai;

                        cout << "Mata kuliah berhasil diperbarui!" << endl;
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                    break;
                }
            }
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (input != 0);

    return 0;
}

int get_index_mahasiswa(vector<Mahasiswa>& data_mahasiswa, string& nrp) {
    for (int i = 0; i < data_mahasiswa.size(); ++i) {
        if (data_mahasiswa[i].NRP == nrp) {
            return i;
        }
    }
    return -1;
}

bool delete_by_nrp(vector<Mahasiswa>& data_mahasiswa, string& nrp) {
    for (int i = 0; i < data_mahasiswa.size(); ++i) {
        if (data_mahasiswa[i].NRP == nrp) {
            data_mahasiswa.erase(data_mahasiswa.begin() + i);
            return true;
        }
    }
    return false;
}

Mahasiswa get_by_nrp(vector<Mahasiswa>& data_mahasiswa, string& nrp) {
    for (int i = 0; i < data_mahasiswa.size(); i++) {
        if (data_mahasiswa[i].NRP == nrp) {
            return data_mahasiswa[i];
        }
    }
    return {};
}

int get_sks_semester(MataKuliah matkul[]) {
    int sks = 0;
    for (int i = 0; i < 5; i++) {
        sks += matkul[i].sks;
    }
    return sks;
}

double get_ip_semester(MataKuliah matkul[]) {
    double total_nilai = 0;
    int total_sks = 0;
    for (int i = 0; i < 5; i++) {
        total_nilai += matkul[i].nilai_conv_numeric * matkul[i].sks;
        total_sks += matkul[i].sks;
    }
    return total_sks > 0 ? total_nilai / total_sks : 0.0;
}

double get_conversion_numeric(MataKuliah matkul) {
    if (matkul.nilai >= 86 && matkul.nilai <= 100) {
        return 4.0;
    } else if (matkul.nilai >= 76 && matkul.nilai <= 85) {
        return 3.5;
    } else if (matkul.nilai >= 66 && matkul.nilai <= 75) {
        return 3.0;
    } else if (matkul.nilai >= 61 && matkul.nilai <= 65) {
        return 2.5;
    } else if (matkul.nilai >= 56 && matkul.nilai <= 60) {
        return 2.0;
    } else if (matkul.nilai >= 41 && matkul.nilai <= 55) {
        return 1.5;
    } else if (matkul.nilai >= 0 && matkul.nilai <= 40) {
        return 0.0;
    }

    return 0.0;
}

string get_conversion_letter(MataKuliah matkul) {
    if (matkul.nilai >= 86 && matkul.nilai <= 100) {
        return "A";
    } else if (matkul.nilai >= 76 && matkul.nilai <= 85) {
        return "AB";
    } else if (matkul.nilai >= 66 && matkul.nilai <= 75) {
        return "B";
    } else if (matkul.nilai >= 61 && matkul.nilai <= 65) {
        return "BC";
    } else if (matkul.nilai >= 56 && matkul.nilai <= 60) {
        return "C";
    } else if (matkul.nilai >= 41 && matkul.nilai <= 55) {
        return "D";
    } else if (matkul.nilai >= 0 && matkul.nilai <= 40) {
        return "E";
    }

    return "E";
}
