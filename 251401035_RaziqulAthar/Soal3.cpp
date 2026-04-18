#include <iostream>
using namespace std;

int main() {
    string kode;
    cin >> kode;

    string hari = kode.substr(0,2);
    string loyal = kode.substr(2,2);
    int belanja = stoi(kode.substr(4,4));

    int poinPerUnit = 0;

    if (hari == "01") { // hari kerja
        if (loyal == "01") poinPerUnit = 1;
        else if (loyal == "02") poinPerUnit = 2;
        else if (loyal == "03") poinPerUnit = 3;
    }
    else if (hari == "02") { // weekend
        if (loyal == "01") poinPerUnit = 2;
        else if (loyal == "02") poinPerUnit = 3;
        else if (loyal == "03") poinPerUnit = 5;
    }
    else if (hari == "03") { // libur
        if (loyal == "01") poinPerUnit = 3;
        else if (loyal == "02") poinPerUnit = 5;
        else if (loyal == "03") poinPerUnit = 7;
    }

    int totalPoin = poinPerUnit * belanja;

    cout << "Total poin: " << totalPoin;
}

/*
ALGORITMA SISTEM POIN BELANJA:

1. Input kode transaksi (8 digit).
2. Ambil bagian kode:
   - 2 digit pertama → jenis hari
   - 2 digit berikutnya → jenis pelanggan
   - 4 digit terakhir → jumlah belanja (dalam satuan 100.000)

3. Tentukan jenis hari:
   - 01 → hari kerja
   - 02 → akhir pekan
   - 03 → hari libur nasional

4. Tentukan jenis pelanggan:
   - 01 → biasa
   - 02 → silver
   - 03 → gold

5. Tentukan poin per 100.000 berdasarkan kombinasi:
   - Hari kerja → (1,2,3)
   - Weekend → (2,3,5)
   - Libur → (3,5,7)

6. Hitung total poin:
   totalPoin = poinPerUnit × jumlahBelanja

7. Tampilkan:
   - jenis hari
   - jenis pelanggan
   - jumlah belanja
   - total poin
*/
