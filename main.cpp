#include <iostream>
#include <cstdlib>
#include "rede-social.cpp"

using namespace std;

int main() {
	Amizade* a = criaAmizade();

	insereAmigos(&a, 1);
	insereAmigos(&a, 2);
	insereAmigos(&a, 3);
	
	mostraAmizade(a);

	return 0;
}
