#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    srand(time(NULL));
    //a
    int** a;
    a = new int* [n];
    for (size_t i = 0; i < n; i++)
        a[i] = new int[m];

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            a[i][j] = rand() % 100;

    //b

    //c

    // вывод с

    delete[] a;
    //b
    //c

    
    for (size_t i = 0; i < M; i++)
        for (size_t j = 0; j < K; j++)
        {
            c[i][j] = 0;
            for (size_t k = 0; k < N; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    
    return 0;
}
