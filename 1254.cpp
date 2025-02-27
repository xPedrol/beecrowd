#include <iostream>
#include <string>

using namespace std;
bool achar_tag(string &texto, string &tag, int inicio)
{
    int fim = tag.size();
    if (inicio + fim > texto.size())
        return false;
    for (int i = 0; i < fim; i++)
    {
        if (tolower(tag[i]) != tolower(texto[inicio + i]))
            return false;
    }

    return true;
}
string gerar_nova_tag(string &tag, string &numero, string &texto)
{
    string nova_tag;
    int sinal_tag = 0, i = 0;
    while (i < texto.size())
    {
        if (texto[i] != '<' && texto[i] != '>')
        {
            if (sinal_tag > 0 && achar_tag(texto, tag, i))
            {
                // verificar se achamos nossa tag
                nova_tag += numero;
                i += tag.size();
            }
            else
            {
                nova_tag.push_back(texto[i]);
                i++;
            }
        }
        else if (texto[i] == '<')
        {
            sinal_tag++;
            nova_tag.push_back('<');
            i++;
        }
        else
        {
            sinal_tag = 0;
            nova_tag.push_back('>');
            i++;
        }
    }
    return nova_tag;
}
int main()
{
    string tag, numero, texto;
    while (cin >> tag)
    {
        cin >> numero;
        cin.ignore();
        getline(cin, texto);
        cout << gerar_nova_tag(tag, numero, texto) << "\n";
    }
}