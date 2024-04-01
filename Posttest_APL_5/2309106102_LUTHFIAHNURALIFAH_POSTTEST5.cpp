#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
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

// Struktur untuk data siswa
struct Siswa {
    string nama;
    string usia;
    string kelas;
};

// Maksimum jumlah siswa
const int MAX_SISWA = 10;

// Array untuk menyimpan data siswa
Siswa dataSiswa[MAX_SISWA];
int jumlahSiswa = 0;

// Array pointer untuk menyimpan data siswa
Siswa *pointerDataSiswa = dataSiswa;
int *pointerJumlahSiswa = &jumlahSiswa;

void tambahSiswa() {
    system("cls");
    if (jumlahSiswa < MAX_SISWA) {
        cout << "Masukkan nama siswa: ";
        cin.ignore(); // Membersihkan buffer
        getline(cin, pointerDataSiswa[jumlahSiswa].nama); 
        cout << "Masukkan usia siswa : ";
        getline(cin, pointerDataSiswa[jumlahSiswa].usia);
        cout << "Daftar Kelas :\n";
        cout << "[1] TK Dini\n";
        cout << "[2] TK A\n";
        cout << "[3] TK B\n";
        cout << "Pilih kelas (1/2/3) : ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pointerDataSiswa[jumlahSiswa].kelas = "TK Dini";
                break;
            case 2:
                pointerDataSiswa[jumlahSiswa].kelas = "TK A";
                break;
            case 3:
                pointerDataSiswa[jumlahSiswa].kelas = "TK B";
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
    system("pause");
    system("cls");
}

// Prosedur untuk menampilkan data siswa
void tampilkanSiswa() {
    system("cls");
    cout << "Data Siswa:" << endl;
    for (int i = 0; i < jumlahSiswa; ++i) {
        cout << i + 1 << ". Nama: " << pointerDataSiswa[i].nama << endl;
        cout << "   Usia: " << pointerDataSiswa[i].usia << endl;
        cout << "   Kelas: " << pointerDataSiswa[i].kelas << endl;
    }
    system("pause");
    system("cls");
}

// Prosedur untuk mengedit data siswa
void editSiswa() {
    system("cls");
    tampilkanSiswa();
    cout << "Masukkan nomor siswa yang ingin diedit: ";
    int pilihan;
    cin >> pilihan;
    if (pilihan >= 1 && pilihan <= jumlahSiswa) {
        cout << "Data Siswa yang akan diedit:" << endl;
        cout << "Nama: " << dataSiswa[pilihan - 1].nama << endl;
        cout << "Usia: " << dataSiswa[pilihan - 1].usia << endl;
        cout << "Kelas: " << dataSiswa[pilihan - 1].kelas << endl;

        cout << "Masukkan usia baru: ";
        cin.ignore();
        getline(cin, dataSiswa[pilihan - 1].usia);
        cout << "Data siswa berhasil diubah." << endl;
    } else {
        cout << "Nomor siswa tidak valid." << endl;
    }
    system("pause");
    system("cls");
}

// Fungsi untuk menghapus data siswa
void hapusSiswa() {
    system("cls");
    tampilkanSiswa();
    cout << "Masukkan nomor siswa yang ingin dihapus: ";
    int pilihan;
    cin >> pilihan;
    if (pilihan >= 1 && pilihan <= jumlahSiswa) {
        cout << "Data Siswa yang akan dihapus:" << endl;
        cout << "Nama: " << dataSiswa[pilihan - 1].nama << endl;
        cout << "Usia: " << dataSiswa[pilihan - 1].usia << endl;
        cout << "Kelas: " << dataSiswa[pilihan - 1].kelas << endl;

        for (int i = pilihan - 1; i < jumlahSiswa - 1; ++i) {
            dataSiswa[i] = dataSiswa[i + 1];
        }
        jumlahSiswa--;
        cout << "Data siswa berhasil dihapus." << endl;
    } else {
        cout << "Nomor siswa tidak valid." << endl;
    }
    system("pause");
    system("cls");
}

// Fungsi untuk memeriksa apakah input merupakan angka
bool isNumber(const string& input) {
    for (char digit : input) {
        if (!isdigit(digit)) {
            return false;
        }
    }
    return true;
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

    // Looping program
    bool berulang = true;
    while (berulang) {

        // Tampilkan menu
        tampilkanMenu();

        // Baca pilihan menu dari user
        string input;
        cin >> input;

        // Memeriksa apakah input merupakan angka
        if (!isNumber(input)) {
            cout << "Masukkan sesuai opsi yang ada." << endl;
            // Membersihkan input stream
            cin.clear();
            // Mengabaikan karakter yang tersisa dalam input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Mengonversi input menjadi integer
        int pilihan = stoi(input);

        // Proses dari pilihan menu
        switch (pilihan) {
            case 1:
                tambahSiswa();
                break;
            case 2:
                tampilkanSiswa();
                break;
            case 3:
                editSiswa();
                break;
            case 4:
                hapusSiswa();
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
