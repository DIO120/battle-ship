#include<fstream>
#include<iostream>
using namespace std;

int main() {
    int n;
    ifstream f("e:\\d).txt");
    f >> n;
    int* a;
    a = new int[n];
    for (size_t i = 0; i < n; i++)
        f >> a[i];
    f.close();

    int s = 0;
    for (size_t i = 0; i < n; i++)
        s = s + a[i];

    cout << "Sa=" << double(s) / n << endl;

    delete[] a;
    return 0;
}
