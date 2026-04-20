#include <iostream>
#include <string>
using namespace std;

int main() {
    string kartu;
    cout << "Masukkan nomor kartu digital: ";
    cin >> kartu;

    int panjang = kartu.length();
    string tipe = "";
    bool validJenis = false;

    if (panjang == 14 && kartu.substr(0,2) == "65") {
        tipe = "NUSANTARA";
        validJenis = true;
    }
    else if (panjang == 16 && (kartu.substr(0,2) == "77" || kartu.substr(0,2) == "78")) {
        tipe = "GARUDA";
        validJenis = true;
    }
    else if (panjang == 15 && kartu.substr(0,2) == "91") {
        tipe = "MERDEKA";
        validJenis = true;
    }

    if (!validJenis) {
        cout << "Tipe kartu: TIDAK DIKENALI\n";
        cout << "Nomor kartu TIDAK VALID.";
        return 0;
    }

    cout << "Tipe kartu: " << tipe << endl;

    int total = 0;
    bool kali2 = true;

    for (int i = panjang - 2; i >= 0; i--) {
        int digit = kartu[i] - '0';

        if (kali2) {
            digit *= 2;
            if (digit > 9)
                digit = digit - 9; 
        }

        total += digit;
        kali2 = !kali2;
    }

    total += kartu[panjang - 1] - '0';

    if (total % 10 == 0)
        cout << "Nomor kartu VALID.";
    else
        cout << "Nomor kartu TIDAK VALID.";

    return 0;
}

/*
ALGORITMA VALIDASI KARTU DIGITAL:

1. Input nomor kartu dalam bentuk string.
2. Hitung panjang kartu.
3. Cek jenis kartu:
   - Jika panjang 14 dan awalan "65" → NUSANTARA
   - Jika panjang 16 dan awalan "77" atau "78" → GARUDA
   - Jika panjang 15 dan awalan "91" → MERDEKA
   - Jika tidak sesuai → kartu tidak valid.

4. Jika jenis valid, lakukan algoritma validasi:
   a. Mulai dari digit kedua dari belakang.
   b. Kalikan setiap digit selang-seling dengan 2.
   c. Jika hasil > 9, jumlahkan digitnya.
   d. Jumlahkan semua digit hasil proses.
   e. Tambahkan digit yang tidak dikali.

5. Hitung total keseluruhan.
6. Jika total % 10 == 0 → kartu VALID.
7. Jika tidak → kartu TIDAK VALID.
*/
