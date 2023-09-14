#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    string str = "Дана строка символов. Заменить в ней все пробелы на таблиции";

    // Проходим по каждому символу строки и заменяем пробелы на '\t'
    for (char& c : str) {
        if (c == ' ') {
            c = '\t';
        }
    }

    cout << "Результат: " << str << std::endl;

    return 0;
}
