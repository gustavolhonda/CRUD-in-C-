#ifndef CAMPEAO_H
#define CAMPEAO_H

#include <iostream>
#include <string>

using namespace std;

enum CLASSE {ATIRADOR = 'A', MAGO = 'M'};

class Campeao {
    public:
        Campeao(string nome, int vida, int mana, string skin, string raca, string regiao);
        ~Campeao();
        virtual char getClasse() const = 0;
        string getSkin() const;
        string getNome() const;
        string getRaca() const;
        string getRegiao() const;
        int getVida() const;
        int getMana() const;
        void setSkin(string novaSkin);
        virtual void imprime() const;
        static bool compara(const Campeao* c1, const Campeao* c2);
    private:
        string nome;
        int vida;
        int mana;
        string skin;
        string raca;
        string regiao;
};

#endif