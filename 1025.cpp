#include <iostream>
#include <algorithm>

using namespace std;

int busca_binaria(int *vetor, int inicio, int fim, int valor)
{
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if(vetor[meio] == valor) {
            if(inicio == fim) return meio;
            fim = meio;
            continue;
        }
        if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }
        if (vetor[meio] > valor)
        {
            fim = meio - 1;
        }
    }
    return -1;
}

int main()
{
    int quant_tabuas, quant_buscas, cases = 0;
    
    while (true)
    {
        cin >> quant_tabuas >> quant_buscas;
        int *tabuas = new int[quant_tabuas];
        if (quant_tabuas == 0 && quant_buscas == 0)
            break;
        printf("CASE# %d:\n", cases + 1);

        for (int i = 0; i < quant_tabuas; i++)
        {
            int v;
            cin >> v;
            tabuas[i] = v;
        }
        sort(tabuas, tabuas + quant_tabuas);
        for (int i = 0; i < quant_buscas; i++)
        {
            int busca;
            cin >> busca;
            int p = busca_binaria(tabuas, 0, quant_tabuas - 1, busca);
            // int *p = upper_bound(tabuas, tabuas + quant_tabuas, busca);
            if (p == -1)
            {
                printf("%d not found\n", busca);
            }
            else
                printf("%d found at %d\n", busca, p + 1);
        }
        cases++;
        delete[] tabuas;
    }
    

    return 0;
}