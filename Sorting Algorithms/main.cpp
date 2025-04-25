#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& A, int k) {
    int N = A.size();

    // Создаем массив B размером k+1 и заполняем его нулями
    vector<int> B;
    for (int i = 0; i <= k; i++)
    {
        B.push_back(0);
    }

    // Заполняем массив B, подсчитывая количество каждого элемента
    for (int i = 0; i < N; i++) {
        B[A[i]]++;
    }

    int walker = 0;   // Индекс для заполнения результирующего массива
    for (int i = 0; i <= k; i++) { // Проходим по всем возможным значениям от 0 до k
        while (B[i] > 0) { // Пока есть элементы со значением i
            A[walker++] = i; // Добавляем i в результирующий массив
            B[i]--; // Уменьшаем количество оставшихся элементов i
        }
    }
}

void radixSort(vector<int>& A, int k, int P) {
    int N = A.size();

    vector<vector<int>> tempArray; // Создаем P векторов
    tempArray.resize(P);

    for (int i = 0; i < k; ++i) { // Проходим по каждому разряду
        
        // Распределяем числа по векторам
        for (int j = 0; j < N; ++j) {
            int index = (A[j] / (int)pow(P, i)) % P; // Получаем индекс вектора
            tempArray[index].push_back(A[j]); // Добавляем число в вектор
        }

        // Перезаписываем числа из векторов обратно в массив
        int walker = 0;
        for (int vec = 0; vec < P; vec++) {
            for (int num : tempArray[vec]) {
                A[walker++] = num;
            }
            tempArray[vec].clear(); // Очищаем
        }
    }
}
int main() {
    setlocale(LC_ALL, "ru");

    cout << "Выберите:\n1. Сортировка подсчетом (Counting sort). \n2. Поразрядная сортировка(Radix sort).LSD!\n";
    int sort; cin >> sort;

    switch (sort)
    {
        {
    case 1:
        cout << "Вы выбрали: 1. Сортировка подсчетом (Counting sort)\n";

        int N, k;

        // Ввод размера массива
        cout << "Введите размер массива: ";
        cin >> N;

        // Ввод максимального значения k
        cout << "Введите максимальный элемент массива: ";
        cin >> k;

        // Ввод элементов массива
        vector<int> A;
        A.resize(N);
        cout << "Введите элементы массива (через пробел): ";
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Сортировка
        countingSort(A, k);

        // Вывод отсортированного массива
        cout << "Отсортированный массив: ";
        for (int num : A) {
            cout << num << " ";
        }
        cout << endl;
        break;
        }
    case 2:
    {
        cout << "Вы выбрали: 2. Поразрядная сортировка (Radix sort) LSD\n";
        vector<int> A;

        int N, k, P;

        // Ввод размера массива
        cout << "Введите размер массива: ";
        cin >> N;

        // Ввод максимального значения k
        cout << "Введите максимальный разряд: ";
        cin >> k;

        // Ввод максимального значения k
        cout << "Введите систему счисления: ";
        cin >> P;

        // Ввод элементов массива
        A.resize(N);
        cout << "Введите элементы массива (через пробел): ";
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Сортировка
        radixSort(A, k, P);

        // Вывод отсортированного массива
        cout << "Отсортированный массив: ";
        for (int num : A) {
            cout << num << " ";
        }
        cout << endl;

        break;
    }
    default:
        break;
    }
}