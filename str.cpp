#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

int main()
{
    ofstream str("result.txt");

    setlocale(LC_ALL, "");
    char raz[10];
    string arr1, arr2, str3;

    int n = arr1.length(), k = arr2.length();
    char* str1 = new char[n];
    char* str2 = new char[k];


    cout << "������� 1-�� ������: ";
    getline(cin, arr1);

    cout << endl << endl;

    cout << "������� 2-�� ������: ";
    getline(cin, arr2);


    cout << endl;
    cout << endl;

    cout << "������� �����������: ";
    cin.getline(raz, 10);

    strcpy(str1, arr1.c_str());
    strcpy(str2, arr2.c_str());


    cout << "������ 1: " << str1;
    cout << endl;
    cout << "������ 2: " << str2;


    cout << endl;
    cout << endl;


    //������ � 1 � 2 ������


    char* now = strtok(str1, raz); // �� ������ ��������� ������ �����������
    char lex[45] = "";//����� ������ ��� �������� ������������� ���������



    while (now != NULL)   // ���� ���� �������
    {
        if (strstr(str2, now) != NULL)//���� �� ������ ������ ������� ���������, �� 
        {
            strcat(lex, now);//��������� � ������ ������ �������
            strcat(lex, " ");// ��������� ������

        }

        now = strtok(NULL, raz);//������� ��� �����, ��������� ����������� �� �������� ���� �� ������ �� �������� �������

    }


    cout << "����� ������ �� ������ � ������: " << lex << endl;


   /* long int  p;
    p = strtol("0x12z", &str2, 0);
    printf(" n = %x, stop = %c\n", p, *str2);*/


    char numbers[256] = ""; // ������ ��������� �����
    char* token = strtok(str2, raz); 

    while (token != NULL) 
    {
        if (strncmp(token, "0x", 2) == 0) 
        { 
            

            char* st;
            long int value = strtol(token, &st, 16); // ����������� � ������� �����
            if (st != token) 
            { // ��������, ��� �������������� ������ �������
                char hex[40];
                _itoa(value, hex, 16); 
                strcat(numbers, "0x");
                strcat(numbers, hex);
                strcat(numbers, ", ");
            }
        }
        token = strtok(NULL, raz); 
    }

    if (strlen(numbers) > 0) {
        numbers[strlen(numbers) - 2] = '\0'; // ������� ��������� ������� � ������
    }

    cout << "��������� ����������������� �����: " << numbers << endl;



    //���������� ���������
    for (int i = 0; i < arr2.length(); i++)
    {
        for (int j = 0; j < arr2.length() - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                swap(arr2[j], arr2[j + 1]);
            }
        }
    }

    cout << "��������������� ������: " << arr2 << endl;

    cout << endl << endl;


    arr1.erase(arr1.length() - 1, 1);

    srand(time(NULL));
    char randomChar = (rand() % 255);
    arr1 += randomChar;
    cout << "������ � ���������� ��������� ��������: " << arr1 << endl;

    arr1.erase(arr1.length() - 2, 1);
    cout << "������ � ��������� ������������� ��������: " << arr1 << endl;



    str.close();
    return 0;
}