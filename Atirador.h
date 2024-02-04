#ifndef ATIRADOR_H
#define ATIRADOR_H

#include "Campeao.h"

class Atirador : public Campeao {
    public:
        Atirador(string nome, int vida, int mana, string skin, string raca, string regiao, string arma, int dano);
        ~Atirador();
        char getClasse() const;
        string getArma() const;
        int getDano() const;
        void imprime() const;
    private:
        string arma;
        int dano;
};

#endif 