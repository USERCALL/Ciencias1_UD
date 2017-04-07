/*******************************************************************************
Determina el t(n) de algoritmo
*******************************************************************************/

#include <cstdlib>
#include <iostream>


using namespace std;

int main(int argc, char * argv[]) {
    cout<<"Determina el t(n) de algoritmo"<<endl;
    int N, i, j;
    int * A;
    int size = 0;
    cin >> N;
    for (i = 0; i < N; i++) {
        A = new int[N];
        for (j = 0; j < N; j++) {
            A[j] = i * j;
            cout << A[j] << endl;

        }
        size += sizeof(A);
        delete[] A;
        cout << endl;
    }
    cout << size + sizeof(N) + sizeof(i) + sizeof(j) + sizeof(A) << endl;
    system("PAUSE");
}
