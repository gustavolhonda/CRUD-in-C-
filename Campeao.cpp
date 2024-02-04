#include "Campeao.h"
#include "Atirador.h"
#include "Mago.h"

Campeao::Campeao(string nome, int vida, int mana, string skin, string raca, string regiao) :
        nome(nome), vida(vida), mana(mana), skin(skin), raca(raca), regiao(regiao) {

}

Campeao::~Campeao() {
}

string Campeao::getSkin() const{
    return this->skin;
}

void Campeao::setSkin(string novaSkin) {
    this->skin = novaSkin;
}

string Campeao::getNome() const {
    return this->nome;
}

string Campeao::getRaca() const {
    return this->raca;
}

string Campeao::getRegiao() const {
    return this->regiao;
}

int Campeao::getVida() const {
    return this->vida;
}

int Campeao::getMana() const {
    return this->mana;
}

void Campeao::imprime() const {
    cout << "[" << (this->getClasse() == ATIRADOR ? "Atirador" : "Mago") << "]" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Região: " << regiao << endl;
    cout << "Raça: " << raca << endl;
    cout << "Vida: " << vida << endl;
    cout << "Mana: " << mana << endl;
    cout << "Skin: " << skin << endl;
}

bool Campeao::compara(const Campeao* c1, const Campeao* c2) {
    if (c1->getClasse() == c2->getClasse()) {
        if (c1->regiao == c2->regiao) {
            return c1->nome < c2->nome;
        }
        return c1->regiao < c2->regiao;
    }
    return c1->getClasse() < c2->getClasse();
    
}