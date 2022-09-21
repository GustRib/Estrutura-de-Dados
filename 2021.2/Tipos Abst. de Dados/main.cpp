#include <iostream>

using namespace std;

class Aluno
{
    private:
        int matricula;
        int idade;
        float notas [3];

    public:
        void leAluno();
        void imprimeAluno();
};

void Aluno::leAluno()
{
        cout << "Digite a matricula: ";
        cin >> matricula; 
        cout << "Digite a idade: ";
        cin >> idade;
        while(!(idade >= 0 && idade <= 120))
    {
            cout << "Idade incorreta. Digite novamente: ";
            cin >> idade;
    }

        for(int i = 0; i < 3; i++)
        {
            cout << "Digite a nota " << i << ": ";
            cin >> notas[i];
        }
}

void Aluno::imprimeAluno()
{
        cout << "Matricula: " << matricula << endl;
        cout << "Idade: " << idade << endl;
        for(int i = 0; i < 3; i++)
            cout << "Nota " << i << ": " << notas[i] << endl;
}

int main()
{
        Aluno a;
        a.leAluno();
        //a.idade = -23;
        a.imprimeAluno();
        return 0;
}