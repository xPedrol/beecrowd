#include <iostream>
using namespace std;

void find(char v, string s)
{
}

int main()
{
    string palavra1;
    string palavra2;
    while (getline(cin, palavra1))
    {
        getline(cin, palavra2);
        int maior = 0;
        if (palavra1 == palavra2)
        {
            maior = palavra1.size();
        }
        else
        {
            for (int i = 0; i < palavra1.size(); i++)
            {
                int j = 0;
                while (j < palavra2.size())
                {
                    if (palavra1[i] == palavra2[j])
                    {
                        int aux = 0;
                        int k = 0;
                        while (palavra1[i + k] == palavra2[j + k])
                        {
                            k++;
                            aux++;
                            if (i + k > palavra1.size() - 1 || j + k > palavra2.size() - 1)
                                break;
                        }
                        if (aux > maior)
                            maior = aux;
                        j += k;
                        continue;
                    }
                    j++;
                }
            }
        }
        cout << maior << "\n";
    }
}