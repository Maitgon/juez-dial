#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/* El coste de la función es el siguiente:
	T(1) = 1; T(n) = 2T(n/2) + 1;
	siendo n el numero de submoviles existentes en cada lado por lo que ser\'a O(n).
*/
bool equilibrado(int &peso) {
	int p_iz, d_iz, p_dr, d_dr;
	bool eqiz = true, eqdr = true;
	cin >> p_iz >> d_iz >> p_dr >> d_dr; 
	if (p_iz == 0) {
		eqiz = equilibrado(p_iz);
	}
	if (p_dr == 0) {
		eqdr = equilibrado(p_dr);
	}
	if (eqiz && eqdr && ((p_iz * d_iz) == (p_dr * d_dr))) {
		peso = p_dr + p_iz;
		return true;
	} 
    else {return false;}
}


void resuelveCaso() {	
	int peso;
	if (equilibrado(peso)) {std::cout << "SI" << "\n";}
	else {cout << "NO" << "\n";}
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}