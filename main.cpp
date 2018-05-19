#include <iostream>
#include <string>
#include "rede-social.hpp"

using namespace std;

class Amigos {
	public:
		string nome;
		Amigos();
		Amigos(string n);
		void Imprime();
};

void Amigos::Imprime() {
	cout << nome << endl;
}

Amigos::Amigos() {
	nome = "vazio";
}

Amigos::Amigos(string n) {
	nome = n;
}

int main() {
	cout << "SAIR para sair da aplicação,\n INSERIR para cadastrar amizades,\n BUSCAR para verificar pessoa existente,\n REMOVER para excluir uma amizade e\n IMPRIMIR para mostrar na tela a rede." << endl;

	string opcao;
	cin >> opcao;

	Amizades<int, Amigos> A;

	while(opcao != "SAIR") {
		if(opcao == "INSERIR" || opcao == "inserir") {
			string nome;
			cout << "ID: ";
			int chave;
			cin >> chave;
			cout << "Nome: ";
			getline(cin, nome);
				
			Amigos a(nome);
			a.Imprime();
		
			A.InserirIterativo(chave, a);
		}
		else if(opcao ==  "BUSCAR" || opcao == "buscar") {
			int chave;
			cout << "ID: ";
			cin >> chave;
			Amigos a = A.Buscar(chave);
			a.Imprime();
		}
		else if(opcao == "REMOVER" || opcao == "remover") {
			int chave;
			cout << "ID: ";
			cin >> chave;
			Amigos a = A.Remover(chave);
		}
		else if(opcao == "IMPRIMIR" || opcao == "imprimir") {
			A.Imprime();
		}
		cin >> opcao;
	}
	
	return 0;
}
