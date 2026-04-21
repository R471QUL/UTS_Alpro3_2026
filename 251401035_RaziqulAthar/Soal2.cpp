#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    int jamKeluar;

    // Input
    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;

    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> jamKeluar;

    cout << endl;
    cout << "--- Ringkasan Parkir ---" << endl;

    // Ambil data dari kode
    string jenisKode = kode.substr(0, 2);
    string waktuMasukStr = kode.substr(2, 4);
    string lokasi = kode.substr(6, 4);

    // Ambil jam & menit masuk
    int jamMasuk = stoi(waktuMasukStr.substr(0, 2));
    int menitMasuk = stoi(waktuMasukStr.substr(2, 2));

    // Ambil jam & menit keluar
    int jamKeluarJam = jamKeluar / 100;
    int menitKeluar = jamKeluar % 100;

    // Hitung durasi (menit → jam)
    int totalMenit = (jamKeluarJam * 60 + menitKeluar) - (jamMasuk * 60 + menitMasuk);

    int durasiJam;
    if (totalMenit % 60 == 0)
        durasiJam = totalMenit / 60;
    else
        durasiJam = totalMenit / 60 + 1;

    // Tentukan jenis kendaraan & tarif
    string jenisKendaraan;
    int tarifAwal = 0, tarifBerikutnya = 0;

    if (jenisKode == "10") {
        jenisKendaraan = "Mobil";
        tarifAwal = 5000;
        tarifBerikutnya = 3000;
    }
    else if (jenisKode == "20") {
        jenisKendaraan = "Motor";
        tarifAwal = 3000;
        tarifBerikutnya = 2000;
    }
    else if (jenisKode == "30") {
        jenisKendaraan = "Bus";
        tarifAwal = 10000;
        tarifBerikutnya = 7000;
    }
    else {
        cout << "Kode kendaraan tidak valid.";
        return 0;
    }

    // Hitung biaya
    int totalBiaya = tarifAwal;
    if (durasiJam > 1)
        totalBiaya += (durasiJam - 1) * tarifBerikutnya;

    // Output sesuai format soal
    cout << "Jenis kendaraan: " << jenisKendaraan << endl;

    cout << "Waktu masuk: ";
    if (jamMasuk < 10) cout << "0";
    cout << jamMasuk << ":";
    if (menitMasuk < 10) cout << "0";
    cout << menitMasuk << endl;

    cout << "Waktu keluar: ";
    if (jamKeluarJam < 10) cout << "0";
    cout << jamKeluarJam << ":";
    if (menitKeluar < 10) cout << "0";
    cout << menitKeluar << endl;

    cout << "Durasi parkir: " << durasiJam << " jam" << endl;
    cout << "Lokasi parkir: " << lokasi << endl;
    cout << "Total biaya: Rp " << totalBiaya << endl;

    return 0;
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
