#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "stdio.h"

using namespace std;

string PureWord(string line) {
    string symbols = "!?,.-*%";

    for (int i = 0; i < symbols.size(); i++) {
        int pos = line.find(symbols[i]);
        if (pos != -1) {
            line.erase(pos, 1);
            return PureWord(line);
        }
    }
    return line;
}

string GetMaxLengWords(string line, int max) {
    string word, MaxLength;
    istringstream stream(line);
    while (stream) {
        if (PureWord(word).size() == max) MaxLength += PureWord(word) + " ";
        stream >> word;
    }
    return MaxLength;
}

int MaxLeng(string line) {
    string word;
    unsigned int max = 0;
    istringstream stream(line);
    while (stream) {
        stream >> word;
        if (PureWord(word).size() > max) max = PureWord(word).size();
    }
    return max;
}

void DeleteWords(string &line, int max) {
    string word, newString;
    istringstream stream(line);
    while (stream) {
        if (PureWord(word).size() != max) newString += word + " ";
        stream >> word;
    }
    line = newString;
}


int NumOfWords(string line) {
    string word;
    int count = -1;
    istringstream stream(line);
    while (stream) {
        stream >> word;
        count++;
    }
    return count;
}

string WriteFile() {
    string line, str;
    ifstream inputF("F:\\input.txt");
    while (getline(inputF, line)) str += line + "\n";
    inputF.close();
    return str;
}

void ReadFile(string line) {
    ofstream outputFile("F:\\output.txt", ios_base::app);
    outputFile << line << "\n";
    outputFile.close();
}

void DeleteWordsInFile() {
    string line, str;
    ifstream inputF("F:\\input.txt");
    while (getline(inputF, line)) str += line + "\n";
    inputF.close();
    DeleteWords(str, MaxLeng(str));
    ofstream outputFile("F:\\input.txt");
    outputFile << str << "\n";
    outputFile.close();
}

void IdentStartEnd(string line) {
    string word;
    istringstream stream(line);
    while (stream) {
        if (word[0] == word[word.size() - 1]) {
            ReadFile(word);
        }
        stream >> word;
    }
}

int main() {
    string line, file = WriteFile();
    cout << "Intoduceti sirul de caractere" << endl;
    getline(cin, line);
    cout << "Fraza contine " << NumOfWords(line) << " cuvinte" << endl;
    cout << "Cuvintele cu lungime maxima sunt: " << GetMaxLengWords(line, MaxLeng(line)) << endl;
    DeleteWords(line, MaxLeng(line));
    cout << "Fraza obtinuta dupa stergerea cuv cu lungime maxima: " << line << endl;
    cout << "Fisierul contine: " << NumOfWords(file) << " cuvinte" << endl;
    ReadFile(GetMaxLengWords(file, MaxLeng(file)));
    IdentStartEnd(file);
    DeleteWordsInFile();
    return 0;
}