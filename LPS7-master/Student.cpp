//Student.cpp
#include "global.h"
#include "Student.h"

Student::Student() {
    this->id = 0;
    this->nume = "";
    this->grupa = "";
    this->zi = 0;
    this->luna = 0;
    this->an = 0;
    this->semestrul = 0;

    for (auto &nota : this->note) {
        nota = 0;
    }
}

Student::Student(int id) {
    this->id = id;
    this->SetFields();
}

Student::Student(string &line) {
    int currentWord = 0;
    string word;
    istringstream stream(line);

    while (stream) {
        stream >> word;

        if (currentWord == 6) this->id = toNumber(word);
        if (currentWord == 7) this->nume = word;
        if (currentWord == 8) this->grupa = word;
        if (currentWord == 9) this->zi = toNumber(word);
        if (currentWord == 10) this->luna = toNumber(word);
        if (currentWord == 11) this->an = toNumber(word);
        if (currentWord == 12) this->semestrul = toNumber(word);
        if (currentWord < 6)
            for (int i = 0; i < 6; i++)
                this->note[currentWord] = toNumber(word);
        currentWord++;
    }
}

void Student::Print() {
    cout << "id: " << this->id;
    cout << ", nume: " << this->nume;
    cout << ", grupa: " << this->grupa;
    cout << ", Data nasterii: ";
    cout << this->zi << ".";
    cout << this->luna << ".";
    cout << this->an;
    cout << ", Semestrul: " << this->semestrul;
    cout << ", Note: ";
    cout << this->note[0] << ",";
    cout << this->note[1] << ",";
    cout << this->note[2] << ",";
    cout << this->note[3] << ",";
    cout << this->note[4] << ",";
    cout << this->note[5] << "\n";
}

void Student::SetFields() {
    cout << "Intoduceti pe rand " << "nume: " << "\n";
    cin >> this->nume;
    cout << "Grupa: " << "\n";
    cin >> this->grupa;
    cout << "Zi: " << "\n";
    cin >> this->zi;
    cout << "Luna: " << "\n";
    cin >> this->luna;
    cout << "An: " << "\n";
    cin >> this->an;
    cout << "Semestrul: " << "\n";
    cin >> this->semestrul;
    for (int i = 0; i < 6; i++) {
        cout << "nota nr " << i << "\n";
        cin >> this->note[i];
    }
}

int Student::GetId() {
    return this->id;
}

string Student::GetName() {
    return this->nume;
}

float Student::GetMedie() {
    float media = 0;
    for (auto &nota : this->note) {
        media += nota;
    }
    return media / 6;
}

int Student::toNumber(string &word) {
    return atoi(word.c_str());
}
