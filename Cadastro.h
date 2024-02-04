#ifndef CADASTRO_H
#define CADASTRO_H

#include "Campeao.h"

#include <iostream>
#include <vector>

using namespace std;

class Cadastro {
    public:
        Cadastro(string fileName);
        virtual ~Cadastro();
        bool adiciona(char classe);
        void imprime(bool sorted = false);
        void imprime(string nome);
        bool remove(string nome);
        bool atualiza(string nome);
        static char opcao();
    private:
        void grava();
        void recupera();
        int indice(string nome);

        string fileName;
        vector <Campeao*> campeoes;
};

#endif 