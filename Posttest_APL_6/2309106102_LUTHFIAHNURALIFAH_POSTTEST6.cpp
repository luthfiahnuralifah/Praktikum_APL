#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
using namespace std;

// Fungsi untuk login
bool login() {
    system("cls");
    string nama, nim;
    int salah = 0;
    const int maksimal = 3;

    while (salah < maksimal) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        system("cls");
        if (nama == "Luthfiah" && nim == "2309106102") {
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

// Fungsi untuk menampilkan data siswa
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

// Fungsi5 untuk mengedit data siswa
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
    cout << "| [5] Sort data siswa                 |" << endl;
    cout << "| [6] Search data siswa               |" << endl;
    cout << "| [7] Keluar                          |" << endl;
    cout << "|_____________________________________|" << endl;
    cout << "Pilih menu (1/2/3/4/5/6/7): ";
}

// Fungsi untuk mengurutkan huruf secara descending
void sortHurufDescending() {
    for (int i = 0; i < jumlahSiswa - 1; ++i) {
        int max_index = i;
        for (int j = i + 1; j < jumlahSiswa; ++j) {
            if (pointerDataSiswa[j].nama > pointerDataSiswa[max_index].nama) {
                max_index = j;
            }
        }
        if (max_index != i) {
            swap(pointerDataSiswa[i], pointerDataSiswa[max_index]);
        }
    }
}

// Quick sort untuk mengurutkan data angka secara ascending
int partition(int low, int high); // Deklarasi prototipe fungsi partition
void quickSort(int low, int high);

int partition(int low, int high) {
    string pivot = pointerDataSiswa[high].usia;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (pointerDataSiswa[j].usia < pivot) {
            ++i;
            swap(pointerDataSiswa[i], pointerDataSiswa[j]);
        }
    }
    swap(pointerDataSiswa[i + 1], pointerDataSiswa[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
}

// Bubble sort untuk mengurutkan data angka secara ascending
void bubbleSort() {
    for (int i = 0; i < jumlahSiswa - 1; ++i) {
        for (int j = 0; j < jumlahSiswa - i - 1; ++j) {
            if (pointerDataSiswa[j].usia > pointerDataSiswa[j + 1].usia) {
                swap(pointerDataSiswa[j], pointerDataSiswa[j + 1]);
            }
        }
    }
}

// Binary search untuk mencari data pada kumpulan data yang terurut secara ascending
int binarySearchAscending(const string& target) {
    int low = 0;
    int high = jumlahSiswa - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (pointerDataSiswa[mid].usia == target) {
            return mid;
        } else if (pointerDataSiswa[mid].usia < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Binary search untuk mencari data pada kumpulan data yang terurut secara descending
int binarySearchDescending(const string& target) {
    int low = 0;
    int high = jumlahSiswa - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (pointerDataSiswa[mid].usia == target) {
            return mid;
        } else if (pointerDataSiswa[mid].usia > target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Fungsi utama
int main() {
    // Memanggil fungsi login untuk melakukan autentikasi pengguna
    if (!login()) {
        // Jika login gagal, keluar dari program
        return 0;
    }

    int searchingOption;

    // Looping program
    while (true) {
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

        //deklarasi variabel
        string target; 
        int sortingOption = -1; // Menginisialisasi sortingOption dengan nilai default
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
                // Pemanggilan fungsi sorting
                cout << "Pilih metode sorting:" << endl;
                cout << "1. Sorting huruf descending" << endl;
                cout << "2. Sorting angka ascending" << endl;
                cout << "3. Bubble sort" << endl;
                cout << "Pilihan (1/2/3): ";
                cin >> input;
                if (!isNumber(input)) {
                    cout << "Masukkan sesuai opsi yang ada." << endl;
                    break;
                }
                sortingOption = stoi(input);
                switch (sortingOption) {
                    case 1:
                        sortHurufDescending();
                        cout << "Sorting huruf descending berhasil dilakukan." << endl;
                        break;
                    case 2:
                        quickSort(0, jumlahSiswa - 1);
                        cout << "Sorting angka ascending berhasil dilakukan." << endl;
                        break;
                    case 3:
                        bubbleSort();
                        cout << "Bubble sort berhasil dilakukan." << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 6:
                // Pemanggilan fungsi searching
                cout << "Pilih metode searching:" << endl;
                cout << "1. Binary search ascending" << endl;
                cout << "2. Binary search descending" << endl;
                cout << "Pilihan (1/2): ";
                cin >> input;
                if (!isNumber(input)) {
                    cout << "Masukkan sesuai opsi yang ada." << endl;
                    break;
                }
                searchingOption = stoi(input); // Perbarui nilai searchingOption
                cout << "Masukkan usia yang ingin dicari: ";
                cin >> target;
                switch (searchingOption) { // Gunakan searchingOption yang sudah diperbarui
                    case 1: {
                        int result = binarySearchAscending(target);
                        if (result != -1) {
                            cout << "Data ditemukan pada indeks " << result << endl;
                        } else {
                            cout << "Data tidak ditemukan." << endl;
                        }
                        break;
                    }
                    case 2: {
                        int result = binarySearchDescending(target);
                        if (result != 1) {
                            cout << "Data ditemukan " << endl;
                        } else {
                            cout << "Data tidak ditemukan." << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;  
            case 7:
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
                return 0; // Keluar dari program saat opsi keluar dipilih
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
    }
    
    return 0;
}