#include <iostream>
#include <string>
#include "flight.h"

using namespace std;

int main() {
    ListJadwal L;
    int n;
    infotype X;
    adr_JadwalP jadwal;

    createListJadwal_103032300055(L);

    cout <<  "Masukkan Jumlah Jadwal Yang Ingin Dimasukkan Ke List: ";
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        cout << "Masukkan Data Jadwal Ke-" << i << endl;

        cout << "Kode: ";
        getline(cin, X.Kode);

        cout << "Jenis: ";
        getline(cin, X.Jenis);

        cout << "Tanggal (Format: DD MMMM YYYY): ";
        getline(cin, X.Tanggal);

        cout << "Waktu (Format: HH:MM): ";
        getline(cin, X.Waktu);

        cout << "Asal: ";
        getline(cin, X.Asal);

        cout << "Tujuan: ";
        getline(cin, X.Tujuan);

        cout << "Kapasitas: ";
        cin >> X.Kapasitas;
        cin.ignore();

        jadwal = createElemenJadwal_103032300055(X);
        InsertLastJ_103032300055(L, jadwal);
        cout << endl;
    }

    cout << "List Jadwal Setelah Dimasukkan Data: " << endl;
    ShowJadwal_103032300055(L);

    cout << "List Jadwal Setelah Dihapus Jadwal Urutan Pertama: " << endl;
    DeleteFirstJ_103032300055(L, jadwal);
    ShowJadwal_103032300055(L);

    cout << "Mencari Jadwal Penerbangan Dari Surabaya(SUB) ke Malang(MLG) Tanggal 9-Desember-2022" << endl;
    jadwal = SearchJ_103032300055(L, "Surabaya(SUB)", "Malang(MLG)", "9-Desember-2022");
    if (jadwal == NULL) {
        cout << "Jadwal Tidak Ditemukan Dalam List" << endl;
    } else {
        cout << "Jadwal Ditemukan" << endl;
        cout << "Kode: " << Info(jadwal).Kode << endl;
        cout << "Jenis: " << Info(jadwal).Jenis << endl;
        cout << "Tanggal: " << Info(jadwal).Tanggal << endl;
        cout << "Waktu: " << Info(jadwal).Waktu << endl;
        cout << "Asal: " << Info(jadwal).Asal << endl;
        cout << "Tujuan: " << Info(jadwal).Tujuan << endl;
        cout << "Kapasitas: " << Info(jadwal).Kapasitas << endl;
    }

    return 0;
}