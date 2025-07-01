#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "metody.h"

using namespace std;



int main() 
{
    setlocale(LC_ALL, "Ru");
    Phones phoneBook;
    int choice = 0;

    while (true) 
    {
        cout << "����:"<<endl;
        cout << "1. �������� ���������" << endl;
        cout << "2. ������� ���������" << endl;
        cout << "3. �������� ���� ����������" << endl;
        cout << "4. ��������� � ����" << endl;
        cout << "5. ��������� �� �����" << endl;
        cout << "6. ������������� �� ������" << endl;
        cout<<  "7. �������� ���� ����������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: " << endl;
        cin >> choice;

        try 
        {
            switch (choice) 
            {
            case 1: 
            {
                short num;
                string name;
                double cost;
                int index;

                cout << "������� ������: ";
                cin >> index;
                
                cout << "������� ����� ��������: ";
                cin >> num;
               
                cout << "������� �������: ";
                cin >> name;

                cout << "������� ���������: ";
                cin >> cost;

                phoneBook.insert(index, Phone(num, name, cost));

                cout << "�������� ��������."<<endl;
                break;
            }
            case 2: 
            {
                int index;
                cout << "������� ������ ��� ��������: ";
                cin >> index;
                phoneBook.erase(index);
                cout << "�������� ������."<<endl;
                break;
            }
            case 3:
                cout << "������ ����������:" << endl;
                phoneBook.print();
                break;
            case 4:
                phoneBook.Save("phones.txt");
                cout << "������ ��������� � ����." << endl;
                break;
            case 5:
                phoneBook.Load("phones.txt");
                cout << "������ ��������� �� �����." << endl;
                break;
            case 6:
                phoneBook.sort();
                cout << "������ ������������ �� ������ ��������." << endl;
                break;
            case 7: 
                phoneBook.clear();
                cout << "������ ������." << endl;
                break;
            
            case 0:
                return 0;
            default:
                cout << "�������� �����. ���������� �����." << endl;
                break;
            }
        }
        catch (const exception& e) 
        {
            cout << "������: " << e.what() << endl;
        }
    }
    return 0;
}