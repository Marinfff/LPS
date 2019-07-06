//Grupa.h
#ifndef LPS7_GRUPA_H
#define LPS7_GRUPA_H

#include "global.h"
#include "Student.h"


class Grupa {
protected:
    vector<Student> grupa;

private:
    void pushElement(Student &object);

    void WriteToBin();

    void WriteToBin(Student object);

    void ReadFromBin();

public:
    void AddStudent();

    void UpdateStudent(int id);

    void DeleteStudent(int id);

    void Print();

    void ReadFromTxt();

    void SortByName();

    void SortById();

    float GetCalitate();
};


#endif //LPS7_GRUPA_H
