#include <iostream>
using namespace std;

int main() {

    string nama;
    string password;
    string namaBenar = "afif";
    string passwordBenar = "047";

    int jumlahPercobaan = 0;
    int pilihanMenu;
    double nilaiWaktu;

    cout << "=== LOGIN ===" << endl;

    while (jumlahPercobaan < 3) {

        cout << "Nama : ";
        cin >> nama;

        cout << "Password : ";
        cin >> password;

        if (nama == namaBenar && password == passwordBenar) {
            cout << "Login berhasil!" << endl;
            break;
        } 
        else {
            jumlahPercobaan++;
            cout << "Salah! Percobaan ke "
                 << jumlahPercobaan << endl;

            if (jumlahPercobaan == 3) {
                cout << "3 kali salah, program berhenti." << endl;
                return 0;
            }
        }
    }

    while (true) {

        cout << endl;
        cout << "=== MENU KONVERSI WAKTU ===" << endl;
        cout << "1. Jam ke Menit dan Detik" << endl;
        cout << "2. Menit ke Jam dan Detik" << endl;
        cout << "3. Detik ke Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilihanMenu;

        if (pilihanMenu == 1) {

            cout << "Masukkan jumlah Jam : ";
            cin >> nilaiWaktu;

            double hasilMenit = nilaiWaktu * 60;
            double hasilDetik = nilaiWaktu * 3600;

            cout << nilaiWaktu << " Jam = "
                 << hasilMenit << " Menit atau "
                 << hasilDetik << " Detik" << endl;

        } 
        else if (pilihanMenu == 2) {

            cout << "Masukkan jumlah Menit : ";
            cin >> nilaiWaktu;

            double hasilJam = nilaiWaktu / 60;
            double hasilDetik = nilaiWaktu * 60;

            cout << nilaiWaktu << " Menit = "
                 << hasilJam << " Jam atau "
                 << hasilDetik << " Detik" << endl;

        } 
        else if (pilihanMenu == 3) {

            cout << "Masukkan jumlah Detik : ";
            cin >> nilaiWaktu;

            double hasilJam = nilaiWaktu / 3600;
            double hasilMenit = nilaiWaktu / 60;

            cout << nilaiWaktu << " Detik = "
                 << hasilJam << " Jam atau "
                 << hasilMenit << " Menit" << endl;

        } 
        else if (pilihanMenu == 4) {

            cout << "Keluar..." << endl;
            break;

        } 
        else {

            cout << "Pilihan salah, coba lagi." << endl;
        }
    }

    return 0;
}