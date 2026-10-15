
#include "Singlylist.h"

void CreateList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.first;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L) {
    if (L.first != Nil) {
        address P = L.first;
        L.first = L.first->next;
        P->next = Nil;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first == Nil) {
        return;
    }

    address P = L.first;

    if (P->next == Nil) {
        L.first = Nil;
        dealokasi(P);
        return;
    }

    address Prec = Nil;

    while (P->next != Nil) {
        Prec = P;
        P = P->next;
    }

    Prec->next = Nil;
    dealokasi(P);
}

void deleteAfter(List &L, address Prec) {
    if (Prec == Nil || Prec->next == Nil) {
        return;
    }

    address P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
    dealokasi(P);
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != Nil) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.first != Nil) {
        deleteFirst(L);
    }
}
