#include <iostream>

using namespace std;
string adicionarHTML(string &texto);
int main()
{
    string texto;
    while (getline(cin, texto))
    {
        cout << adicionarHTML(texto) << "\n";
    }
}
string adicionarHTML(string &texto)
{
    int italico = 0;
    int bold = 0;
    string novo_texto;
    for (char &letra : texto)
    {
        if (letra == '_')
        {
            if (italico == 1)
            {
                novo_texto += "</i>";
                italico = 0;
            }
            else
            {
                novo_texto += "<i>";
                italico++;
            }
        }
        else if (letra == '*')
        {
            if (bold == 1)
            {
                novo_texto += "</b>";
                bold = 0;
            }
            else
            {
                novo_texto += "<b>";
                bold++;
            }
        }
        else
        {
            novo_texto.push_back(letra);
        }
    }
    return novo_texto;
}