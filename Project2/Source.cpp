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
        if (ch == '.' || ch == '!') { // ��������� ������� ����� �����������
            sentenceCount++;
        }
    }

    return sentenceCount;
}

int main() {
    setlocale(LC_ALL, "ru");
    string inputText;
    cout << "������� �����: ";
    getline(cin, inputText);

    string reversedText(inputText);
    reverse(reversedText.begin(), reversedText.end());

    cout << "\n������������ �����:\n" << reversedText << endl;

    size_t dotCount = count (inputText.begin(), inputText.end(), '.');
    size_t commaCount = count (inputText.begin(), inputText.end(), ',');

    cout << " ���������� �����:" << dotCount << "\n";
    cout << " ���������� �������:" << commaCount << "\n\n";

    int totalSentences = countSentences (inputText);

    cout << " ����� ���������� ����������� � ����� �:" << totalSentences << endl;

    // ���������� ������ �� ���������� � � ��������� ������� �����������
    cout << "\n������ �����������, ������������:\n";

    string sentence;
    for (char ch : inputText) {
        if (ch == '.' || ch == '!') { // ������� �������� �����������
            reverse(sentence.begin(), sentence.end());
            cout << sentence << ch; // ������� ������������ ������ ���� � � �������� ����������

            sentence.clear(); // ������� ����� ��� ���������� ����������� 
        }
        else {
            sentence += ch; // ��������� ������� � �������  ������������  
        }
    }

    return 0;
}
