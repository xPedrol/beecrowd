#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<bool>> &adj, vector<bool> &visitados, int v, int espacos, int &total_visitados)
{
    visitados[v] = true;
    total_visitados++;
    bool vazio = true;
    for (int i = 0; i < adj[v].size(); i++)
    {
        bool filho = adj[v][i];
        if (!filho)
            continue;
        vazio = false;
        for (int j = 0; j < espacos; j++)
        {
            printf("  ");
        }
        if (!visitados[i])
        {
            printf("%d-%d pathR(G,%d)\n", v, i, i);
        }
        else
        {
            printf("%d-%d\n", v, i);
        }
        if (!visitados[i])
            dfs(adj, visitados, i, espacos + 1, total_visitados);
    }
    if (espacos == 1 && !vazio && total_visitados != visitados.size())
    {
        printf("\n");
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        printf("Caso %d:\n", i + 1);
        int n_vertices, n_arestas;
        cin >> n_vertices >> n_arestas;
        vector<vector<bool>> adj(n_vertices, vector<bool>(n_vertices, false));
        vector<bool> visitados(n_vertices);
        int total_visitados = 0;
        int v1, v2;
        for (int j = 0; j < n_arestas; j++)
        {
            cin >> v1 >> v2;
            adj[v1][v2] = true;
            // adj[v2][v1] = true;
        }
        // sort(adj[v1].begin(), adj[v1].end());
        for (int j = 0; j < n_vertices; j++)
        {
            if (!visitados[j])
                dfs(adj, visitados, j, 1, total_visitados);
        }
        if (i < n - 1)
        {
            printf("\n");
        }
    }
}