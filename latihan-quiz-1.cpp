#include <iostream>
using namespace std;

struct Produk {
  string id_produk;
  string nama_produk;
  int harga_produk;
};

struct HistoryPenjualan {
  string id_pelanggan;
  string id_produk;
  int jumlah;
};

struct LaporanPenjualan {
  string id_pelanggan;
  int total;
};

int cari_harga_produk(Produk produk[], string idProduk) {
  for (int i = 0; i < 4; i++) {
    if (produk[i].id_produk == idProduk) {
      return produk[i].harga_produk;
    }
  }
  return 0;
}

int main() {
  Produk produk[4] = {
    {"051", "Shampoo", 37000},
    {"052", "Sabun", 15500},
    {"053", "Sikat gigi", 12990},
    {"054", "Sikat gigi", 7350}
  };

  HistoryPenjualan history_penjualan[7] = {
    {"101", "051", 1},
    {"102", "052", 2},
    {"102", "052", 2},
    {"101", "052", 2},
    {"103", "051", 1},
    {"102", "054", 1},
    {"103", "054", 1}
  };

  LaporanPenjualan laporan_penjualan[3] = {{"", 0}, {"", 0}, {"", 0}};
  int laporan_count = 0;

  for (int i = 0; i < 7; i++) {
    string id_pelanggan = history_penjualan[i].id_pelanggan;
    string id_produk = history_penjualan[i].id_produk;
    int jumlah = history_penjualan[i].jumlah;

    int harga_produk = cari_harga_produk(produk, id_produk);
    int total_harga = harga_produk * jumlah;

    bool found = false;
    for (int k = 0; k < laporan_count; k++) {
      if (laporan_penjualan[k].id_pelanggan == id_pelanggan) {
        laporan_penjualan[k].total += total_harga;
        found = true;
        break;
      }
    }

    if (!found) {
      laporan_penjualan[laporan_count].id_pelanggan = id_pelanggan;
      laporan_penjualan[laporan_count].total = total_harga;
      laporan_count++;
    }
  }

  for (int i = 0; i < laporan_count; i++) {
    cout << "Total pembelian pelanggan: " << laporan_penjualan[i].id_pelanggan
         << ", Total penjualan: " << laporan_penjualan[i].total << endl;
  }

  return 0;
}
