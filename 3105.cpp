#include <iostream>
#include <cmath>
using namespace std;

pair<double, double> pode_dobrar(double &novo_valor, const double &N, double &X, const double &Y)
{
    double valor_antigo = novo_valor;
    double double_n = static_cast<double>(N);
    novo_valor = double_n / (X + 1);
    double altura = (X + 1) * (Y + 1);
    return make_pair(altura, valor_antigo);
}

int main()
{
    int K;
    double N, M, x = 0, y = 0;
    cin >> N >> M >> K;
    double novo_n = N;
    double novo_m = M;

    while (true)
    {
        if (max(novo_m, novo_n) == novo_n)
        {
            x++;
            auto v = pode_dobrar(novo_n, N, x, y);
            if (v.first > K)
            {
                cout << static_cast<long long int>(ceil(v.second)) << "\n";
                break;
            }
        }
        else
        {
            y++;
            auto v = pode_dobrar(novo_m, M, y, x);
            if (v.first > K)
            {
                cout << static_cast<long long int>(ceil(v.second)) << "\n";
                break;
            }
        }
    }
}
