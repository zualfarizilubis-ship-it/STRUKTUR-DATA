#include <iostream>
#include <string>
using namespace std;

enum Status { KOSONG, TERISI, TERHAPUS };

struct Mahasiswa {
    int nim;
    string nama;
    Status status;
};

const int UKURAN = 10;
Mahasiswa hashTable[UKURAN];

int hash1(int nim) {
    return nim % UKURAN;
}

int hash2(int nim) {
    return 7 - (nim % 7);
}

void insert(int nim, string nama) {
    int i = 0;
    int index;
    do {
        index = (hash1(nim) + i * hash2(nim)) % UKURAN;
        if (hashTable[index].status == KOSONG || hashTable[index].status == TERHAPUS) {
            hashTable[index].nim = nim;
            hashTable[index].nama = nama;
            hashTable[index].status = TERISI;
            cout << "Data NIM " << nim << " dimasukkan ke indeks " << index << endl;
            return;
        }
        i++;
    } while (i < UKURAN);
    cout << "Hash Table Penuh! Tidak bisa insert NIM " << nim << endl;
}

void search(int nim) {
    int i = 0;
    int index;
    do {
        index = (hash1(nim) + i * hash2(nim)) % UKURAN;
        if (hashTable[index].status == TERISI && hashTable[index].nim == nim) {
            cout << "Ditemukan! Indeks " << index << " | NIM: " << hashTable[index].nim << " | Nama: " << hashTable[index].nama << endl;
            return;
        }
        if (hashTable[index].status == KOSONG) break;
        i++;
    } while (i < UKURAN);
    cout << "NIM " << nim << " TIDAK DITEMUKAN di Hash Table" << endl;
}

void removeData(int nim) {
    int i = 0;
    int index;
    do {
        index = (hash1(nim) + i * hash2(nim)) % UKURAN;
        if (hashTable[index].status == TERISI && hashTable[index].nim == nim) {
            hashTable[index].status = TERHAPUS;
            cout << "Data NIM " << nim << " dihapus dari indeks " << index << endl;
            return;
        }
        if (hashTable[index].status == KOSONG) break;
        i++;
    } while (i < UKURAN);
    cout << "Gagal hapus: NIM " << nim << " tidak ada" << endl;
}

void tampilHashTable() {
    cout << "\nISI HASH TABLE (UKURAN 10)" << endl;
    for (int i = 0; i < UKURAN; i++) {
        cout << "Indeks " << i << " : ";
        if (hashTable[i].status == TERISI) {
            cout << "NIM = " << hashTable[i].nim << " | Nama = " << hashTable[i].nama;
        }
        else if (hashTable[i].status == TERHAPUS) {
            cout << "[SUDAH DIHAPUS]";
        }
        else {
            cout << "[KOSONG]";
        }
        cout << endl;
    }
    cout << endl;
}

void inisialisasi() {
    for(int i=0; i<UKURAN; i++){
        hashTable[i].status = KOSONG;
    }
}

int main() {
    inisialisasi();

    insert(251401, "Alfarizi");
    insert(251402, "Budi");
    insert(251403, "Citra");

    search(251402);

    removeData(251403);

    tampilHashTable();

    return 0;
}