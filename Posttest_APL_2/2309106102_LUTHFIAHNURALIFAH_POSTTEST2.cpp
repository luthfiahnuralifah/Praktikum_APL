#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk login
bool login() {
    string nama, usia;
    int salah = 0;
    const int maksimal = 3;

    while (salah < maksimal) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> usia;

        if (nama == "Luthfiah" && usia == "2309106102") {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            salah++;
        }
    }

    cout << "Anda sudah mencoba login sebanyak " << maksimal << " kali. Anda keluar dari program.\n";
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

// Fungsi untuk menambah data siswa
void tambahSiswa(Siswa siswa[], int& jumlahSiswa) {
    if (jumlahSiswa < MAX_SISWA) {
        cout << "Masukkan nama siswa: ";
        cin.ignore(); // Membersihkan buffer
        getline(cin, siswa[jumlahSiswa].nama); // Menggunakan getline untuk membaca nama
        cout << "Masukkan usia siswa : ";
        getline(cin, siswa[jumlahSiswa].usia);
        cout << "Daftar Kelas :\n";
        cout << "[1] TK Dini\n";
        cout << "[2] TK A\n";
        cout << "[3] TK B\n";
        cout << "Pilih kelas (1/2/3) : ";

        int pilihan;
        cin >> pilihan;

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
                cout << "Pilihan tidak valid.\n";
                return; 
        }

        jumlahSiswa++;
        cout << "Data siswa berhasil ditambahkan.\n";
    } else {
        cout << "Maaf, kapasitas kelas penuh.\n";
    }
}

// Fungsi untuk menampilkan data siswa
void tampilkanSiswa(const Siswa siswa[], int jumlahSiswa) {
    cout << "Data Siswa:\n";
    for (int i = 0; i < jumlahSiswa; ++i) {
        cout << i + 1 << ". Nama: " << siswa[i].nama << endl;
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

// Fungsi untuk mengedit data siswa
void editSiswa(Siswa siswa[], int jumlahSiswa) {
    tampilkanSiswa(siswa, jumlahSiswa);
    cout << "Masukkan nama siswa yang ingin diedit: ";
    string nama;
    cin.ignore(); 
    getline(cin, nama);

    bool ditemukan = false;
    for (int i = 0; i < jumlahSiswa; ++i) {
        if (siswa[i].nama == nama) {
            cout << "Masukkan usia baru: ";
            getline(cin, siswa[i].usia);
            cout << "Daftar Kelas :\n";
            cout << "[1] TK Dini\n";
            cout << "[2] TK A\n";
            cout << "[3] TK B\n";
            cout << "Pilih kelas baru (1/2/3) : ";
            int pilihan;
            cin >> pilihan;
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
                    cout << "Pilihan tidak valid.\n";
                    return; // Keluar dari fungsi jika pilihan tidak valid
            }
            cout << "Data siswa berhasil diubah.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data siswa tidak ditemukan.\n";
    }
}

// Fungsi untuk menghapus data siswa
void hapusSiswa(Siswa siswa[], int& jumlahSiswa) {
    tampilkanSiswa(siswa, jumlahSiswa);
    cout << "Masukkan nama siswa yang ingin dihapus: ";
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
            cout << "Data siswa berhasil dihapus.\n";
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data siswa tidak ditemukan.\n";
    }
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << " _____________________________________\n";
    cout << "|                Menu                 |\n";
    cout << "|-------------------------------------|\n";
    cout << "| [1] Tambah data siswa               |\n";
    cout << "| [2] Tampilkan data siswa            |\n";
    cout << "| [3] Edit data siswa                 |\n";
    cout << "| [4] Hapus data siswa                |\n";
    cout << "| [5] Keluar                          |\n";
    cout << "|_____________________________________|\n";
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
                cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai.\n";
        }
    }
    return 0;
}