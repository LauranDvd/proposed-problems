#include <iostream>
#include <algorithm>
using namespace std;

const int N_MAX = 100000;
const int A_MAX = 1000000000;

int n, a[N_MAX + 1];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    long long suma = 0;
    int nrGrupe = 0;
    int frecvCurenta = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] == a[i + 1])
            frecvCurenta++;
        else
        {
            suma += 1LL * min(frecvCurenta, nrGrupe) * a[i + 1];
            nrGrupe = max(nrGrupe, frecvCurenta);
            frecvCurenta = 1;
        }
    }
    suma += 1LL * min(frecvCurenta, nrGrupe) * a[1];

    cout << suma;

    return 0;
}
