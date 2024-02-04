#include "Cadastro.h"
#include "Mago.h"
#include "Atirador.h"
using namespace std;

int main() {

    char op;
    string nome;
    
    Cadastro cadastro("info.dat");
    
    do {
        op = Cadastro::opcao();
        switch (op) {
            case 'I': { 
                cadastro.imprime();
                break;
            }
            case 'N': {
                cin.ignore();
                cout << "Nome: ";
                getline(cin, nome);
                cadastro.imprime(nome);
                break;
            }
            case 'O': {
                cadastro.imprime(true);
                break;
            }
            case 'A': {
                cadastro.adiciona(ATIRADOR);
                break;
            }
            case 'M': {
                cadastro.adiciona(MAGO);
                break;
            }
            case 'S': {
                cin.ignore();
                cout << "Nome: ";
                getline(cin, nome);
                bool ok = cadastro.atualiza(nome);
                cout << "Atualização " << (ok ? "ok" : "não ok") << endl;
                break;
            }
            case 'R': {
                cin.ignore();
                cout << "Nome: ";
                getline(cin, nome);
                bool ok = cadastro.remove(nome);
                cout << "Remoção " << (ok ? "ok" : "não ok") << endl;
                break;
            }
        }
        cout << endl;
    } while (op != 'F');

    return 0;
}