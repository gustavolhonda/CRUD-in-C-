#ifndef MAGO_H
#define MAGO_H

#include "Campeao.h"

class Mago : public Campeao {
    public:
        Mago(string nome, int vida, int mana, string skin, string raca, string regiao, string magia, int poderDeHabilidade);
        ~Mago();
        char getClasse() const;
        string getMagia() const;
        int getPdh() const;
        void imprime() const;
    private:
        string magia;
        int poderDeHabilidade;
};

#endif 