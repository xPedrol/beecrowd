#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int N1, N2, D1, D2;
        char operacao, lixo;
        cin >> N1 >> lixo >> D1 >> operacao >> N2 >> lixo >> D2;
        int numerador, denominador;
        switch (operacao)
        {
        case '+':
            numerador = N1 * D2 + N2 * D1;
            denominador = D1 * D2;
            break;
        case '-':
            numerador = N1 * D2 - N2 * D1;
            denominador = D1 * D2;
            break;

        case '*':
            numerador = N1 * N2;
            denominador = D1 * D2;
            break;

        case '/':
            numerador = N1 * D2;
            denominador = N2 * D1;
            break;

        default:
            break;
        }
        cout << numerador << "/" << denominador;
        int divisores[5] = {2, 3, 5, 7, 13};
        int atual = 0;
        while (true)
        {
            int divisor = divisores[atual];
            if (numerador % divisor == 0 && denominador % divisor == 0)
            {
                numerador /= divisor;
                denominador /= divisor;
            }
            else
            {
                atual++;
                if (atual >= 5)
                    break;
            }
        }
        cout << " = " << numerador << "/" << denominador << "\n";
    }

    return 0;
}