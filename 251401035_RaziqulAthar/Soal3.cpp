#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    // Ambil bagian kode
    string kodeHari = kode.substr(0, 2);
    string kodePelanggan = kode.substr(2, 2);
    int jumlahUnit = stoi(kode.substr(4, 4)); // dalam 100.000

    // Konversi jumlah belanja
    long long jumlahBelanja = jumlahUnit * 100000;

    // Tentukan jenis hari
    string jenisHari;
    if (kodeHari == "01") jenisHari = "Hari Kerja";
    else if (kodeHari == "02") jenisHari = "Akhir Pekan";
    else if (kodeHari == "03") jenisHari = "Hari Libur Nasional";
    else {
        cout << "Kode tidak valid.";
        return 0;
    }

    // Tentukan jenis pelanggan
    string jenisPelanggan;
    if (kodePelanggan == "01") jenisPelanggan = "Biasa";
    else if (kodePelanggan == "02") jenisPelanggan = "Silver";
    else if (kodePelanggan == "03") jenisPelanggan = "Gold";
    else {
        cout << "Kode tidak valid.";
        return 0;
    }

    // Tentukan poin per 100.000
    int poinPerUnit = 0;

    if (kodeHari == "01") { // Hari kerja
        if (kodePelanggan == "01") poinPerUnit = 1;
        else if (kodePelanggan == "02") poinPerUnit = 2;
        else if (kodePelanggan == "03") poinPerUnit = 3;
    }
    else if (kodeHari == "02") { // Weekend
        if (kodePelanggan == "01") poinPerUnit = 2;
        else if (kodePelanggan == "02") poinPerUnit = 3;
        else if (kodePelanggan == "03") poinPerUnit = 5;
    }
    else if (kodeHari == "03") { // Libur
        if (kodePelanggan == "01") poinPerUnit = 3;
        else if (kodePelanggan == "02") poinPerUnit = 5;
        else if (kodePelanggan == "03") poinPerUnit = 7;
    }

    // Hitung total poin
    int totalPoin = poinPerUnit * jumlahUnit;

    // Output sesuai soal
    cout << "Jenis Hari: " << jenisHari << endl;
    cout << "Jenis Pelanggan: " << jenisPelanggan << endl;
    cout << "Jumlah Belanja: Rp " << jumlahBelanja << endl;
    cout << "Total Poin: " << totalPoin << endl;

    return 0;
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
