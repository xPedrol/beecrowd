#include <iostream>
using namespace std;

int main()
{
    int t, contador = 0;
    cin >> t;
    for (int i = 0; i < 5; i++)
    {
        int v;
        cin >> v;
        if(v == t) contador++;
    }

    cout << contador << "\n";

    return 0;
}