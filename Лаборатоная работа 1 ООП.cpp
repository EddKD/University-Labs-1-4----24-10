#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    if (n <= 0) {
        cout << "Размер массива должен быть положительным числом!" << endl;
    }
    int* arr = new  int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "\nСодержимое массива:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    cout << "\nАдрес начала массива: " << arr << endl;

    cout << "\nРасстояние элементов от начала массива:" << endl;
    for (int i = 0; i < n; i++) {
        size_t bytes_distance = i * sizeof(int);
        ptrdiff_t elements_distance = i;
        cout << "Элемент arr[" << i << "]:" << endl;
        cout << "  Адрес: " << &arr[i] << endl;
        cout << "  Расстояние от начала: " << elements_distance << " элементов";
        cout << " (" << bytes_distance << " байт)" << endl;
    }
    delete[] arr;
    return 0;
}

//ЗАДАНИЕ Б ЗАКОММЕНТИРОВАЛ 
/*
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <iomanip> 
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    const int n = 10;
    double* arr = new double[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 10000) / 100.0;
    }

    cout << "\nСодержимое массива:" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << "\nАдрес начала массива: " << arr << endl;
    cout << "\nРасстояние элементов от начала массива:" << endl;
    for (int i = 0; i < n; i++) {
        size_t distance_bytes = i * sizeof(double);
        ptrdiff_t distance_elements = i;
        cout << "Элемент arr[" << i << "]: ";
        cout << "адрес = " << &arr[i] << ", ";
        cout << "смещение = " << distance_bytes << " байт";
        cout << " (" << distance_elements << " элементов)" << endl;
    }
    delete[] arr;
    return 0;
}
*/