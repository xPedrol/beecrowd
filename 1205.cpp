#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>
using namespace std;

int n, m, k;
double p;

typedef pair<int, int> par;

double dijkstra(vector<vector<par>> adj, int inicio, const int fim)
{
    priority_queue<par, vector<par>, greater<par>> q;
    vector<int> distancias(n, INT_MAX);
    distancias[inicio] = 0;
    q.push({0, inicio});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        for (par i : adj[a])
        {
            int i_valor = i.first;
            int i_peso = i.second;
            if (distancias[i_valor] == INT_MAX)
            {
                distancias[i_valor] = distancias[a] + i_peso;
                q.push({distancias[i_valor], i_valor});
            }
            else if (distancias[i_valor] > distancias[a] + i_peso)
            {
                distancias[i_valor] = distancias[a] + i_peso;
                q.push({distancias[i_valor], i_valor});
            }
        }
    }

    if (distancias[fim] == INT_MAX)
    {
        return 0;
    }
    return pow(p, distancias[fim]);
}

int main()
{
    while (cin >> n >> m >> k >> p)
    {
        vector<int> vertices(n, 0);
        vector<vector<par>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            v1--;
            v2--;
            adj[v1].push_back({v2, 0});
            adj[v2].push_back({v1, 0});
        }
        int total_atiradores;
        cin >> total_atiradores;
        for (int i = 0; i < total_atiradores; i++)
        {
            int v;
            cin >> v;
            v--;
            vertices[v]++;
        }

        int inicio, fim;
        cin >> inicio >> fim;
        inicio--;
        fim--;
        for (int i = 0; i < n; i++)
        {
            int peso = 0;
            if (inicio == i)
            {
                peso += vertices[i];
            }
            for (par &filho : adj[i])
            {
                filho.second = peso + vertices[filho.first];
            }
        }
        double probabilidade = dijkstra(adj, inicio, fim);
        probabilidade = probabilidade < 0 ? 0 : probabilidade;
        cout << fixed << setprecision(3) << probabilidade << "\n";
    }
}

// void d(vector<vector<par>> adj, int inicio, int V)
// {
//     priority_queue<par, vector<par>, greater<par>> q;
//     vector<int> distancias(V, INT_MAX);
//     distancias[inicio] = 0;
//     q.push({0, inicio});
//     while (!q.empty())
//     {
//         int valor = q.top().second;
//         for (par i : adj[valor])
//         {
//             int i_distancia = distancias[i.first];
//             int i_peso = i.second;
//             if (i_distancia == INT_MAX)
//             {
//                 distancias[i.first] = distancias[valor] + i_peso;
//                 q.push({distancias[i.first], i.first});
//             }
//             else if (distancias[valor] + i_peso < distancias[i.first])
//             {
//                 distancias[i.first] = distancias[valor] + i_peso;
//                 q.push({distancias[i.first], i.first});
//             }
//         }
//     }
// }

