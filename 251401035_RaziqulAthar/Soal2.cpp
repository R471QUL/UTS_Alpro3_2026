#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string kode;
    int keluar;
    cin >> kode >> keluar;

    string jenisKode = kode.substr(0,2);
    int masuk = stoi(kode.substr(2,4));

    int jamMasuk = masuk / 100;
    int menitMasuk = masuk % 100;

    int jamKeluar = keluar / 100;
    int menitKeluar = keluar % 100;

    int totalMenit = (jamKeluar*60 + menitKeluar) - (jamMasuk*60 + menitMasuk);
    int jam = ceil(totalMenit / 60.0);

    int biaya = 0;

    if (jenisKode == "10") {
        biaya = 5000 + (jam-1)*3000;
        cout << "Mobil\n";
    } else if (jenisKode == "20") {
        biaya = 3000 + (jam-1)*2000;
        cout << "Motor\n";
    } else if (jenisKode == "30") {
        biaya = 10000 + (jam-1)*7000;
        cout << "Bus\n";
    }

    cout << "Durasi: " << jam << " jam\n";
    cout << "Biaya: " << biaya;
}
/*
ALGORITMA SISTEM PARKIR:

1. Input kode parkir (10 digit) dan jam keluar (HHMM).
2. Ambil informasi dari kode:
   - 2 digit pertama → jenis kendaraan.
   - 4 digit berikutnya → waktu masuk (HHMM).
   - 4 digit terakhir → lokasi (tidak dipakai dalam perhitungan).

3. Pisahkan waktu:
   - Jam masuk dan menit masuk.
   - Jam keluar dan menit keluar.

4. Konversi semua waktu ke menit:
   totalMenit = (jamKeluar*60 + menitKeluar) - (jamMasuk*60 + menitMasuk)

5. Hitung durasi dalam jam:
   - durasi = pembulatan ke atas dari totalMenit / 60

6. Tentukan tarif berdasarkan jenis kendaraan:
   - Mobil → 5000 jam pertama, 3000 berikutnya
   - Motor → 3000 jam pertama, 2000 berikutnya
   - Bus → 10000 jam pertama, 7000 berikutnya

7. Hitung total biaya:
   biaya = tarif awal + (durasi-1) * tarif berikutnya

8. Tampilkan:
   - jenis kendaraan
   - durasi parkir
   - total biaya
*/
