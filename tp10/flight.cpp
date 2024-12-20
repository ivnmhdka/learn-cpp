#include <iostream>
#include "flight.h"

using namespace std;

void createListJadwal_103032300055(ListJadwal &L) {
    First(L) = NULL;
}

adr_JadwalP createElemenJadwal_103032300055(infotype X) {
    adr_JadwalP P = new elemenJadwal;
    Info(P) = X;
    next(P) = NULL;
    return P;
}

void InsertLastJ_103032300055(ListJadwal &L, adr_JadwalP P) {
    if (First(L) == NULL) {
        First(L) = P;
    } else {
        adr_JadwalP Q = First(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void ShowJadwal_103032300055(ListJadwal L) {
    if (First(L) == NULL) {
        cout << "List Jadwal Kosong" << endl;
    } else {
        adr_JadwalP Q = First(L);
        int i = 0;
        while (Q != NULL) {
            cout << "Jadwal Penerbangan" << i+1 << endl;
            cout << endl;
            cout << "Kode: " << Info(Q).Kode << endl;
            cout << "Jenis: " << Info(Q).Jenis << endl;
            cout << "Tanggal: " << Info(Q).Tanggal << endl;
            cout << "Waktu: " << Info(Q).Waktu << endl;
            cout << "Asal: " << Info(Q).Asal << endl;
            cout << "Tujuan: " << Info(Q).Tujuan << endl;
            cout << "Kapasitas: " << Info(Q).Kapasitas << endl;
            cout << "-----------------------------" << endl;
            i++;
            Q = next(Q);
        }
    }
    cout << endl;
}

void DeleteFirstJ_103032300055(ListJadwal &L, adr_JadwalP &P) {
    if (First(L) == NULL) {
        cout << "List Jadwal Kosong" << endl;
    } else if (next(First(L)) == NULL) {
        First(L) = NULL;
    } else {
        P = First(L);
        First(L) = next(P);
        next(P) = NULL;
    }
}

adr_JadwalP SearchJ_103032300055(ListJadwal L, string dari, string ke, string tanggal) {
    if (First(L) == NULL) {
        cout << "List Jadwal Kosong" << endl;
        return NULL;
    } else {
        adr_JadwalP Q = First(L);
        while (Q != NULL && !(Info(Q).Asal == dari && Info(Q).Tujuan == ke && Info(Q).Tanggal == tanggal)) {
            Q = next(Q);
        }
        if (Q == NULL) {
            return NULL;
        } else {
            return Q;
        }
    }
}