#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

struct LokasiKonstruksi {
  int id;
  int material;
  double biaya[3];
};

LokasiKonstruksi find_konstruksi_terbesar(LokasiKonstruksi data_lokasi[], int panjang);

double sum_biaya(LokasiKonstruksi data_lokasi_terbesar);

double mean_biaya(LokasiKonstruksi data_lokasi_terbesar);

string nama_material(int code);

int main() {
  int max = 30;
  LokasiKonstruksi data_konstruksi[max];

  /*
   *  Baca file konstruksi.txt
   */
  fstream file;
  file.open("konstruksi.txt", ios::in);

  if (!file.is_open()) {
    cout << "tidak ada file konstruksi.txt" << endl;
    return 1;
  }

  char separator;
  while (!file.eof()) {
    for (int i = 0; i < max; i++) {
      file >> data_konstruksi[i].id;
      file >> separator;
      file >> data_konstruksi[i].material;
      file >> separator;
      file >> data_konstruksi[i].biaya[0];
      file >> separator;
      file >> data_konstruksi[i].biaya[1];
      file >> separator;
      file >> data_konstruksi[i].biaya[2];
    }
  }
  file.close();


  /*
   *  cetak ID lokasi, nama material dominan, dan rata-rata biaya tiga proyek
   */
  fstream file_output1;
  file_output1.open("output1_konstruksi.txt", ios::out);

  cout << "Print output1_konstruksi.txt : " << endl;
  for (int i = 0; i < max; i++) {
    cout << std::left << std::setw(5) << data_konstruksi[i].id
        << std::setw(20) << nama_material(data_konstruksi[i].material)
        << std::right << std::setw(15) << mean_biaya(data_konstruksi[i]) << "\n";
    file_output1 << std::left << std::setw(5) << data_konstruksi[i].id
        << std::setw(20) << nama_material(data_konstruksi[i].material)
        << std::right << std::setw(15) << mean_biaya(data_konstruksi[i]) << "\n";
  }

  if (file_output1) {
    cout << "File output1_konstruksi.txt berhasil dibuat" << endl;
  }

  file_output1.close();

  /*
   *  Menentukan lokasi dengan rata-rata biaya proyek tertinggi untuk setiap jenis material
   *  dengan asumsi
   *  1 -> Beton Bertulang
   *  2 -> Baja
   *  3 -> Kayu
   *  4 -> Bambu
   */
  int jumlah_material = 5;
  LokasiKonstruksi proyek_tertinggi_permaterial[jumlah_material];
  int kode_material[jumlah_material] = {1, 2, 3, 4, 100};

  for (int i = 0; i < max; i++) {
    for (int j = 0; j < jumlah_material; j++) {
      if (data_konstruksi[i].material == kode_material[j]) {
        if (proyek_tertinggi_permaterial[j].id == -1) {
          proyek_tertinggi_permaterial[j] = data_konstruksi[i];
        }

        if (mean_biaya(data_konstruksi[i]) > mean_biaya(proyek_tertinggi_permaterial[j])) {
          proyek_tertinggi_permaterial[j] = data_konstruksi[i];
        }
      }
    }
  }

  fstream file_output2;
  file_output2.open("output2_konstruksi.txt", ios::out);

  cout << "\nPrint output2_konstruksi.txt : " << endl;
  for (int i = 0; i < 5; i++) {
    cout << std::left << std::setw(20) << nama_material(proyek_tertinggi_permaterial[i].material)
        << std::setw(10) << proyek_tertinggi_permaterial[i].id
        << std::setw(15) << fixed << setprecision(2) << mean_biaya(proyek_tertinggi_permaterial[i]) << endl;

    file << std::left << std::setw(20) << nama_material(proyek_tertinggi_permaterial[i].material)
        << std::setw(10) << proyek_tertinggi_permaterial[i].id
        << std::setw(15) << fixed << setprecision(2) << mean_biaya(proyek_tertinggi_permaterial[i]) << endl;
  }

  if (file_output2) {
    cout << "File output2_konstruksi.txt berhasil dibuat" << endl;
  }

  file_output2.close();
}

LokasiKonstruksi find_konstruksi_terbesar(LokasiKonstruksi data_lokasi[], int panjang) {
  double data_biaya_awal = data_lokasi[0].biaya[0] + data_lokasi[0].biaya[1] + data_lokasi[0].biaya[2];
  LokasiKonstruksi data_lokasi_terbesar = data_lokasi[0];

  for (int i = 1; i < panjang; i++) {
    double biaya_data_ke_i = data_lokasi[i].biaya[0] + data_lokasi[i].biaya[1] + data_lokasi[i].biaya[2];
    if (biaya_data_ke_i > data_biaya_awal) {
      data_lokasi_terbesar = data_lokasi[i];
    }
  }

  return data_lokasi_terbesar;
}

double sum_biaya(LokasiKonstruksi data_lokasi_terbesar) {
  return data_lokasi_terbesar.biaya[0] + data_lokasi_terbesar.biaya[1] + data_lokasi_terbesar.biaya[2];
}

double mean_biaya(LokasiKonstruksi data_lokasi_terbesar) {
  return sum_biaya(data_lokasi_terbesar) / 3;
}

string nama_material(int code) {
  switch (code) {
    case 1:
      return "Beton Bertulang";
    case 2:
      return "Baja";
    case 3:
      return "Kayu";
    case 4:
      return "Bambu";
    default:
      return "Tidak Dikenal";
  }
}
