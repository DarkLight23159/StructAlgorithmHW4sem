#include"BinarySearchTree.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>

void InputFromFile(std::vector<int>& array, int size) {
    std::ifstream input;
    input.open("input" + std::to_string(size) + ".txt");

    int Value;
    for (int i = 0; i < size; i++)
    {
        input >> Value;
        array.push_back(Value);
    }
    input.close();
}

int main() {
    setlocale(LC_ALL, "ru");
    tree* tr = nullptr;
    std::vector<int> inputArr;
    int size = 10;
    InputFromFile(inputArr, 10);

    for (int i = 0; i < size; i++)
    {
        insert(tr, inputArr[i]);
    }

    std::cout << "������ �����:" << std::endl;
    preorder(tr);
    std::cout << std::endl;
    std::cout << "������������ �����:" << std::endl;
    inorder(tr);
    std::cout << std::endl;
    std::cout << "�������� �����:" << std::endl;
    postorder(tr);
    std::cout << std::endl;

    Delete(tr, find(tr, 8));

    std::cout << "����� � ������� ���� �� ��������� 8." << std::endl;
    std::cout << "������ �����:" << std::endl;
    preorder(tr);
    std::cout << std::endl;
    std::cout << "������������ �����:" << std::endl;
    inorder(tr);
    std::cout << std::endl;
    std::cout << "�������� �����:" << std::endl;
    postorder(tr);
    std::cout << std::endl;
}