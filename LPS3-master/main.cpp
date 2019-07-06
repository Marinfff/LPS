#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cmath>

using namespace std;


int rrand(int range_min, int range_max) {
    return rand() % (range_max - range_min + 1) + range_min;
}

int WriteArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}

int SortArray(int arr[], int size, int ord) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ord == 1) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else {
                if (arr[j] < arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    WriteArr(arr, size);
    return 0;
}

int DeleteElement(int x[], int k, int &n) {
    for (int i = k; i < n; ++i) {
        x[i] = x[i + 1];
    }
    n--;

    WriteArr(x, n);

    return 0;
}

int AddElement(int x[], int h, int &n) {
    n++;

    x[n - 1] = h;

    WriteArr(x, n);
    return 0;
}

int Rotire(int x[], int z, int n) {
    z = x[0];
    for (int i = 1; i <= n; i++) x[i - 1] = x[i];
    x[n - 1] = z;
    cout << "Vectorul obtinut" << "\n";
    WriteArr(x, n);
    return 0;
}

float MediaNotelor(int arr[], int size) {
    int *n = &size;
    float *medie = new float;
    int *arr_ptr = arr;

    for (int i = 0; i < size; ++i) {
        *medie += *(arr_ptr + i);
    }

    *medie = *medie / *n;

    return *medie;
}

int MinMax(int arr[], int size, int item) {
    int *min = new int;
    int *max = new int;
    int *arr_ptr = arr;

    *min = arr[0];
    *max = arr[0];

    for (int i = 0; i < size; ++i) {
        if (*(arr_ptr + i) > *max) {
            *max = *(arr_ptr + i);
        }
        if (*(arr_ptr + i) < *min) {
            *min = *(arr_ptr + i);
        }
    }

    if (item == 1) {
        return *max;
    } else {
        return *min;
    }
}

float Calitate(int x[], int n) {
    float calitatii = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] == 10 || x[i] == 9)
            calitatii++;
    }
    return round((calitatii / n * 100) * 100) / 100;
}

int main() {
    int z, k, h, n, n2, ord;
    cout << "\n" << "Introduceti nr de elevi" << "\n";
    cin >> n;

    int x[n];

    for (int i = 0; i < n; ++i) {
        x[i] = rrand(1, 10);
    }

    cout << "\n" << "Vectorul introdus" << WriteArr(x, n) << "\n";

    cout << "\n" << "Introduceti ordinea sortararii 1 sau -1 " << "\n";
    cin >> ord;
    SortArray(x, n, ord);

    cout << "\n" << "Media notelor " << MediaNotelor(x, n) << "\n";

    cout << "\n" << "Introduceti 1 pentru a afla numarul maxim si 0 pentru minim" << "\n";
    cin >> n2;
    if (n2 == 1) {
        cout << "\n" << "Numarul maxim este " << MinMax(x, n, n2) << "\n";
    } else {
        cout << "\n" << "Numarul minim este " << MinMax(x, n, n2) << "\n";
    }

    cout << "\n" << "Introduceti nr elementului pentru stergere" << "\n";
    cin >> k;
    DeleteElement(x, k, n);

    cout << "Introduceti noul element" << endl;
    cin >> h;
    AddElement(x, h, n);

    cout << "Rotirea vectorului cu o pozitie la stanga" << "\n";
    Rotire(x, z, n);

    cout << "%Calitatii: " << Calitate(x, n) << "%" << endl;

    return 0;
}