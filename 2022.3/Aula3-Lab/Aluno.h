#ifdef ALUNO_HPP_INCLUDED
#define ALUNO_HPP_INCLUDED

class Aluno
{
    private:
        int idade;
        char *nome[40], *matricula[15];
        double notas[7];
        void atribui();
    public:
        Aluno(char n, char mat);
        ∼Aluno();
        // operacoes
        void leNotas();        // exercicio 1
        double calculaMedia(); // exercicio 1
        void setIdade(int id){idade = id;};
        int getIdade(){return idade;};

        void setMatricula(char mat[]);
        char* getMatricula();

        //getNome
        //setNome
};

#endif // ALUNO_HPP_INCLUDED