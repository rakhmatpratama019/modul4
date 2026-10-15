#include "list.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE;

    // Membuat linked list kosong
    createList(List);

    // Membuat data mahasiswa
    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    // Proses insert
    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    // Menampilkan list setelah insert
    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---"
         << endl;

    printList(List);

    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    // Proses delete
    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    // Menampilkan list setelah delete
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---"
         << endl;

    printList(List);

    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    // Menghapus seluruh isi linked list
    deleteList(List);

    cout << "--- ISI LIST SETELAH DIHAPUS LIST ---"
         << endl;

    printList(List);

    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
