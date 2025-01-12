#include <iostream>
using namespace std;

void criptografar(string &palavra)
{
    for (int i = 0; i < palavra.size(); i++)
    {
        palavra[i] = isalpha(palavra[i]) ? palavra[i] + 3 : palavra[i];
        if (i <= (palavra.size()-1) / 2)
        {
            palavra[i] = palavra[i] - 1;
        }
    }
}
int main()
{
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        string palavra;
        getline(cin, palavra);
        criptografar(palavra);
        for (int i = palavra.size()-1; i >= 0; i--)
        {
            printf("%c",palavra[i]);
        }
        printf("\n");
        
    }

    return 0;
}