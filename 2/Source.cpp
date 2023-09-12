#include<fstream>
#include<iostream>
using namespace std;

int main() {
    
    int n = 0;
    ifstream f("e:\\data.txt");
    while (!f.eof()) {    // End Of File
        f >> a[n];
        n++;
    }
    f.close();

    int s = 0;
    for (size_t i = 0; i < n; i++)
        s = s + a[i];

    cout << "Sa=" << double(s) / n << endl;
    cout << "n=" << n << endl;

    return 0;
}
