#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countWordOccurrences(const string& text, const string& word) {
    int count = 0;
    size_t pos = 0;

    while ((pos = text.find(word, pos)) != string::npos) {
        count++;
        pos += word.length();
    }

    return count;
}

int countSentences(const string& text) {
    int sentenceCount = 0;

    for (char ch : text) {
        if (ch == '.' || ch == '!') { // Проверяем символы конца предложения
            sentenceCount++;
        }
    }

    return sentenceCount;
}

int main() {
    setlocale(LC_ALL, "ru");
    string inputText;
    cout << "Введите текст: ";
    getline(cin, inputText);

    string reversedText(inputText);
    reverse(reversedText.begin(), reversedText.end());

    cout << "\nПеревернутый текст:\n" << reversedText << endl;

    size_t dotCount = count (inputText.begin(), inputText.end(), '.');
    size_t commaCount = count (inputText.begin(), inputText.end(), ',');

    cout << " Количество точек:" << dotCount << "\n";
    cout << " Количество запятых:" << commaCount << "\n\n";

    int totalSentences = countSentences (inputText);

    cout << " Общее количество предложений в тектс е:" << totalSentences << endl;

    // Разделение текста на предложени я и переворот каждого предложения
    cout << "\nКаждое предложение, перевернутое:\n";

    string sentence;
    for (char ch : inputText) {
        if (ch == '.' || ch == '!') { // Найдено конечное предложение
            reverse(sentence.begin(), sentence.end());
            cout << sentence << ch; // Выводим перевернутое предло жени е с символом препинания

            sentence.clear(); // Очищаем буфер для следующего предложения 
        }
        else {
            sentence += ch; // Добавляем символы в текущее  прадложениие  
        }
    }

    return 0;
}
