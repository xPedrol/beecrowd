#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>> &adjacencias, vector<int> &visitados, const int inicio, int &maior)
{
    for (int i : adjacencias[inicio])
    {
        if (visitados[i] < visitados[inicio] + 1)
        {
            visitados[i] = visitados[inicio] + 1;
            if (visitados[i] > maior)
                maior = visitados[i];
        }
        dfs(adjacencias, visitados, i, maior);
    }
    return 1;
}

// void bfs(vector<vector<int>> &adjacencias, vector<int> &visitados, const int inicio)
// {
//     queue<int> q;
//     visitados[inicio]++;
//     q.push(inicio);
//     while (!q.empty())
//     {
//         int atual = q.front();
//         q.pop();
//         for (int i : adjacencias[atual])
//         {
//             if (visitados[i] == 0)
//             {
//                 q.push(i);
//             }
//             visitados[i] = visitados[atual] + 1;
//         }
//     }
// }

bool substring(string s1, string s2)
{
    for (int i = 0; i < s2.size(); i++)
    {
        string segmento = s2.substr(i, s1.size());
        if (segmento == s1)
            return true;
    }
    return false;
}

bool ordenar(string s1, string s2)
{
    return s1.size() < s2.size();
}
int main()
{
    while (true)
    {
        int total_strings;
        cin >> total_strings;
        if (total_strings == 0)
            break;
        cin.ignore();
        vector<string> strings;
        vector<vector<int>> adjacencias(total_strings);
        for (int i = 0; i < total_strings; i++)
        {
            string palavra;
            getline(cin, palavra);
            strings.push_back(palavra);
        }
        // sort(strings.begin(), strings.end(), ordenar);
        // cout << "===================\n\n";
        // for (int i = 0; i < strings.size(); i++)
        // {
        //     cout << i << " - " << strings[i] << "\n";
        // }
        for (int i = 0; i < strings.size(); i++)
        {
            for (int j = 0; j < strings.size(); j++)
            {
                if (strings[i].size() > strings[j].size() || strings[i] == strings[j])
                    continue;
                if (substring(strings[i], strings[j]))
                    adjacencias[i].push_back(j);
            }
        }
        vector<int> visitados(total_strings, 1);
        int maior = 0;
        for (int i = 0; i < total_strings; i++)
        {
            if (visitados[i] == 1)
            {
                dfs(adjacencias, visitados, i, maior);
            }
        }
        cout << maior << "\n";
    }

    return 0;
}