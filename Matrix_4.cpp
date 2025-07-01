#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


double** rnd_matr(int* n, int* m); // ������� ��� ��������� ��������� �������

void print_matr(double** ma, int n, int m);// ������� ��� ������ �������

void delete_matr(double** ma, int n); // ������� ��� ������������ ������

double** rotate_matr(double** ma, int n, int m);// ������� ��� �������� ������� �� 90� ������ ������� �������


// ������� ��� �������� ��������� ������� ��������� �������
double** rnd_matr(int* n, int* m)
{
    setlocale(LC_ALL, "");
    cout << "������� ���������� �����: ";
    cin >> *n;
    cout << "������� ���������� ��������: ";
    cin >> *m;
    double** ma = new double* [*n]; // �������� ������� ���������� �� ������
    for (int i = 0; i < *n; i++)
        ma[i] = new double[*m]; // �������� ������ ������ �������

    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            ma[i][j] = rand() / (double)100 - 100;

    return ma; // ������� ��������� �� �������
}

// ������� �������
void print_matr(double** ma, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%.2f ", ma[i][j]); // ������ �������� �������
        cout << endl << endl;;
    }
}

// ������� ��� ������������ ������, ������� ��������
void delete_matr(double** ma, int n)
{
    for (int i = 0; i < n; i++)
        delete[] ma[i]; // �������� ������ ������
    delete[] ma; // �������� ������� ����������
}

// ������� ��� �������� ������� �� 90� ������ ������� �������
double** rotate_matr(double** ma, int n, int m)
{
    double** rotated = new double* [m]; // �������� ����� ������� ��� �������� ����������
    for (int i = 0; i < m; i++)
        rotated[i] = new double[n]; // �������� ����� ��� ����� �������

    // ������� �������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            rotated[m - 1 - j][i] = ma[i][j]; // ����������� ���������

    return rotated; // ������� ��������� �� ���������� �������
}

int main() 
{
    srand(time(NULL)); // ������������� ���������� ��������� �����
    int n, m; 
    double** matr = rnd_matr(&n, &m); // ��������� ��������� �������

    cout << endl << endl;

    cout << "�������� �������:"<<endl;
    cout << endl;
    print_matr(matr, n, m); // ����� �������� �������

    cout << endl << endl;

    double** rotated_matr = rotate_matr(matr, n, m); // ������� �������

    cout << "���������� ������� �� 90� ������ ������� �������: " << endl;
    cout << endl;

    print_matr(rotated_matr, m, n); // ������ ���������� �������

    delete_matr(matr, n); 

    delete_matr(rotated_matr, m); // ������������ ������

    system("pause"); // ������������ ����� ����������� ���������
    return 0;
}

