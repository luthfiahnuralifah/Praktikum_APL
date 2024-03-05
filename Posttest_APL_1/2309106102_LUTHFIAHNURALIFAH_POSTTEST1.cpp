#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Fungsi untuk login
bool login() {
    string nama, nim;
    int salah = 0;
    const int maksimal = 3;

    while (salah < maksimal) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "Luthfiah" && nim == "2309106102") {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            salah++;
        }
    }

    cout << "anda sudah mencoba login sebanyak " << maksimal << " kali. anda keluar dari program.\n";
    return false;
}


void konversiSuhu() {
    double suhuAwal, suhuAkhir;
    int pilihanAwal, pilihanAkhir;

    while (true) {
        cout << "\nMenu Konversi Suhu:\n";
        cout << "[1] Konversi Celcius\n";
        cout << "[2] Konversi Reamur\n";
        cout << "[3] Konversi Fahrenheit\n";
        cout << "[4] Konversi Kelvin\n";
        cout << "[0] Keluar\n";
        cout << "Pilih opsi yang ingin dikonversi (1/2/3/4/0): ";
        cin >> pilihanAwal;

        if (pilihanAwal == 0)
            break;

        cout << "Masukkan suhu: ";
        cin >> suhuAwal;

        cout << "Pilih tujuan konversi (1/2/3/4): ";
        cin >> pilihanAkhir;

        switch (pilihanAwal) {
            case 1: 
                switch (pilihanAkhir) {
                    case 1:
                        suhuAkhir = suhuAwal;
                        break;
                    case 2:
                        suhuAkhir = (4.0/5.0) * suhuAwal;
                        break;
                    case 3:
                        suhuAkhir = (9.0/5.0) * suhuAwal + 32;
                        break;
                    case 4:
                        suhuAkhir = suhuAwal + 273.15;
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                        continue;
                }
                break;
            case 2: 
                switch (pilihanAkhir) {
                    case 1:
                        suhuAkhir = (5.0/4.0) * suhuAwal;
                        break;
                    case 2:
                        suhuAkhir = suhuAwal;
                        break;
                    case 3:
                        suhuAkhir = (9.0/4.0) * suhuAwal + 32;
                        break;
                    case 4:
                        suhuAkhir = (5.0/4.0) * suhuAwal + 273.15;
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                        continue;
                }
                break;
            case 3: 
                switch (pilihanAkhir) {
                    case 1:
                        suhuAkhir = (5.0/9.0) * (suhuAwal - 32);
                        break;
                    case 2:
                        suhuAkhir = (4.0/9.0) * (suhuAwal - 32);
                        break;
                    case 3:
                        suhuAkhir = suhuAwal;
                        break;
                    case 4:
                        suhuAkhir = (5.0/9.0) * (suhuAwal - 32) + 273.15;
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                        continue;
                }
                break;
            case 4: 
                switch (pilihanAkhir) {
                    case 1:
                        suhuAkhir = suhuAwal - 273.15;
                        break;
                    case 2:
                        suhuAkhir = (4.0/5.0) * (suhuAwal - 273.15);
                        break;
                    case 3:
                        suhuAkhir = (9.0/5.0) * (suhuAwal - 273.15) + 32;
                        break;
                    case 4:
                        suhuAkhir = suhuAwal;
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                        continue;
                }
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                continue;
        }

        cout << fixed << setprecision(2);
        cout << "Hasil konversi: " << suhuAkhir << endl;
    }
}

int main() {
    if (!login()) {
        return 0;
    }

    konversiSuhu();

    return 0;
}
