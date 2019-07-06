//main.cpp

#include "global.h"

#pragma pack (push, 1)
#pragma pack (pop)

int main() {
    vector<Students> grupa;
    grupa.reserve(100);
    int deletedItem, updatedItem;

    ReadTextFile(grupa);
    cout << "\n" << "Tabelul citit din students.txt este:" << "\n";
    PrintList(grupa);
    cout << "\n" << "Tabelul sortat dupa nume este:" << "\n";
    SortByName(grupa);
    WriteBinFile(grupa);
    ReadBinFile();
    cout << "\n" << "Tabelul sortat dupa data nasterii este:" << "\n";
    SortByDn(grupa);
    WriteBinFile(grupa);
    ReadBinFile();
    cout << "\n" << "Intoduceti nr elementului pentru stergere: " << "\n";
    cin >> deletedItem;
    cout << "\n" << "Tabelul obtinut dupa stergerea elementului sub nr " << deletedItem << " este: " << "\n";
    DeleteElement(grupa, deletedItem - 1);
    WriteBinFile(grupa);
    ReadBinFile();
    cout << "\n" << "Procentul calitatii este " << Calitate(grupa) << "\n";
    cout << "\n" << "Intoduceti nr elementului pentru innoire: " << "\n";
    cin >> updatedItem;
    UpdateElement(grupa, updatedItem - 1);
    WriteBinFile(grupa);
    cout << "\n" << "Tabelul obtinut dupa innoirea elementului sub nr " << updatedItem << " este: " << "\n";
    ReadBinFile();
    cout << "\n" << "Adaugati un nou element!" << "\n";
    AddElement(grupa);
    cout << "\n" << "Tabelul final citit din bin.dat este:" << "\n";
    WriteBinFile(grupa);
    ReadBinFile();

    return 1;
}
