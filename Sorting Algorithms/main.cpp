#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& A, int k) {
    int N = A.size();

    // ������� ������ B �������� k+1 � ��������� ��� ������
    vector<int> B;
    for (int i = 0; i <= k; i++)
    {
        B.push_back(0);
    }

    // ��������� ������ B, ����������� ���������� ������� ��������
    for (int i = 0; i < N; i++) {
        B[A[i]]++;
    }

    int walker = 0;   // ������ ��� ���������� ��������������� �������
    for (int i = 0; i <= k; i++) { // �������� �� ���� ��������� ��������� �� 0 �� k
        while (B[i] > 0) { // ���� ���� �������� �� ��������� i
            A[walker++] = i; // ��������� i � �������������� ������
            B[i]--; // ��������� ���������� ���������� ��������� i
        }
    }
}

void radixSort(vector<int>& A, int k, int P) {
    int N = A.size();

    vector<vector<int>> tempArray; // ������� P ��������
    tempArray.resize(P);

    for (int i = 0; i < k; ++i) { // �������� �� ������� �������
        
        // ������������ ����� �� ��������
        for (int j = 0; j < N; ++j) {
            int index = (A[j] / (int)pow(P, i)) % P; // �������� ������ �������
            tempArray[index].push_back(A[j]); // ��������� ����� � ������
        }

        // �������������� ����� �� �������� ������� � ������
        int walker = 0;
        for (int vec = 0; vec < P; vec++) {
            for (int num : tempArray[vec]) {
                A[walker++] = num;
            }
            tempArray[vec].clear(); // �������
        }
    }
}
int main() {
    setlocale(LC_ALL, "ru");

    cout << "��������:\n1. ���������� ��������� (Counting sort). \n2. ����������� ����������(Radix sort).LSD!\n";
    int sort; cin >> sort;

    switch (sort)
    {
        {
    case 1:
        cout << "�� �������: 1. ���������� ��������� (Counting sort)\n";

        int N, k;

        // ���� ������� �������
        cout << "������� ������ �������: ";
        cin >> N;

        // ���� ������������� �������� k
        cout << "������� ������������ ������� �������: ";
        cin >> k;

        // ���� ��������� �������
        vector<int> A;
        A.resize(N);
        cout << "������� �������� ������� (����� ������): ";
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // ����������
        countingSort(A, k);

        // ����� ���������������� �������
        cout << "��������������� ������: ";
        for (int num : A) {
            cout << num << " ";
        }
        cout << endl;
        break;
        }
    case 2:
    {
        cout << "�� �������: 2. ����������� ���������� (Radix sort) LSD\n";
        vector<int> A;

        int N, k, P;

        // ���� ������� �������
        cout << "������� ������ �������: ";
        cin >> N;

        // ���� ������������� �������� k
        cout << "������� ������������ ������: ";
        cin >> k;

        // ���� ������������� �������� k
        cout << "������� ������� ���������: ";
        cin >> P;

        // ���� ��������� �������
        A.resize(N);
        cout << "������� �������� ������� (����� ������): ";
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // ����������
        radixSort(A, k, P);

        // ����� ���������������� �������
        cout << "��������������� ������: ";
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