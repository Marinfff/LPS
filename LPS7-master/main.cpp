//main.cpp
#include "global.h"
#include "Student.h"
#include "Grupa.h"

int main() {
    Grupa IS11Z;
    int id;

    cout << "\n" << "Tabelul citit din students.txt este:" << "\n";
    IS11Z.ReadFromTxt();
    IS11Z.Print();
    cout << "\n" << "Tabelul sortat dupa id este:" << "\n";
    IS11Z.SortById();
    IS11Z.Print();
    cout << "\n" << "Tabelul sortat dupa nume este:" << "\n";
    IS11Z.SortByName();
    IS11Z.Print();
    cout << "\n" << "Trebuie sa adaugati un nou student!" << "\n";
    IS11Z.AddStudent();
    cout << "\n" << "Tabelul citit dupa adaugarea unui element este:" << "\n";
    IS11Z.Print();
    cout << "\n" << "Intoduceti id'un elementului pentru stergere:" << "\n";
    cin >> id;
    IS11Z.DeleteStudent(id);
    cout << "\n" << "Tabelul citit dupa stergerea elementului cu id'ul " << id << " este:" << "\n";
    IS11Z.Print();
    cout << "\n" << "Intoduceti id'un elementului pentru innoire:" << "\n";
    cin >> id;
    IS11Z.UpdateStudent(id);
    cout << "\n" << "Tabelul citit dupa innoirea elementului cu id'ul " << id << " este:" << "\n";
    IS11Z.Print();
    cout << "\n" << "Tabelul final citit din bin.dat este:" << "\n";
    IS11Z.Print();
    cout << "\n" << "Procentul calitatii este: " << IS11Z.GetCalitate() << "\n";
    return 0;
}