#include <iostream>

using namespace std;
struct Aluno
{
    string nome, aulas;
};

bool nao_pode_fazer_teste(Aluno aluno)
{
    int presenca = 0;
    int total = aluno.aulas.size();
    for (char aula : aluno.aulas)
    {
        if (aula == 'P')
            presenca++;
        if (aula == 'M')
            total--;
    }
    int n = ((float)presenca / (float)total) * 100;
    return n < 75;
}
int main()
{
    int T;
    cin >> T;
    for (int j = 0; j < T; j++)
    {
        int N;
        cin >> N;
        Aluno alunos[100];
        int sem_teste[100];
        int k = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> alunos[i].nome;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> alunos[i].aulas;
            if (nao_pode_fazer_teste(alunos[i]))
            {
                sem_teste[k] = i;
                k++;
            }
        }
        for (int i = 0; i < k; i++)
        {
            int index = sem_teste[i];
            cout << alunos[index].nome;
            if (i < k - 1)
            {
                cout << " ";
            }
        }

        cout << "\n";
    }
}