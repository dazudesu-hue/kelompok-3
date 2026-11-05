//
// Created by HP on 29/10/2026.
//
#include <iostream>
#include <iomanip>  
#include <thread>   
#include <chrono>   
using namespace std;

int main() {
    int pilihan;
    int waktu_jam = 0;
    long harga = 0;
    long uang_bayar = 0;

    cout << "==================================\n";
    cout << "      SISTEM BILLING WARNET       \n";
    cout << "==================================\n";
    cout << "Daftar Paket Internet:\n";
    cout << "1. Paket 1 Jam  (Rp 5.000)\n";
    cout << "2. Paket 2 Jam  (Rp 10.000)\n";
    cout << "3. Paket 10 Jam (Rp 30.000)\n";
    cout << "==================================\n";
    cout << "Pilih paket (1-3): ";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            waktu_jam = 1;
            harga = 5000;
            break;
        case 2:
            waktu_jam = 2;
            harga = 10000;
            break;
        case 3:
            waktu_jam = 10;
            harga = 30000;
            break;
        default:
            cout << "Pilihan tidak valid! Program berhenti.\n";
            return 0;
    }

    cout << "\nTotal yang harus dibayar : Rp " << harga << endl;
    cout << "Masukkan nominal uang    : Rp ";
    cin >> uang_bayar;

    if (uang_bayar < harga) {
        cout << "Maaf, uang Anda tidak cukup! Transaksi dibatalkan.\n";
        return 0;
    }

    cout << "Kembalian Anda           : Rp " << uang_bayar - harga << endl;
    cout << "\nPembayaran berhasil! Tekan Enter untuk memulai billing...";
    cin.ignore();
    cin.get();

    int total_detik = waktu_jam * 3600;

    cout << "\n==================================\n";
    cout << "        BILLING BERJALAN          \n";
    cout << "==================================\n";

    while (total_detik >= 0) {
        int jam = total_detik / 3600;
        int menit = (total_detik % 3600) / 60;
        int detik = total_detik % 60;

        cout << "\rSisa Waktu Anda: " 
             << setfill('0') << setw(2) << jam << ":"
             << setfill('0') << setw(2) << menit << ":"
             << setfill('0') << setw(2) << detik << flush;

        this_thread::sleep_for(chrono::seconds(1));

        total_detik--;
    }

    cout << "\n\n==================================\n";
    cout << "          WAKTU HABIS!            \n";
    cout << " Komputer akan dikunci otomatis.  \n";
    cout << "==================================\n";

    return 0;
}

