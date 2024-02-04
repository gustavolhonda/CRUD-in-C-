#include "Atirador.h"

Atirador::Atirador(string nome, int vida, int mana, string skin, string raca, string regiao, string arma, int dano) : 
        Campeao(nome, vida, mana, skin, raca, regiao), arma(arma), dano(dano) {

}

Atirador::~Atirador() {
}

char Atirador::getClasse() const {
    return ATIRADOR;
}

string Atirador::getArma() const {
    return this->arma;
}

int Atirador::getDano() const {
    return this->dano;
}

void Atirador::imprime() const {
    Campeao::imprime();
    cout << "Arma: " << arma << endl;
    cout << "Dano: " << dano << endl;
    cout << "------------------------------" << endl;
}