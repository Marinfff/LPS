//Student.h
#ifndef LPS7_STUDENT_H
#define LPS7_STUDENT_H

#include "global.h"


class Student {
protected:
    int id;
    string nume;
    string grupa;
    int zi;
    int luna;
    int an;
    int semestrul;
    int note[6];

public:
    Student();

    Student(int id);

    Student(string &line);

    void Print();

    void SetFields();

    int GetId();

    string GetName();

    float GetMedie();

private:
    int toNumber(string &word);
};


#endif //LPS7_STUDENT_H
