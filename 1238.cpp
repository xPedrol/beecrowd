#include <iostream>

using namespace std;

string combinar_palavras(string &p1, string &p2)
{
    string nova = "";
    int contador = 0;
    while (p1.size() > contador && p2.size() > contador)
    {
        nova.push_back(p1[contador]);
        nova.push_back(p2[contador++]);
    }
    while (p1.size() > contador)
    {
        nova.push_back(p1[contador++]);
    }
    while (p2.size() > contador)
    {
        nova.push_back(p2[contador++]);
    }
    return nova;
}

int main()
{
    int n;
    string p1, p2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p1 >> p2;
        cout << combinar_palavras(p1, p2) + "\n";
    }
}