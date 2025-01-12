#include <iostream>
#include <list>
#include <cmath>
using namespace std;
typedef pair<int, int> dupla;
int n, k, m;

dupla escolher(list<int> &desempregados, list<int>::iterator &horario, list<int>::iterator &anti_horario, list<int>::iterator &ultimo)
{
    if (desempregados.size() == 1)
    {
        int valor = *desempregados.begin();
        desempregados.erase(desempregados.begin());
        return {valor, valor};
    }
    list<int>::iterator primeiro, segundo;
    for (int i = 0; i < max(k + 1, m + 1); i++)
    {
        if (i < k + 1)
        {
            if (horario == desempregados.end())
            {
                horario = desempregados.begin();
            }
            if (i == k - 1)
                primeiro = horario;
            if (i < k)
                horario++;
        }
        if (i < m + 1)
        {
            if (anti_horario == desempregados.end())
            {
                anti_horario = ultimo;
            }
            if (i == m - 1)
                segundo = anti_horario;
            if (i < m)
                anti_horario--;
        }
    }
    dupla estg = {*primeiro, *segundo};

    if (segundo == ultimo || primeiro == ultimo)
    {
        int total = desempregados.size();
        auto aux = ultimo == primeiro ? primeiro : segundo;
        while (aux == primeiro || aux == segundo)
        {
            aux--;
        }
        ultimo = aux;
    }

    if (primeiro == anti_horario || segundo == anti_horario)
        anti_horario = desempregados.end(); // n faz sentido. precisa ir para a prox posicao valida
    if (primeiro == horario || segundo == horario)
        horario = desempregados.end(); // n faz sentido. precisa ir para a prox posicao valida
    desempregados.erase(primeiro);
    if (primeiro != segundo)
        desempregados.erase(segundo);
    return estg;
}

string gerar_espacos(int numero)
{
    int total_algaritmos = log10(abs(numero)) + 1;
    int total_algaritmos_faltando = 3 - total_algaritmos;
    if (total_algaritmos_faltando == 2)
        return "  ";

    if (total_algaritmos_faltando == 1)
        return " ";
    return "";
}
int main()
{

    // n total de funcionarios
    // k movimentos horarios
    // m movimentos anti-horarios

    while (true)
    {
        list<dupla> duplas;
        list<int> desempregados;
        cin >> n >> k >> m;
        if (n + k + m == 0)
            break;
        // k = k % n;
        // m = m % n;
        list<int>::iterator horario;
        list<int>::iterator anti_horario;
        list<int>::iterator ultimo;
        for (int i = 0; i < n; i++)
        {
            desempregados.push_back(i + 1);
            if (i == 0)
            {
                horario = anti_horario = desempregados.begin();
            }
            else
            {
                anti_horario++;
            }
        }
        ultimo = anti_horario;
        while (!desempregados.empty())
        {
            duplas.push_back(escolher(desempregados, horario, anti_horario, ultimo));
        }
        for (auto it = duplas.begin(); it != duplas.end(); it++)
        {
            int primeiro = (*it).first;
            int segundo = (*it).second;
            cout << gerar_espacos(primeiro) << primeiro;
            if (primeiro != segundo)
            {
                cout << gerar_espacos(segundo) << segundo;
            }
            auto aux = it;
            if (++aux != duplas.end())
            {
                cout << ",";
            }
        }
        cout << "\n";
    }
}