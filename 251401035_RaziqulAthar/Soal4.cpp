#include <iostream>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            poinA += 3;
            streakA++;
            streakB = 0;

            if (streakA == 3) {
                poinA += 2;
                streakA = 0;
            }
        }
        else if (S[i] == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0;

            if (streakB == 3) {
                poinB += 2;
                streakB = 0;
            }
        }
        else {
            poinA += 1;
            poinB += 1;
            streakA = streakB = 0;
        }
    }

    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    if (poinA > poinB)
        cout << "Pemenangnya adalah pemain A";
    else if (poinB > poinA)
        cout << "Pemenangnya adalah pemain B";
    else
        cout << "Hasil pertandingan Seri!";
}

/*
ALGORITMA PERTANDINGAN:

1. Input jumlah babak (N) dan string hasil (S).
2. Inisialisasi:
   - poinA = 0, poinB = 0
   - streakA = 0, streakB = 0

3. Ulangi untuk setiap karakter dalam S:
   a. Jika 'A':
      - poinA += 3
      - streakA++ dan reset streakB
      - Jika streakA == 3:
          poinA += 2 (bonus)
          reset streakA

   b. Jika 'B':
      - poinB += 3
      - streakB++ dan reset streakA
      - Jika streakB == 3:
          poinB += 2 (bonus)
          reset streakB

   c. Jika 'C':
      - poinA += 1 dan poinB += 1
      - reset streakA dan streakB

4. Setelah semua babak:
   - Bandingkan poinA dan poinB
   - Jika poinA > poinB → A menang
   - Jika poinB > poinA → B menang
   - Jika sama → seri

5. Tampilkan:
   - poin A
   - poin B
   - hasil pertandingan
*/
