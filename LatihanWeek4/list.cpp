
#include "list.h"
#include <iostream>
#include <string>

using namespace std;

// Mengecek apakah list kosong
bool isEmpty(LinkedList list) {
    return list.first == nullptr;
}

// Membuat linked list kosong
void createList(LinkedList &list) {
    list.first = nullptr;
}

// Membuat node baru
address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;

    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = nullptr;

    return nodeBaru;
}

// Menghapus node dan membebaskan memorinya
void dealokasi(address &nodeHapus) {
    if (nodeHapus != nullptr) {
        delete nodeHapus;
        nodeHapus = nullptr;
    }
}

// Menambahkan node di awal list
void insertFirst(LinkedList &list, address nodeBaru) {
    if (nodeBaru != nullptr) {
        nodeBaru->next = list.first;
        list.first = nodeBaru;
    }
}

// Menambahkan node setelah node tertentu
void insertAfter(LinkedList &list, address nodeBaru, address prev) {
    if (nodeBaru == nullptr) {
        return;
    }

    if (prev != nullptr) {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

// Menambahkan node di akhir list
void insertLast(LinkedList &list, address nodeBaru) {
    if (nodeBaru == nullptr) {
        return;
    }

    nodeBaru->next = nullptr;

    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;

        while (nodeBantu->next != nullptr) {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->next = nodeBaru;
    }
}

// Menghapus node pertama
void delFirst(LinkedList &list) {
    if (!isEmpty(list)) {
        address nodeHapus = list.first;

        list.first = list.first->next;
        nodeHapus->next = nullptr;

        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

// Menghapus node terakhir
void delLast(LinkedList &list) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    address nodeHapus = list.first;

    // Jika hanya ada satu node
    if (nodeHapus->next == nullptr) {
        list.first = nullptr;
        dealokasi(nodeHapus);
        return;
    }

    address nodePrev = nullptr;

    while (nodeHapus->next != nullptr) {
        nodePrev = nodeHapus;
        nodeHapus = nodeHapus->next;
    }

    nodePrev->next = nullptr;
    dealokasi(nodeHapus);
}

// Menghapus node setelah nodePrev
void delAfter(
    LinkedList &list,
    address nodeHapus,
    address nodePrev
) {
    if (isEmpty(list)) {
        cout << "List kosong!" << endl;
        return;
    }

    if (nodePrev != nullptr && nodePrev->next != nullptr) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = nullptr;

        dealokasi(nodeHapus);
    } else {
        cout << "Node sebelumnya (prev) tidak valid!" << endl;
    }
}

// Menampilkan seluruh data mahasiswa
void printList(LinkedList list) {
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
        return;
    }

    address nodeBantu = list.first;

    while (nodeBantu != nullptr) {
        cout << "Nama : " << nodeBantu->isidata.nama
             << ", NIM : " << nodeBantu->isidata.nim
             << ", Usia : " << nodeBantu->isidata.umur
             << endl;

        nodeBantu = nodeBantu->next;
    }
}

// Menghitung jumlah node
int nbList(LinkedList list) {
    int count = 0;
    address nodeBantu = list.first;

    while (nodeBantu != nullptr) {
        count++;
        nodeBantu = nodeBantu->next;
    }

    return count;
}

// Menghapus seluruh node dalam list
void deleteList(LinkedList &list) {
    address nodeBantu = list.first;

    while (nodeBantu != nullptr) {
        address nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;

        nodeHapus->next = nullptr;
        dealokasi(nodeHapus);
    }

    list.first = nullptr;

    cout << "List sudah terhapus!" << endl;
}
