#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <cstdlib>
using namespace std;

struct tDatos {
	int cont;
	int consumo;
};

struct tEntrada {
	int longitud;
	int numColores;
	int consumoMaximo;
};

bool Terminar(int consumoTOP, int consumoMaximo) {
	return (consumoTOP <= consumoMaximo);
}

bool esValido(int k, vector<int> const& sol, vector <int> sumaLuces, int lucesTotal) {
	// que no haya mas de dos colores iguales juntos
	if (k > 1 && sol[k] == sol[k - 1] && sol[k] == sol[k - 2]) return false;
	
	// que el numero de lucees mas una unidad supere al resto
	if (sumaLuces[sol[k]] > lucesTotal - sumaLuces[sol[k]] + 1) return false;
	//if (2 * sumaLuces[sol[k]] > lucesTotal + 1) return false;

	return true;
}

// Agrupar los datos en structs por datos de entrada, datos actuales, marcaje y solMejor
void resolver(int longi, int luces, vector<int> const& consumo, int consumoMaximo, int k, vector <int> &sol, int &consumoTOP,
	vector <int> &sumaLuces, int &lucesTotal, int &cont) {
	for (int i = 0; i < luces; i++) {
		sol[k] = i;
		consumoTOP += consumo[i];
		sumaLuces[i]++;
		lucesTotal++;
		if (esValido(k, sol, sumaLuces, lucesTotal)) {
			if (k == longi - 1) {
				if (Terminar(consumoTOP, consumoMaximo)) {
					cont++;
				}
			}//si esta lleno
			else {
				resolver(longi, luces, consumo, consumoMaximo, k + 1, sol, consumoTOP, sumaLuces, lucesTotal, cont);
			}
		}
		sumaLuces[i]--;
		consumoTOP -= consumo[i];
		lucesTotal--;
	}
}

bool resuelveCaso() {
	int longi, luces, consumoMaximo;
	cin >> longi;
	if (longi == 0) return false;
	cin >> luces >> consumoMaximo;
	
	vector<int> consumoLuces(luces);
	for (int & i : consumoLuces) std::cin >> i;

	vector <int> sol(longi);
	vector <int> contLuces(luces);
	// rellenamos el contador de luces a 0
	for (int i = 0; i < luces; i++) {
		contLuces[i] = 0;
	}

	// inicialiazamos a 0
	int consumoTOP = 0;
	int lucesTotal = 0;
	int cont = 0;
	resolver(longi, luces, consumoLuces, consumoMaximo, 0, sol, consumoTOP, contLuces, lucesTotal, cont);

	cout << cont << "\n";

		return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
