#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
#define First(P) P.First
#define Info(P) P->Info
#define next(P) P->next

using namespace std;

typedef struct jadwalPenerbangan infotype;
typedef struct elemenJadwal *adr_JadwalP;

struct jadwalPenerbangan {
    string Kode, Jenis, Tanggal, Waktu, Asal, Tujuan;
    int Kapasitas;
};

struct elemenJadwal {
    infotype Info;
    adr_JadwalP next;
};

struct ListJadwal {
    adr_JadwalP First;
};

void createListJadwal_103032300055(ListJadwal &L);
adr_JadwalP createElemenJadwal_103032300055(infotype X);
void InsertLastJ_103032300055(ListJadwal &L, adr_JadwalP P);
void ShowJadwal_103032300055(ListJadwal L);
void DeleteFirstJ_103032300055(ListJadwal &L, adr_JadwalP &P);
adr_JadwalP SearchJ_103032300055(ListJadwal L, string dari, string ke, string tanggal);

#endif // FLIGHT_H_INCLUDED
