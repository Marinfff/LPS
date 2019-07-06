//fileFunc.cpp
#include "global.h"

void ReadTextFile(vector<Students> &array) {
    string line;
    array.clear();
    ifstream inputF("F:\\students.txt");
    while (getline(inputF, line)) {
       array.push_back(ParseLine(array, line));
    }
    inputF.close();
}

void WriteBinFile(vector<Students> &array) {
    Students student;
    ofstream fout("F:\\bin.dat", ios::binary);
    for (int i = 0; i < array.size(); ++i) {
        fout.write(reinterpret_cast<char *>(&array[i]), sizeof(Students));
    }
    fout.close();
}

void ReadBinFile() {
    Students student;
    vector<Students> vec;

    ifstream ifs("F:\\bin.dat", ios::binary);
        while (ifs.read(reinterpret_cast<char *>(&student), sizeof(Students))) {
            vec.push_back(student);
        }
    ifs.close();

    PrintList(vec);
}

