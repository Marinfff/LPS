#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main() {
    int n, n1, value, min = 10, max = 1, count = 0, decalaj;
    float media = 0, calitatii = 0;

    cout << "Introduceti nr de note " << endl;
    cin >> n;
    cout << "Introduceti valoarea pentru comparatii " << endl;
    cin >> n1;

    for (int i = 0; i < n; i++) {
        cout << "Introduceti cate o nota" << endl;
        cin >> value;
        if (value < min) min = value;
        if (value > max) max = value;
        if (value == 10 || value == 9) calitatii++;
        if (value == n1 || value < n1) count++;
        media += value;
    }

    decalaj = max - min;

    cout << "Media: " << round((media / n) * 100) / 100 << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Decalaj: " << decalaj << endl;
    cout << "Numarul de valori egale si mai mici de cat n1: " << count << endl;
    cout << "%Calitatii: " << round((calitatii / n * 100) * 100) / 100 << "%" << endl;

    return 0;
}