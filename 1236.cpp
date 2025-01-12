#include <iostream>
#include <string>
using namespace std;

bool verificar_diferenca(const string &linha, const int &index)
{
    if (index > 0)
    {
        char caractere1 = linha[index];
        char caractere2 = linha[index - 1];
        bool espaco_nulo1 = caractere1 == '0' || isspace(caractere1);
        bool espaco_nulo2 = caractere2 == '0' || isspace(caractere2);
        return espaco_nulo1 && espaco_nulo2 && caractere1 != caractere2;
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        string linha;
        string nova_linha;
        getline(cin, linha);
        int total_trash = 0;
        for (int i = 0; i < linha.size(); i++)
        {
            char caractere = linha[i];
            bool espaco_nulo = caractere == '0' || isspace(caractere);
            bool espaco_nulo_dif = verificar_diferenca(linha, i);
            auto preencher_nova_linha = [&](char _caractere)
            {
                if (total_trash > 2)
                {
                    nova_linha = nova_linha + (_caractere == '0' ? '#' : '$') + char(total_trash);
                    total_trash = 0;
                }
                else if (total_trash > 0 && total_trash < 3)
                {
                    for (int j = 0; j < total_trash; j++)
                    {
                        nova_linha += _caractere;
                    }
                    total_trash = 0;
                }
            };
            if (espaco_nulo && !espaco_nulo_dif)
            {
                total_trash++;
                if (total_trash == 255)
                {
                    nova_linha = nova_linha + (caractere == '0' ? '#' : '$') + char(total_trash);
                    total_trash = 0;
                }
                if (i == linha.size() - 1)
                {
                    preencher_nova_linha(caractere);
                }
            }
            else
            {
                preencher_nova_linha(linha[i-1]);
                if (!espaco_nulo_dif)
                {
                    nova_linha += caractere;
                }
                else
                {
                    total_trash++;
                }
            }
        }
        cout << nova_linha << "\n";
    }

    return 0;
}
