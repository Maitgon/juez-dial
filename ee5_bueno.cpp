#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int _INF = 100000;

struct tDatos {
	vector <int> sol;
	vector <bool>marca;
	int suma;
};

// función que resuelve el problema
void solucion(vector <vector<int>> const& tabla, tDatos &d, int k, int f, vector <int> const& acum, int &sol) {
	for (int i = 0; i < f; i++) {
		d.sol[k] = i;
		d.suma += tabla[k][i];
		if (!d.marca[i]) {
			d.marca[i] = true;
			if (k == d.sol.size() - 1) {
				if (sol > d.suma) sol = d.suma;
			}//
			else {
				if (d.suma + acum[k + 1] < sol) {
					solucion(tabla, d, k + 1, f, acum, sol);
				}
			}
			d.marca[i] = false;
		}
		d.suma -= tabla[k][i];
	}
}

bool resuelveCaso() {
	int func;
	tDatos d;
	cin >> func;
	if (func == 0)return false;

	//matriz
	vector <vector<int>> tabla;
	for (int i = 0; i < func; ++i) {
		vector<int> aux(func);
		for (int j = 0; j < func; ++j) cin >> aux[j];
		tabla.push_back(aux);
	}
	d.marca.assign(func, false);
	d.sol.assign(func, 0);
	d.suma = 0;
	int sol = 0;
	for (int i = 0, j = 0; i < func && j < func; i++, j++) {
		sol += tabla[i][j];
	}
	vector<int> acum(func);
	for (int i = 0; i < func; ++i) {
		int auxMax = sol;
		for (int j = 0; j < func; ++j)
			if (auxMax > tabla[i][j]) auxMax = tabla[i][j];
		acum[i] = auxMax;
	}
	// Vector acumulados
	for (int i = (int)acum.size() - 1; i > 0; --i) {
		acum[i - 1] += acum[i];
	}
	solucion(tabla, d, 0, func, acum, sol);
	cout << sol << "\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}