#include <iostream>
#include <string>
using namespace std;

int main() {
    string kartu;
    cin >> kartu;

    int panjang = kartu.length();
    bool validJenis = false;

    // cek jenis kartu
    if (panjang == 14 && kartu.substr(0,2) == "65") validJenis = true;
    else if (panjang == 16 && (kartu.substr(0,2) == "77" || kartu.substr(0,2) == "78")) validJenis = true;
    else if (panjang == 15 && kartu.substr(0,2) == "91") validJenis = true;

    if (!validJenis) {
        cout << "Kartu tidak valid (jenis salah)";
        return 0;
    }

    int total = 0;
    bool kali2 = true;

    for (int i = panjang - 2; i >= 0; i--) {
        int digit = kartu[i] - '0';

        if (kali2) {
            digit *= 2;
            if (digit > 9) digit = digit/10 + digit%10;
        }

        total += digit;
        kali2 = !kali2;
    }

    total += kartu[panjang-1] - '0';

    if (total % 10 == 0)
        cout << "Kartu VALID";
    else
        cout << "Kartu TIDAK VALID";
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
