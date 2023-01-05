    l.imprime();
    l.insereInicio(10);

    l.imprime();

    // exercicio 1
    int indice = l.buscaMaior(10);
    if (indice != -1)
        cout << "Elemento maior: " << l.get(indice) << endl;
    else
        cout << "Nao foi encontrado valor maior na lista." << endl;

    l.limpar();
    l.imprime();

    // exercicio 2
    int vet[6] = { 11,12,13,14,15,16 };
    l.insereValores(6, vet);

    l.imprime();

    int vet2[4] = { 17,18,19,20 };
    l.insereValores(4, vet2);

    l.imprime();

    // exercicio 3

        ListaCont L1(50), L2(25), L3(25);

    for (int i = 0; i < 50; i++) {
        L1.insereFinal(rand() % 100);
    }
    L1.imprime();


    for (int i = 0; i < 50 / 2; i++) {
        // porque nao pode deixar get(i) e remove(i)???
        L2.insereFinal(L1.get(0));
        L1.removeInicio();
    }

    L2.imprime();

    L1.imprime();

    for (int i = 0; i < 50 / 2; i++) {
        L3.insereFinal(L1.get(0));
        L1.removeInicio();
    }

    L3.imprime();

    L1.imprime();