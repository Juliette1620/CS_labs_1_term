//В целочисленной прямоугольной матрице A(mxn) найти:
//-номер первой из строк, содержащей хотя бы один нуль;
//-координаты всех ее седловых точек, если таковые имеются
//max min(a[i, j]) = min max(a[i, j]).


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int matrixRand(int, int);
void matrixOutput(int**, int, int);
int matrixDimensionsInput(int*, int*);
void checking(int*, int*);
int numberOfRoW(int**, int, int);
void cordinatesOfPoints(int**, int, int);
bool minInRaw(int*, int, int);
bool maxInCol(int**, int, int, int);

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int n, m, a, b;
    int** matrix;
    if (matrixDimensionsInput(&m, &n)) return 1;
    matrix = new int* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new int[n];
    cout << "Выберите операцию: \n1) ручной ввод элементов матрицы;\n"
        << "2) автоматическое заполнение матрицы элементами;\n";
    int numberOfOperation;
    cout << "Выбрана операция ";
    cin >> numberOfOperation;
    switch (numberOfOperation) {
        case 1:
            cout << "Введите элементы матрицы:\n";
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> matrix[i][j];
                }
            }
            matrixOutput(matrix, m, n);
            break;
        case 2:
             checking(&a, &b);
             for (int i = 0; i < m; i++) {
                 for (int j = 0; j < n; j++) {
                     matrix[i][j] = matrixRand(a, b);
                 }
             }
             matrixOutput(matrix, m, n);
             break;
         default:
             cout << "Неверная операция";
             break;
    }
    cout << "Номер первой из строк, содержащей хотя бы один нуль: " << numberOfRoW(matrix, m, n) << endl;
    cordinatesOfPoints(matrix, m, n);
    for (int i = 0; i < m; i++)
        delete[] matrix[i];
    system("pause");
    return 0;
}

int matrixRand(int a, int b) {
    return (a + rand() % (b - a + 1));
}

void matrixOutput(int** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n\n\n";
    }
}

void checking(int* a, int* b) {
    cout << "Введите границы интервала, которому должны принадлежать элементы матрицы\na = ";
    cin >> *a;
    cout << endl; 
    for (;;) {
        cout << "b = ";
        cin >> *b;
        cout << endl;
        if (*a >= *b)
            cout << "Значение b должно превышать значение a\n";
        else break;
    }
}

int matrixDimensionsInput (int* m, int* n) {
    cout << "Задайте размер матрицы.\nКоличество строк в матрице m =  ";
    cin >> *m;
    if (m <= 0) {
        cout << "Введенное значение m не может быть количеством строк в матрице \n";
        system("pause");
        return 1;
    }
    cout << "\nКоличество столбцов в матрице n =  ";
    cin >> *n;
    if (n <= 0) {
        cout << "Введенное значение n не может быть количеством столбцов в матрице \n";
        system("pause");
        return 1;
    }
    return 0;
}

int numberOfRoW(int** matrix, int m, int n) {
    int counter = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0)
                counter = i;
        }
    }
    return (counter);
}

void cordinatesOfPoints(int** matrix, int m, int n) {
    bool ifNoPoints = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (minInRaw(&matrix[i][0], n, matrix[i][j]) && maxInCol(matrix, m, matrix[i][j], j)) {
                cout << "Седловой элемент " << matrix[i][j] << " c координатами " << i << " и " << j << endl;
                ifNoPoints = false;
            }
        }
    }
    if (ifNoPoints)
        cout << "Нет седловых точек" << endl;
}

bool minInRaw(int* row, int n, int num) {
    for (int k = 0; k < n; k++) {
        if (row[k] < num) return (false);
    }
    return (true);
}

bool maxInCol(int** matrix, int m, int num, int j) {
    for (int k = 0; k < m; k++) {
        if (matrix[k][j] > num) return (false);
    }
    return (true);
}
