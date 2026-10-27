#include <iostream>
#include <string>
using namespace std;

void tampilkanKata(string kata[], int n) {
    for (int i = 0; i < n; i++) {
        cout << kata[i] << "  ";
    }
    cout << endl;
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah kata: ";
    cin >> jumlah;
    
    string kata[jumlah];
    cout << "Masukkan " << jumlah << " kata:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Kata ke-" << i+1 << ": ";
        cin >> kata[i];
    }
    
    cout << "\nData awal:  ";
    tampilkanKata(kata, jumlah);
    cout << "\n";
    
    for (int i = 1; i < jumlah; i++) {
        string key = kata[i];
        int j = i - 1;
        
        cout << "Langkah " << i << ": Ambil \"" << key << "\"\n";
        
        while (j >= 0 && kata[j] > key) {
            cout << "  Geser \"" << kata[j] << "\" ke kanan\n";
            kata[j + 1] = kata[j];
            j--;
        }
        
        kata[j + 1] = key;
        cout << "  Taruh \"" << key << "\" di posisi " << (j + 1) << endl;
        cout << "  Hasil: ";
        tampilkanKata(kata, jumlah);
        cout << endl;
    }
    
    cout << "Hasil akhir: ";
    tampilkanKata(kata, jumlah);
    
    return 0;
}