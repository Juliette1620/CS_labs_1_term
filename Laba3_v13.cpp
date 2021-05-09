#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double maxNumber(double*, int);
double sumOfElements(double*, int);
void newArray(double*, int);
double arrayRand(double a, double b);

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int n;
    
    int const SIZE = 500;
    double array[SIZE];
    double a, b;
    cout << "Введите количество элементов массива.\n n =  ";
    cin >> n;
    if (n <= 0 || n > 500)
    {
        cout << "Веденное значение n не может быть количеством элементов массива \n";
        system("pause");
        return 1;
    }
    
    cout << "Выберите операцию: \n1) ручной ввод элементов массива;\n"
        << "2) автоматическое заполнение массива элементами;\n";
 
    int numberOfOperation;
    cout << "Выбрана операция ";
    cin >> numberOfOperation;
    if (numberOfOperation == 1)
    {
        cout << "Введите элементы массива:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
    }
    
    else
        if (numberOfOperation == 2)
        {
            cout << "Введите границы интервала, которому должны принадлежать элементы массива\na = ";
            cin >> a;
            cout << endl;
            for (;;)
            {
                cout << "b = ";
                cin >> b;
                cout << endl;
                if (a >= b)
                    cout << "Значение b должно превышать значение a\n";
                else break;
            }
            for (int i = 0; i < n; i++)
            {
                array[i] = arrayRand(a, b);
                cout << array[i] << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "Неверная операция";
            return 0;
        }
    cout << "Максимальный элемент массива равен " << maxNumber(array, n) << endl;
    cout << "Сумма элементов массива,"
        << "расположенных до последнего положительного элемента равна " << sumOfElements(array, n) << endl;
    cout << "Новый массив: \n";
    newArray(array, n);
    system("pause");
    return 0;
}



double maxNumber(double* array, int n)
{
    double maxNum = array[0];
    for (int i = 1; i < n; ++i)
    {
        if (array[i] > maxNum)
        {
            maxNum = array[i];
        }
    }
    return (maxNum);
}

double sumOfElements(double* array, int n)
{
    double sum = 0;
    int k = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (array[i] > 0)
        {
            i--;
            for (i; i >= 0; i--)
            {
                sum += array[i];
            }
        }
    }
   
    return (sum);
}

void newArray(double* array, int n)
{
    double a, b, tmp;
    bool ifZero ;
    cout << "Задайте интервал [a;b], значение b должно превышать значение a\na = ";
    cin >> a;
    cout << endl;

    for (;;)
    {
        cout << "b = ";
        cin >> b;
        cout << endl;
        if (a >= b)
            cout << "Значение b не превышает значение a\n";
        else break;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] >= a && array[i] <= b)
        {
            for (int j = i; j < n - 1; j++)
            {
                array[j] = array[j + 1];
            }
            array[n - k - 1] = 0;
            k++;
            i--; 
        }
    }
  
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}

double arrayRand(double a, double b) 
{
    double f = (double)rand() / RAND_MAX;
    return a + f * (b - a);
}
