#include <iostream>
#include <string>
//#include "Dicionario.h"
#include "ABB.h"
using namespace std;

class Pessoa
{
public:
	string nome;
	int idade;
	string telefone;
	string cpf;

	Pessoa();
	Pessoa(string n, int i, string t, string c);

	bool operator==(Pessoa p2);
	bool operator!=(Pessoa p2);


	void Imprime();

};

void Pessoa::Imprime()
{
	cout << nome << "-" << idade << "-" << telefone << "-" << cpf << endl;
}

Pessoa::Pessoa()
{
	nome = "vazio";
	idade = 0;
	telefone = "";
	cpf = "";
}

Pessoa::Pessoa(string n, int i, string t, string c)
{
	nome = n;
	idade = i;
	telefone = t;
	cpf = c;
}

bool Pessoa::operator==(Pessoa p2)
{
	return cpf == p2.cpf;
}

bool Pessoa::operator!=(Pessoa p2)
{
	return cpf != p2.cpf;
}

int main()
{
	string opcao;
	cin >> opcao;

	Dicionario<int, Pessoa> D;

	while(opcao != "SAIR")
	{
		if(opcao == "INSERIR")
		{
			string nome,  cpf, telefone, lixo;
			int chave;
			int idade;
			cin >> chave;
			getline(cin, lixo);
			getline(cin, nome);
			cin >> idade;
			getline(cin, lixo);
			getline(cin, cpf);
			getline(cin, telefone);
				
			Pessoa p(nome, idade, cpf, telefone);
			p.Imprime();
		
			D.Inserir(chave, p);
		}
		else if(opcao ==  "BUSCAR")
		{
			int chave;
			cin >> chave;
			Pessoa p = D.Buscar(chave);
			p.Imprime();
		}
		else if(opcao == "REMOVER")
		{
			int chave;
			cin >> chave;
			Pessoa p = D.Remover(chave);
		}
		else if(opcao == "IMPRIMIR")
		{
			D.Imprime();
		}

		cin >> opcao;
	}
}


