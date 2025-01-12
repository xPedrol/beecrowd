#include <iostream>

using namespace std;

bool verificar_palavras(string s)
{
    if (s == ".")
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == s.size() - 1 && s[i] == '.')
            continue;
        if (!isalpha(s[i]))
            return false;
    }
    return true;
}

int main()
{
    string simbolo;
    while (getline(cin, simbolo))
    {
        int comprimento_palavras = 0;
        int total_palavras = 0;
        int inicio = -1;
        int comprimento = 0;
        for (int i = 0; i < simbolo.size(); i++)
        {
            if (!isspace(simbolo[i]))
            {
                comprimento++;
                if (inicio == -1)
                {
                    inicio = i;
                }
            }
            if (isspace(simbolo[i]) || i == simbolo.size() - 1)
            {
                if (inicio != -1)
                {
                    string novo_simbolo = simbolo.substr(inicio, comprimento);
                    bool e_palavra = verificar_palavras(novo_simbolo);
                    if (e_palavra)
                    {
                        if (novo_simbolo[comprimento-1] == '.')
                            comprimento_palavras--;
                        comprimento_palavras += novo_simbolo.size();
                        total_palavras++;
                    }
                    inicio = -1;
                    comprimento = 0;
                }
                continue;
            }
        }
        int comprimento_medio = total_palavras > 0 ? comprimento_palavras / total_palavras : 0;
        int nota;
        if (comprimento_medio <= 3)
        {
            nota = 250;
        }
        if (comprimento_medio == 4 || comprimento_medio == 5)
        {
            nota = 500;
        }
        if (comprimento_medio >= 6)
        {
            nota = 1000;
        }
        cout << nota << "\n";
    }
}