#include <vector>
#include <queue>
#include <iostream>
using namespace std;

short int N;

int get_cima(const int x)
{
    int n_x = x - 1;
    if (n_x < 0)
        return -1;
    return n_x;
}
int get_baixo(const int x)
{
    int n_x = x + 1;
    if (n_x >= N)
        return -1;
    return n_x;
}

int get_esquerda(const int y)
{
    int n_y = y - 1;
    if (n_y < 0)
        return -1;
    return n_y;
}

int get_direita(const int y)
{
    int n_y = y + 1;
    if (n_y >= N)
        return -1;
    return n_y;
}
int get_posicao(const int x, const int y)
{
    return N * x + y;
}

pair<int, int> get_xy(const int posicao)
{
    int x = posicao / N;
    int y = posicao % N;
    return make_pair(x, y);
}

bool posicao_correta(queue<int> &fila, int pai, int direcao)
{
    auto filho_xy = get_xy(fila.front());
    auto pai_xy = get_xy(pai);
    // cima
    if (direcao == 0)
    {
        int novo_x = get_cima(pai_xy.first);
        return filho_xy.first == novo_x && filho_xy.second == pai_xy.second;
    }
    // baixo
    if (direcao == 1)
    {
        int novo_x = get_baixo(pai_xy.first);
        return filho_xy.first == novo_x && filho_xy.second == pai_xy.second;
    }
    // esquerda
    if (direcao == 2)
    {
        int novo_y = get_esquerda(pai_xy.second);
        return filho_xy.second == novo_y && filho_xy.first == pai_xy.first;
    }
    // direita
    if (direcao == 3)
    {
        int novo_y = get_direita(pai_xy.second);
        return filho_xy.second == novo_y && filho_xy.first == pai_xy.first;
    }
    return false;
}

bool todos_sairam(int a, int b, int c, vector<int> &saidas)
{
    int sairam = 0;
    for (int saida : saidas)
    {
        sairam += a == saida ? 1 : 0;
        sairam += b == saida ? 1 : 0;
        sairam += c == saida ? 1 : 0;
        if (sairam == 3)
            return true;
    }
    return false;
}

int main()
{
    short int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        vector<vector<int>> adj(N * N, vector<int>(4, -1));
        vector<char> valores(N * N);
        vector<int> saidas;
        vector<int> robos;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                char valor;
                cin >> valor;
                int posicao = get_posicao(j, k);
                if (isalpha(valor))
                {
                    if (valor == 'X')
                    {
                        saidas.push_back(posicao);
                    }
                    else
                    {
                        robos.push_back(posicao);
                    }
                }
                valores[posicao] = valor;
                int cima = get_cima(j);
                int baixo = get_baixo(j);
                int esquerda = get_esquerda(k);
                int direita = get_direita(k);
                if (cima > -1)
                {
                    adj[posicao][0] = get_posicao(cima, k);
                }
                if (baixo > -1)
                {
                    adj[posicao][1] = get_posicao(baixo, k);
                }
                if (esquerda > -1)
                {
                    adj[posicao][2] = get_posicao(j, esquerda);
                }
                if (direita > -1)
                {
                    adj[posicao][3] = get_posicao(j, direita);
                }
            }
        }
        int a_saiu = -1, b_saiu = -1, c_saiu = -1;
        vector<int> visitadosA(N * N, 0), visitadosB(N * N, 0), visitadosC(N * N, 0);
        queue<pair<int, int>> qA, qB, qC;
        visitadosA[robos[0]] = 1, visitadosB[robos[1]] = 1, visitadosC[robos[2]] = 1;
        qA.push(make_pair(-1, robos[0])), qB.push(make_pair(-1, robos[1])), qC.push(make_pair(-1, robos[2]));
        bool stop = false;
        int direcao_atual = -1;
        while (!qA.empty() || !qB.empty() || !qC.empty())
        {
            if (a_saiu != -1 && b_saiu != -1 && c_saiu != -1)
                break;
            auto par_vazio = make_pair(-1, -1);
            // <direcao,valor>
            pair<int, int> a = !qA.empty() ? qA.front() : par_vazio, b = !qB.empty() ? qB.front() : par_vazio, c = !qC.empty() ? qC.front() : par_vazio;
            if (direcao_atual != a.first)
                a.second = -1;
            else
                qA.pop();

            if (direcao_atual != b.first)
                b.second = -1;
            else
                qB.pop();
            if (direcao_atual != c.first)
                c.second = -1;
            else
                qC.pop();
            for (int j = 0; j < 4; j++)
            {
                if (a_saiu == -1)
                {
                    int filhoA = a.second != -1 ? adj[a.second][j] : -1;
                    if (filhoA != -1 && valores[filhoA] != '#' && visitadosA[filhoA] == 0)
                    {
                        if (filhoA == saidas[0] || filhoA == saidas[1] || filhoA == saidas[2])
                        {
                            a_saiu = visitadosA[a.second] + 1;
                        }
                        else
                        {
                            qA.push(make_pair(j, filhoA));
                            visitadosA[filhoA] = visitadosA[a.second] + 1;
                        }
                    }
                }
                if (b_saiu == -1)
                {
                    int filhoB = b.second != -1 ? adj[b.second][j] : -1;
                    if (filhoB != -1 && valores[filhoB] != '#' && visitadosB[filhoB] == 0)
                    {
                        if (filhoB == saidas[0] || filhoB == saidas[1] || filhoB == saidas[2])
                        {
                            b_saiu = visitadosB[b.second] + 1;
                        }
                        else
                        {
                            qB.push(make_pair(j, filhoB));
                            visitadosB[filhoB] = visitadosB[b.second] + 1;
                        }
                    }
                }
                if (c_saiu == -1)
                {
                    int filhoC = c.second != -1 ? adj[c.second][j] : -1;
                    if (filhoC != -1 && valores[filhoC] != '#' && visitadosC[filhoC] == 0)
                    {
                        if (filhoC == saidas[0] || filhoC == saidas[1] || filhoC == saidas[2])
                        {
                            c_saiu = visitadosC[c.second] + 1;
                        }
                        else
                        {
                            qC.push(make_pair(j, filhoC));
                            visitadosC[filhoC] = visitadosC[c.second] + 1;
                        }
                    }
                }
            }
            direcao_atual = direcao_atual == -1 ? 0 : (++direcao_atual) % 4;
        }
        int max_passos = max(max(c_saiu, b_saiu), a_saiu);
        int min_passos = min(min(c_saiu, b_saiu), a_saiu);
        cout << "Case " << i + 1 << ": ";
        if (min_passos == -1)
        {
            cout << "trapped\n";
        }
        else
        {
            cout << max_passos - 1 << "\n";
        }
    }
}