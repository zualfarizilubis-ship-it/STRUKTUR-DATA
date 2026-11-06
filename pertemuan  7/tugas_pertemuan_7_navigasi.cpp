#include <iostream>
using namespace std;

int main() {
    int graph[6][6] = {
        {0, 1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {2, 3, 4, 5, 6, 7},
        {3, 4, 5, 6, 7, 7},
        {4, 5, 6, 7, 8, 9},
        {5, 6, 7, 8, 9, 0}
    };

    int jarak[6];
    int parent[6];
    bool sudah[6] = {false};

    for (int i = 0; i < 6; i++) {
        jarak[i] = 999;
        parent[i] = -1;
    }

    jarak[0] = 0;

    for (int i = 0; i < 6; i++) {
        int min = 999;
        int posisi = -1;

        for (int j = 0; j < 6; j++) {
            if (!sudah[j] && jarak[j] < min) {
                min = jarak[j];
                posisi = j;
            }
        }

        if (posisi == -1) {
            break;
        }

        sudah[posisi] = true;

        for (int j = 0; j < 6; j++) {
            if (graph[posisi][j] != 999 && !sudah[j]) {
                if (jarak[posisi] + graph[posisi][j] < jarak[j]) {
                    jarak[j] = jarak[posisi] + graph[posisi][j];
                    parent[j] = posisi;
                }
            }
        }
    }

    cout << "Jarak terpendek dari A:\n";

    for (int i = 0; i < 6; i++) {
        int rute[6];
        int n = 0;
        int temp = i;

        while (temp != -1) {
            rute[n] = temp;
            n++;
            temp = parent[temp];
        }

        cout << "A ke " << char(i + 'A') << " : ";

        for (int j = n - 1; j >= 0; j--) {
            cout << char(rute[j] + 'A');

            if (j > 0) {
                cout << " -> ";
            }
        }

        cout << " = " << jarak[i] << " km" << endl;
    }

    char asal, tujuan;

    cout << "\nMasukkan lokasi awal: ";
    cin >> asal;

    cout << "Masukkan lokasi tujuan: ";
    cin >> tujuan;

    int start = asal - 'A';
    int akhir = tujuan - 'A';

    // Menghitung ulang dari lokasi awal
    for (int i = 0; i < 6; i++) {
        jarak[i] = 999;
        parent[i] = -1;
        sudah[i] = false;
    }

    jarak[start] = 0;

    for (int i = 0; i < 6; i++) {
        int min = 999;
        int posisi = -1;

        for (int j = 0; j < 6; j++) {
            if (!sudah[j] && jarak[j] < min) {
                min = jarak[j];
                posisi = j;
            }
        }

        if (posisi == -1) {
            break;
        }

        sudah[posisi] = true;

        for (int j = 0; j < 6; j++) {
            if (graph[posisi][j] != 999 && !sudah[j]) {
                if (jarak[posisi] + graph[posisi][j] < jarak[j]) {
                    jarak[j] = jarak[posisi] + graph[posisi][j];
                    parent[j] = posisi;
                }
            }
        }
    }

    cout << "\nRute terpendek: ";

    if (jarak[akhir] == 999) {
        cout << "Tidak ditemukan";
    } else {
        int rute[6];
        int n = 0;
        int temp = akhir;

        while (temp != -1) {
            rute[n] = temp;
            n++;
            temp = parent[temp];
        }

        for (int i = n - 1; i >= 0; i--) {
            cout << char(rute[i] + 'A');

            if (i > 0) {
                cout << " -> ";
            }
        }

        cout << "\nTotal jarak: " << jarak[akhir] << " km";
    }

    return 0;
}