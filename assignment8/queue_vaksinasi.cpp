#include <iostream>
#include "queue_vaksinasi.h"

using namespace std;

void createQueue_103032300055(Queue &Q) {
    head(Q) = NULL;
    tail(Q) = NULL;
}

bool isEmpty_103032300055(Queue Q) {
    return head(Q) == NULL;
}

ElemQ* createElemQueue_103032300055(string nama, int usia, string pekerjaan, int nomor_antrean, int waktu_daftar) {
    ElemQ *P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    info(P).waktu_daftar = waktu_daftar;
    next(P) = NULL;
    return P;
}

void enqueue_103032300055(Queue &Q, ElemQ *P) {
    if(isEmpty_103032300055(Q)) {
        head(Q) = P;
        tail(Q) = P;
    } else if (info(P).prioritas) {
        if(!info(head(Q)).prioritas) {
            next(P) = head(Q);
            head(Q) = P;
        } else {
            ElemQ *temp = head(Q);
            while (next(temp) != NULL && info(next(temp)).prioritas) {
                temp = next(temp);
            }
            next(P) = next(temp);
            next(temp) = P;
            if(next(P) == NULL) {
                tail(Q) = P;
            }
        }
    } else {
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void dequeue_103032300055(Queue &Q, ElemQ* &P) {
    if(isEmpty_103032300055(Q)) {
        P = NULL;
        cout << "Semua warga telah terlayani" << endl;
    } else {
        P = Q.head;
        Q.head = Q.head->next;
        if(Q.head == NULL) {
            Q.tail = NULL;
        }
        P->next = NULL;
    }
}

ElemQ* front_103032300055(Queue Q) {
    return head(Q);
}

ElemQ* back_103032300055(Queue Q) {
    return tail(Q);
}

int size_103032300055(Queue Q) {
    int count = 0;
    ElemQ *temp = head(Q);
    while (temp != NULL) {
        count++;
        temp = next(temp);
    }
    return count;
}

void printInfo_103032300055(Queue Q) {
    if(isEmpty_103032300055(Q) == true) {
        cout << "Antrean kosong." << endl;
    } else {
        cout << "Daftar antrean: " << endl;
        ElemQ *P = front_103032300055(Q);
        while (P != NULL) {
            cout << "Nama: " << info(P).nama << endl;
            cout << "Usia: " << info(P).usia << endl;
            cout << "Pekerjaan: " << info(P).pekerjaan << endl;
            if(info(P).prioritas == true) {
                cout << "Prioritas: Ya" << endl;
            } else {
                cout << "Prioritas: Tidak" << endl;
            }
            cout << "Nomor Antrean: " << info(P).nomor_antrean << endl;
            cout << "-----------------------------" << endl;
            P = next(P);
        }
    }
}

void serveQueue_103032300055(Queue &Q) {
    int count = 0;
    ElemQ *P;
    while (isEmpty_103032300055(Q) != true && count < 100) {
        dequeue_103032300055(Q, P);
        cout << "Melayani Warga: " << endl;
        cout << "Nama: " << info(P).nama << endl;
        cout << "Usia: " << info(P).usia << endl;
        cout << "Pekerjaan: " << info(P).pekerjaan << endl;
        if(info(P).prioritas == true) {
            cout << "Prioritas: Ya" << endl;
        } else {
            cout << "Prioritas: Tidak" << endl;
        }
        cout << "Vaksinasi berhasil." << endl;
        cout << "-----------------------------" << endl;
        count++;
    }
    if(size_103032300055(Q) > 100) {
        cout << "Kapasitas harian telah penuh." << endl;
        if(isEmpty_103032300055(Q) == false) {
            cout << "Warga yang belum terlayani diminta kembali besok." << endl;
        }
    }
}

void reassignQueue_103032300055(Queue &Q) {
    Queue priorityQ, normalQ, waitingQ;
    createQueue_103032300055(priorityQ);
    createQueue_103032300055(normalQ);
    createQueue_103032300055(waitingQ);
    ElemQ *P;
    while (isEmpty_103032300055(Q) != true) {
        dequeue_103032300055(Q, P);
        if(info(P).prioritas) {
            enqueue_103032300055(priorityQ, P);
        } else {
            enqueue_103032300055(normalQ, P);
        }
    }
    while (isEmpty_103032300055(priorityQ) != true) {
        dequeue_103032300055(priorityQ, P);
        enqueue_103032300055(waitingQ, P);
    }
    while (isEmpty_103032300055(normalQ) != true) {
        dequeue_103032300055(normalQ, P);
        enqueue_103032300055(waitingQ, P);
    }
    Q = waitingQ;
}

void checkWaitingTime_103032300055(Queue &Q, int waktu_sekarang) {
    Queue priorityQ, tempQ;
    createQueue_103032300055(priorityQ);
    createQueue_103032300055(tempQ);
    ElemQ *P;
    while (isEmpty_103032300055(Q) != true) {
        dequeue_103032300055(Q, P);
        if((waktu_sekarang - info(P).waktu_daftar) > 120) {
            info(P).prioritas == true;
            enqueue_103032300055(priorityQ, P);
        } else {
            enqueue_103032300055(tempQ, P);
        }
    }
    while (isEmpty_103032300055(priorityQ) != true) {
        dequeue_103032300055(priorityQ, P);
        enqueue_103032300055(Q, P);
    }
    while (isEmpty_103032300055(tempQ) != true) {
        dequeue_103032300055(tempQ, P);
        enqueue_103032300055(Q, P);
    }
}

void emergencyHandle_103032300055(Queue &Q, int nomor_antrean) {
    Queue priorityQ, tempQ;
    createQueue_103032300055(priorityQ);
    createQueue_103032300055(tempQ);
    ElemQ *P;
    bool isFound = false;
    while (isEmpty_103032300055(Q) != true) {
        dequeue_103032300055(Q, P);
        if(info(P).nomor_antrean == nomor_antrean) {
            info(P).kondisi_darurat = true;
            isFound = true;
            enqueue_103032300055(priorityQ, P);
        } else {
            enqueue_103032300055(tempQ, P);
        }
    }
    if(isFound == false) {
        cout << "Warga dengan nomor antrean" << nomor_antrean << "Tidak ditemukan." << endl;
    }
    while (isEmpty_103032300055(priorityQ) != true) {
        dequeue_103032300055(priorityQ, P);
        enqueue_103032300055(Q, P);
    }
    while (isEmpty_103032300055(tempQ) != true) {
        dequeue_103032300055(tempQ, P);
        enqueue_103032300055(Q, P);
    }
}

void updatePriority_103032300055(Queue &Q) {
    Queue Qdepan, QpalingDepan, Qbelakang;
    createQueue_103032300055(QpalingDepan);
    createQueue_103032300055(Qdepan);
    createQueue_103032300055(Qbelakang);
    ElemQ *P;
    while (isEmpty_103032300055(Q) != true) {
        dequeue_103032300055(Q, P);
        if(info(P).prioritas == true || info(P).waktu_daftar > 120) {
            info(P).waktu_daftar = info(P).waktu_daftar + 60;
            enqueue_103032300055(QpalingDepan, P);
        } else if(info(P).kondisi_darurat == true) {
            info(P).waktu_daftar = info(P).waktu_daftar + 60;
            enqueue_103032300055(Qdepan, P);
        } else {
            info(P).waktu_daftar = info(P).waktu_daftar + 60;
            enqueue_103032300055(Qbelakang, P);
        }
    }
    while (isEmpty_103032300055(QpalingDepan) != true) {
        dequeue_103032300055(QpalingDepan, P);
        enqueue_103032300055(Q, P);
    }
    while (isEmpty_103032300055(Qdepan) != true) {
        dequeue_103032300055(Qdepan, P);
        enqueue_103032300055(Q, P);
    }
    while (isEmpty_103032300055(Qbelakang) != true) {
        dequeue_103032300055(Qbelakang, P);
        enqueue_103032300055(Q, P);
    }
}

ElemQ* findAndRemove_103032300055(Queue &Q, int nomor_antrean) {
    Queue tempQ;
    createQueue_103032300055(tempQ);
    ElemQ *P;
    ElemQ *Pketemu = NULL; // Corrected "ELemQ" to "ElemQ"
    
    while (!isEmpty_103032300055(Q)) { // Simplified condition
        dequeue_103032300055(Q, P);
        if (info(P).nomor_antrean == nomor_antrean) {
            Pketemu = P;
        } else {
            enqueue_103032300055(tempQ, P);
        }
    }

    while (!isEmpty_103032300055(tempQ)) { // Simplified condition
        dequeue_103032300055(tempQ, P);
        enqueue_103032300055(Q, P);
    }

    if (Pketemu == NULL) {
        cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan dalam antrean." << endl;
    }

    return Pketemu;
}
