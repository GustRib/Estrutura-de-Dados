#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class No
{
private:
    int info; /// valor armazenado no No
    No *prox; /// ponteiro para o proximo No
public:
    No()                  { }; // construtor 
    ~No()                 { }; // destrutor
    int getInfo()         { return info; }; // retorna todas as informaçoes do nó
    No* getProx()         { return prox; }; // passa para o proximo nó
    void setInfo(int val) { info = val; }; // define as informaçoes a serem passadas pela val
    void setProx(No *p)   { prox = p; }; // define quem será o proximo nó da lista
};
#endif // NO_H_INCLUDED
