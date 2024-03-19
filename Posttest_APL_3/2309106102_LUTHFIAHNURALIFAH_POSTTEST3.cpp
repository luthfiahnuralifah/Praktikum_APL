#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Fungsi untuk login
bool login() {
    system("cls");
    string nama, usia;
    int salah = 0;
    const int maksimal = 3;

    while (salah < maksimal) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> usia;

        system("cls");
        if (nama == "Luthfiah" && usia == "2309106102") {
            cout << "Login berhasil!" << endl;
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi." << endl;
            salah++;
        }
    }

    cout << "Anda sudah mencoba login sebanyak " << maksimal << " kali. Anda keluar dari program." << endl;
    return false;
} 

// Maksimum jumlah siswa
const int MAX_SISWA = 10;

// Struktur untuk data siswa
struct Siswa {
    string nama;
    string usia;
    int kelas;
};

// Perosedur untuk menambah data siswa
void tambahSiswa(Siswa siswa[], int& jumlahSiswa) {
    system("cls");
    if (jumlahSiswa < MAX_SISWA) {
        cout << "Masukkan nama siswa: " ;
        cin.ignore(); // Membersihkan buffer
        getline(cin, siswa[jumlahSiswa].nama); 
        cout << "Masukkan usia siswa : " ;
        getline(cin, siswa[jumlahSiswa].usia);
        cout << "Daftar Kelas :" << endl;
        cout << "[1] TK Dini" << endl; 
        cout << "[2] TK A" << endl;
        cout << "[3] TK B" << endl;
        cout << "Pilih kelas (1/2/3) : " ;

        int pilihan;
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1:
                siswa[jumlahSiswa].kelas = 1;
                break;
            case 2:
                siswa[jumlahSiswa].kelas = 2;
                break;
            case 3:
                siswa[jumlahSiswa].kelas = 3;
                break;
            default:
                cout << "Pilihan tidak valid.";
                return; 
        }

        jumlahSiswa++;
        cout << "Data siswa berhasil ditambahkan." << endl;
    } else {
        cout << "Maaf, kapasitas kelas penuh." << endl;
    }
    cout << "Ingin menambah siswa lagi? (y/n): ";
    char ulang;
    cin >> ulang;
    if (ulang == 'y') {
        tambahSiswa(siswa, jumlahSiswa); // Letak Rekursif
    } system("cls");
}

// Prosedur untuk menampilkan data siswa
void tampilkanSiswa(const Siswa siswa[], int jumlahSiswa) {
    system("cls");
    cout << "Data Siswa:" << endl;
    for (int i = 0; i < jumlahSiswa; ++i) {
        cout << i + 1 << ". Nama: " << siswa[ i].nama << endl;
        cout << "   Usia: " << siswa[i].usia << endl;
        cout << "   Kelas: ";
        switch (siswa[i].kelas) {
            case 1:
                cout << "TK Dini";
                break;
            case 2:
                cout << "TK A";
                break;
            case 3:
                cout << "TK B";
                break;
        }
        cout << endl;
    }
}

// Prosedur untuk mengedit data siswa
void editSiswa(Siswa siswa[], int jumlahSiswa) {
    system("cls");
    tampilkanSiswa(siswa, jumlahSiswa);
    cout << "Masukkan nama siswa yang ingin diedit: " << endl;
    string nama;
    cin.ignore(); 
    getline(cin, nama);

    bool ditemukan = false;
    for (int i = 0; i < jumlahSiswa; ++i) {
        if (siswa[i].nama == nama) {
            cout << "Masukkan usia baru: ";
            getline(cin, siswa[i].usia);
            cout << "Daftar Kelas :" << endl;
            cout << "[1] TK Dini" << endl;
            cout << "[2] TK A" << endl;
            cout << "[3] TK B" << endl;
            cout << "Pilih kelas baru (1/2/3) : ";
            int pilihan;
            cin >> pilihan;
            cin.ignore(); // Membersihkan buffer
            switch (pilihan) {
                case 1:
                    siswa[i].kelas = 1;
                    break;
                case 2:
                    siswa[i].kelas = 2;
                    break;
                case 3:
                    siswa[i].kelas = 3;
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    return; // Keluar dari fungsi jika pilihan tidak valid
            }
            cout << "Data siswa berhasil diubah." << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data siswa tidak ditemukan." <<endl;
    }
}

// Fungsi untuk menghapus data siswa
bool hapusSiswa(Siswa siswa[], int& jumlahSiswa) {
    system("cls");
    tampilkanSiswa(siswa, jumlahSiswa);
    cout << "Masukkan nama siswa yang ingin dihapus: " << endl;
    string nama;
    cin.ignore(); 
    getline(cin, nama);

    bool ditemukan = false;
    for (int i = 0; i < jumlahSiswa; ++i) {
        if (siswa[i].nama == nama) {
            for (int j = i; j < jumlahSiswa - 1; ++j) {
                siswa[j] = siswa[j + 1];
            }
            jumlahSiswa--;
            cout << "Data siswa berhasil dihapus." << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data siswa tidak ditemukan." << endl;
    }
    
    return ditemukan; // Mengembalikan true jika data ditemukan dan berhasil dihapus, false jika tidak ditemukan
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << " _____________________________________" << endl;
    cout << "|                Menu                 |" << endl;
    cout << "|-------------------------------------|" << endl;
    cout << "| [1] Tambah data siswa               |" << endl;
    cout << "| [2] Tampilkan data siswa            |" << endl;
    cout << "| [3] Edit data siswa                 |" << endl;
    cout << "| [4] Hapus data siswa                |" << endl;
    cout << "| [5] Keluar                          |" << endl;
    cout << "|_____________________________________|" << endl;
    cout << "Pilih menu (1/2/3/4/5): ";
}

// Fungsi utama
int main() {
    // Memanggil fungsi login untuk melakukan autentikasi pengguna
    if (!login()) {
        // Jika login gagal, keluar dari program
        return 0;
    }

    // Array untuk menyimpan data siswa
    Siswa dataSiswa[MAX_SISWA];
    int jumlahSiswa = 0;

    // Looping program
    bool berulang = true;
    while (berulang) {

        // Tampilkan menu
        tampilkanMenu();

        // Baca pilihan menu dari user
        int pilihan;
        cin >> pilihan;

        // Proses dari pilihan menu
        switch (pilihan) {
            case 1:
                tambahSiswa(dataSiswa, jumlahSiswa);
                break;
            case 2:
                tampilkanSiswa(dataSiswa, jumlahSiswa);
                break;
            case 3:
                editSiswa(dataSiswa, jumlahSiswa);
                break;
            case 4:
                hapusSiswa(dataSiswa, jumlahSiswa);
                break;
            case 5:
                berulang = false; 
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
    }
    return 0;
}
