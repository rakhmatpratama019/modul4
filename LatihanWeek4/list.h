
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

// Deklarasi isi data mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

// Struktur node
struct node {
    dataMahasiswa isidata;
    address next;
};

// Struktur linked list
struct LinkedList {
    address first;
};

// Deklarasi fungsi dan prosedur
bool isEmpty(LinkedList list);
void createList(LinkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);

void printList(LinkedList list);
void insertFirst(LinkedList &list, address nodeBaru);
void insertAfter(LinkedList &list, address nodeBaru, address prev);
void insertLast(LinkedList &list, address nodeBaru);

void delFirst(LinkedList &list);
void delLast(LinkedList &list);
void delAfter(LinkedList &list, address nodeHapus, address nodePrev);

int nbList(LinkedList list);
void deleteList(LinkedList &list);

#endif
