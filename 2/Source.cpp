#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    string str = "���� ������ ��������. �������� � ��� ��� ������� �� ��������";

    // �������� �� ������� ������� ������ � �������� ������� �� '\t'
    for (char& c : str) {
        if (c == ' ') {
            c = '\t';
        }
    }

    cout << "���������: " << str << std::endl;

    return 0;
}
