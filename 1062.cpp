#include <iostream>
#include <stack>

using namespace std;

int main()
{

    while (true)
    {
        int vagoes;
        cin >> vagoes;
        if (vagoes == 0)
            break;
        bool stop = false;
        while (true)
        {
            int vagao;
            int v[vagoes];
            for (int i = 0; i < vagoes; i++)
            {
                cin >> vagao;
                if (vagao == 0)
                    break;
                v[i] = vagao;
            }
            if (vagao == 0)
                break;

            stack<int> st;
            int entrada_atual = 1;

            bool saida_valida = true;
            for (int i = 0; i < vagoes; i++)
            {
                vagao = v[i];
                if (vagao < entrada_atual)
                {
                    if (st.top() == vagao)
                    {
                        st.pop();
                        continue;
                    }
                    saida_valida = false;
                    break;
                }
                while (vagao > entrada_atual)
                {
                    st.push(entrada_atual);
                    entrada_atual++;
                }
                if (vagao == entrada_atual)
                {
                    entrada_atual++;
                }
            }
            if (!stop)
            {
                if (saida_valida)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}