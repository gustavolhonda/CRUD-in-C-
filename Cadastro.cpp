#include "Cadastro.h"
#include "Atirador.h"
#include "Mago.h"

#include <algorithm>
#include <fstream>

Cadastro::Cadastro(string fileName) : fileName(fileName)
{
    recupera();
}

Cadastro::~Cadastro()
{
}

void Cadastro::grava()
{

    char classe;
    string nome, skin, raca, regiao, arma, magia;
    int tamNome, tamSkin, tamRaca, tamRegiao, tamArma, tamMagia;
    int vida, mana, dano, pdh;
    Mago *m1;
    Atirador *a1;

    ofstream saida(fileName, ios::binary);

    for (long unsigned int i = 0; i < campeoes.size(); i++)
    {

        // Escrevendo a classe do campeao (ATIRADOR ou MAGO)
        classe = campeoes[i]->getClasse();
        saida.write(reinterpret_cast<char *>(&classe), sizeof(classe));

        // Escrevendo o nome do campeao
        nome = campeoes[i]->getNome();
        tamNome = nome.size();
        saida.write(reinterpret_cast<char *>(&tamNome), sizeof(tamNome));
        saida.write(reinterpret_cast<char *>(&nome[0]), tamNome);

        // Escrevendo a região
        regiao = campeoes[i]->getRegiao();
        tamRegiao = regiao.size();
        saida.write(reinterpret_cast<char *>(&tamRegiao), sizeof(tamRegiao));
        saida.write(reinterpret_cast<char *>(&regiao[0]), tamRegiao);

        // Escrevendo a raça
        raca = campeoes[i]->getRaca();
        tamRaca = raca.size();
        saida.write(reinterpret_cast<char *>(&tamRaca), sizeof(tamRaca));
        saida.write(reinterpret_cast<char *>(&raca[0]), tamRaca);

        // Escrevendo a vida
        vida = campeoes[i]->getVida();
        saida.write(reinterpret_cast<char *>(&vida), sizeof(vida));

        // Escrevendo a mana
        mana = campeoes[i]->getMana();
        saida.write(reinterpret_cast<char *>(&mana), sizeof(mana));

        // Escrevendo a skin
        skin = campeoes[i]->getSkin();
        tamSkin = skin.size();
        saida.write(reinterpret_cast<char *>(&tamSkin), sizeof(tamSkin));
        saida.write(reinterpret_cast<char *>(&skin[0]), tamSkin);

        // Escreve as caracteristicas especificas dos campeões
        // (atributos da classe Atirador ou Mago)

        switch (classe)
        {
        case ATIRADOR:
        {

            // escrevendo a arma
            a1 = dynamic_cast<Atirador *>(campeoes[i]);
            arma = a1->getArma();
            tamArma = arma.size();
            saida.write(reinterpret_cast<char *>(&tamArma), sizeof(tamArma));
            saida.write(reinterpret_cast<char *>(&arma[0]), tamArma);

            // escrevendo o dano
            dano = a1->getDano();
            saida.write(reinterpret_cast<char *>(&dano), sizeof(dano));

            break;
        }
        case MAGO:
        {

            // escrevendo a magia
            m1 = dynamic_cast<Mago *>(campeoes[i]);
            magia = m1->getMagia();
            tamMagia = magia.size();
            saida.write(reinterpret_cast<char *>(&tamMagia), sizeof(tamMagia));
            saida.write(reinterpret_cast<char *>(&magia[0]), tamMagia);

            // escrevendo o pdh
            pdh = m1->getPdh();
            saida.write(reinterpret_cast<char *>(&pdh), sizeof(pdh));

            break;
        }
        }
    }
    saida.close();
}

void Cadastro::recupera()
{

    char classe;
    string nome, skin, raca, regiao, arma, magia;
    int tamNome, tamSkin, tamRaca, tamRegiao, tamArma, tamMagia;
    int vida, mana, dano, pdh;

    ifstream entrada(fileName, ios::binary);

    if (entrada.is_open())
    {

        campeoes.clear();

        // Lendo a classe

        entrada.read(reinterpret_cast<char *>(&classe), sizeof(classe));

        while (entrada.good())
        {

            // Lendo o nome

            // Lendo o tamanho da string (nome)
            entrada.read(reinterpret_cast<char *>(&tamNome), sizeof(tamNome));
            nome.resize(tamNome);

            // Lendo os caracteres da string (nome)
            entrada.read(reinterpret_cast<char *>(&nome[0]), tamNome);

            // Lendo a região

            // Lendo o tamanho da string (região)
            entrada.read(reinterpret_cast<char *>(&tamRegiao), sizeof(tamRegiao));
            regiao.resize(tamRegiao);

            // Lendo os caracteres da string (região)
            entrada.read(reinterpret_cast<char *>(&regiao[0]), tamRegiao);

            // Lendo a raça

            // Lendo o tamanho da string (raça)
            entrada.read(reinterpret_cast<char *>(&tamRaca), sizeof(tamRaca));
            raca.resize(tamRaca);

            // Lendo os caracteres da string (raça)
            entrada.read(reinterpret_cast<char *>(&raca[0]), tamRaca);

            // Lendo a vida
            entrada.read(reinterpret_cast<char *>(&vida), sizeof(vida));

            // Lendo a mana
            entrada.read(reinterpret_cast<char *>(&mana), sizeof(mana));

            // Lendo a skin

            // Lendo o tamanho da string (skin)
            entrada.read(reinterpret_cast<char *>(&tamSkin), sizeof(tamSkin));
            skin.resize(tamSkin);

            // Lendo os caracteres da string (skin)
            entrada.read(reinterpret_cast<char *>(&skin[0]), tamSkin);

            // Lendo as caracteristicas especificas dos Campeões
            // (atributos da classe Atirador ou Mago)

            switch (classe)
            {
            case ATIRADOR:
            {

                // Lendo a arma

                // Lendo o tamanho da string (arma)
                entrada.read(reinterpret_cast<char *>(&tamArma), sizeof(tamArma));
                arma.resize(tamArma);

                // Lendo os caracteres da string (arma)
                entrada.read(reinterpret_cast<char *>(&arma[0]), tamArma);

                // Lendo o dano
                entrada.read(reinterpret_cast<char *>(&dano), sizeof(dano));

                campeoes.push_back(new Atirador(nome, vida, mana, skin, raca, regiao, arma, dano));
                break;
            }
            case MAGO:
            {

                // Lendo a magiaa

                // Lendo o tamanho da string (magia)
                entrada.read(reinterpret_cast<char *>(&tamMagia), sizeof(tamMagia));
                magia.resize(tamMagia);

                // Lendo os caracteres da string (magia)
                entrada.read(reinterpret_cast<char *>(&magia[0]), tamMagia);

                // Lendo o Poder de Habilidade
                entrada.read(reinterpret_cast<char *>(&pdh), sizeof(pdh));

                campeoes.push_back(new Mago(nome, vida, mana, skin, raca, regiao, magia, pdh));
                break;
            }
            }

            // Lendo a classe

            entrada.read(reinterpret_cast<char *>(&classe), sizeof(classe));
        }
    }
    entrada.close();
}

bool Cadastro::adiciona(char classe)
{

    string nome, raca, regiao, skin, arma, magia;
    int vida, mana, dano, pdh;

    Campeao *c;

    cin.ignore();
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Região: ";
    getline(cin, regiao);
    cout << "Raça: ";
    getline(cin, raca);
    cout << "Vida: ";
    cin >> vida;
    cout << "Mana: ";
    cin >> mana;
    cin.ignore();
    cout << "Skin: ";
    getline(cin, skin);

    switch (classe)
    {
    case ATIRADOR:
    {
        cout << "Arma: ";
        getline(cin, arma);
        cout << "Dano: ";
        cin >> dano;
        c = new Atirador(nome, vida, mana, skin, raca, regiao, arma, dano);
        break;
    }
    case MAGO:
    {
        cout << "Magia: ";
        getline(cin, magia);
        cout << "Poder De Habilidade: ";
        cin >> pdh;
        c = new Mago(nome, vida, mana, skin, raca, regiao, magia, pdh);
        break;
    }
    }

    campeoes.push_back(c);
    grava();
    return true;
}

bool Cadastro::atualiza(string nome)
{
    string skin;
    bool ok = false;
    int pos = indice(nome);

    if (pos != -1)
    {

        cout << "Skin: ";
        getline(cin, skin);
        campeoes[pos]->setSkin(skin);
        grava();
        ok = true;
    }

    return ok;
}

bool Cadastro::remove(string nome)
{
    bool ok = false;
    int pos = indice(nome);

    if (pos != -1)
    {
        campeoes.erase(campeoes.begin() + pos);
        grava();
        ok = true;
    }

    return ok;
}

int Cadastro::indice(string nome)
{
    long unsigned int tam = campeoes.size();
    long unsigned int pos = 0;

    while ((pos < tam) && (campeoes[pos]->getNome() != nome))
    {
        pos++;
    }

    if (pos < tam)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

void Cadastro::imprime(string nome)
{
    int pos = indice(nome);
    if (pos != -1)
    {
        campeoes[pos]->imprime();
    }
    else
    {
        cout << "Nome não encontrado.";
    }
}

void Cadastro::imprime(bool sorted)
{
    vector<Campeao *> copia = campeoes;

    if (sorted)
    {
        sort(copia.begin(), copia.end(), Campeao::compara);
    }
    for (unsigned long int i = 0; i < copia.size(); i++)
    {
        copia[i]->imprime();
        cout << endl;
    }
}

char Cadastro::opcao()
{
    char c;
    cout << "[I] Imprime todos" << endl;
    cout << "[N] Imprime por nome" << endl;
    cout << "[O] Imprime ordenado (Classe/Nome)" << endl;
    cout << "[A] Adiciona Atirador" << endl;
    cout << "[M] Adiciona Mago" << endl;
    cout << "[S] Atualiza skin (por nome)" << endl;
    cout << "[R] Remove (por nome)" << endl;
    cout << "[F] Fim" << endl;
    cout << "> ";
    cin >> c;
    return (toupper(c));
}