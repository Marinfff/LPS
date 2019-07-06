//Grupa.cpp
#include "global.h"
#include "Grupa.h"

string pathToTxt = "F:\\students.txt";
string pathToBin = "F:\\bin.dat";


void Grupa::pushElement(Student &object) {
    this->grupa.push_back(object);
}

void Grupa::WriteToBin() {
    Student student;
    ofstream fout(pathToBin, ios::binary);
    for (auto &student : this->grupa) {
        fout.write(reinterpret_cast<char *>(&student), sizeof(student));
    }
    fout.close();
    this->ReadFromBin();
}

void Grupa::WriteToBin(Student object) {
    ofstream fout(pathToBin, ios::binary | ios_base::app);
    fout.write(reinterpret_cast<char *>(&object), sizeof(object));
    fout.close();
    this->ReadFromBin();
}

void Grupa::ReadFromBin() {
    Student student;
    this->grupa.clear();
    ifstream finput(pathToBin, ios::binary);
    while (finput.read(reinterpret_cast<char *>(&student), sizeof(student))) {
        this->grupa.push_back(student);
    }
    finput.close();
}

void Grupa::AddStudent() {
    int k;
    do {
        Student student(grupa.size() + 1);
        WriteToBin(student);
        cout << "Doriti sa introduceti ceva? " << endl;
        cin >> k;
    } while (k != 0);
}

void Grupa::UpdateStudent(int id) {
    for (int i = 0; i < this->grupa.size(); ++i) {
        if (this->grupa[i].GetId() == id) {
            this->grupa[i].SetFields();
        }
    }
    this->WriteToBin();
}

void Grupa::DeleteStudent(int id) {
    vector<Student>::iterator first;
    first = this->grupa.begin();
    for (int i = 0; i < this->grupa.size(); ++i) {
        if (this->grupa[i].GetId() == id) {
            this->grupa.erase(first + i);
        }
    }
    this->WriteToBin();
}

void Grupa::Print() {
    for (auto &student: this->grupa) {
        student.Print();
    }
}

void Grupa::ReadFromTxt() {
    string line;
    ifstream finput(pathToTxt);
    while (getline(finput, line)) {
        Student Object(line);
        this->pushElement(Object);
    }
    finput.close();
    this->WriteToBin();
}

void Grupa::SortByName() {
    vector<Student>::iterator i1, i2;
    i1 = this->grupa.begin();
    i2 = this->grupa.begin();

    for (int i = this->grupa.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (this->grupa[j].GetName() > this->grupa[j + 1].GetName()) {
                iter_swap(i1 + j, i2 + j + 1);
            }
        }
    }
    this->WriteToBin();
}

void Grupa::SortById() {
    vector<Student>::iterator i1, i2;
    i1 = this->grupa.begin();
    i2 = this->grupa.begin();

    int j = 0;
    for (int i = 0; i < grupa.size(); i++) {
        j = i;
        for (int k = i; k < grupa.size(); k++) {
            if (this->grupa[j].GetId() > this->grupa[k + 1].GetId()) {
                j = k;
            }
        }
        iter_swap(i1 + j, i2 + j + 1);
    }
    this->WriteToBin();
}

float Grupa::GetCalitate() {
    float calitate = 0;
    for (auto &student : this->grupa) {
        if (student.GetMedie() >= 9) {
            calitate++;
        }
    }
    return round((calitate / (this->grupa.size()) * 100) * 100) / 100;
}