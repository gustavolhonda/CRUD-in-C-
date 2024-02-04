#include "Mago.h"

Mago::Mago(string nome, int vida, int mana, string skin, string raca, string regiao, string magia, int poderDeHabilidade) :
        Campeao(nome, vida, mana, skin, raca, regiao), magia(magia), poderDeHabilidade(poderDeHabilidade) {

}

Mago::~Mago() {

}

char Mago::getClasse() const {
    return MAGO;
}

string Mago::getMagia() const {
    return this->magia;
}

int Mago::getPdh() const {
    return this->poderDeHabilidade;
}

void Mago::imprime() const {
    Campeao::imprime();
    cout << "Magia: " << magia << endl;
    cout << "Poder de Habilidade: " << poderDeHabilidade << endl;
    cout << "------------------------------";
}