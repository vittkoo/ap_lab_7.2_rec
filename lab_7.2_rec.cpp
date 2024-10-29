#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo);
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int n, int colNo);
void PrintRows(int** a, const int k, const int n, int rowNo);
void FindMaxOfMins(int** a, const int k, const int n, int rowNo, int& maxMin);
void FindMinInRow(int** a, const int rowNo, const int n, int colNo, int& minInRow);

int main() {
    srand((unsigned)time(NULL));

    int Low = 4;
    int High = 51;

    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    CreateRows(a, k, n, Low, High, 0);
    PrintRows(a, k, n, 0);

    int maxMin = -1;
    FindMaxOfMins(a, k, n, 0, maxMin);

    if (maxMin > -1) {
        cout << "Max of minimums = " << maxMin << endl;
    }
    else {
        cout << "Matrix is empty." << endl;
    }

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int n, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int k, const int n, int rowNo) {
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
}

void FindMinInRow(int** a, const int rowNo, const int n, int colNo, int& minInRow) {
    if (colNo == 0) 
        minInRow = a[rowNo][colNo]; // ≥н≥ц≥ал≥зац≥€ minInRow першим елементом
    else if (a[rowNo][colNo] < minInRow) 
        minInRow = a[rowNo][colNo]; // знаходженн€ м≥н≥мального елемента в р€дку
    if (colNo < n - 1) 
        FindMinInRow(a, rowNo, n, colNo + 1, minInRow); // виклик дл€ наступного стовпц€
    
}

void FindMaxOfMins(int** a, const int k, const int n, int rowNo, int& maxMin) {
    if (rowNo < k) {
        int minInRow = 0;
        FindMinInRow(a, rowNo, n, 0, minInRow);

        // оновленн€ maxMin
        if (rowNo == 0) 
            maxMin = minInRow;
        else if (minInRow > maxMin) 
            maxMin = minInRow;
        FindMaxOfMins(a, k, n, rowNo + 1, maxMin);
    }
}
