#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 0; i < N; i++)
    {
        string numero;
        cin >> numero;
        int soma = 0;
        for (int j = 0; j < numero.size(); j++)
        {
            int n1 = numero[j] - '0';
            soma += leds[n1];
        }
        printf("%d leds\n", soma);
    }
}