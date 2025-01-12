#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int> &seq, vector<int> &aux, int left, int mid, int right)
{
    for (int i = left; i <= right; ++i)
    {
        aux[i] = seq[i];
    }

    int i = left, j = mid + 1, k = left, inversoes = 0;

    while (i <= mid && j <= right)
    {
        if (aux[i] <= aux[j])
        {
            seq[k++] = aux[i++];
        }
        else
        {
            seq[k++] = aux[j++];
            inversoes += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        seq[k++] = aux[i++];
    }
    while (j <= right)
    {
        seq[k++] = aux[j++];
    }

    return inversoes;
}

int mergeSortAndCount(vector<int> &seq, vector<int> &aux, int left, int right)
{
    int inversoes = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        inversoes += mergeSortAndCount(seq, aux, left, mid);
        inversoes += mergeSortAndCount(seq, aux, mid + 1, right);
        inversoes += mergeAndCount(seq, aux, left, mid, right);
    }
    return inversoes;
}

string vencedor(vector<int> &seq)
{
    vector<int> aux(seq.size());
    int inversoes = mergeSortAndCount(seq, aux, 0, seq.size() - 1);
    if (inversoes % 2 == 0)
    {
        return "Carlos";
    }
    else
    {
        return "Marcelo";
    }
}
int main()
{
    int total;
    while (true)
    {
        cin >> total;
        if (total == 0)
            break;

        vector<int> vetor(total);
        for (int i = 0; i < total; i++)
        {
            cin >> vetor[i];
        }
        cout << vencedor(vetor) << endl;
    }

    return 0;
}
