#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tColor {
	int alt;
	int a;
	int r;
	int v;
};

bool suma(vector <int> const& cont) {
	// el numero de piezas rojas tiene q ser mayor q la suma de las piezas azules mas verdes
	if(cont[1] > (cont[0] + cont[2]))return true;
	else return false;
}

bool esValido(vector <int> const& sol, int k, vector <int> const& cont, tColor c) {
	// no puede haber dos verdes seguidas
	if (sol.size() - 1 != 0 && sol[k] == sol[k - 1] && sol[k] == 2)return false;
	// el numero de piezas verdes no puede ser mayor al de azules en ningun momento
	if (cont[0] < cont[2]) return false;
	// no puede haber mas fichas azules que las que indica el archivo
	if (cont[0] > c.a)return false;
	// no puede haber mas fichas rojas que las que indica el archivo
	if (cont[1] > c.r) return false;
	// no puede haber mas fichas verdes que las que indica el archivo
	if (cont[2] > c.v)return false;
	else return true;
}

void escribir(vector <int> const& sol) {
	if (sol.size() == 0) cout << "SIN SOLUCION \n";
	else {
		for (int i = 0; i < sol.size(); i++) {
			if (sol[i] == 0)cout << "azul ";
			else if (sol[i] == 1)cout << "rojo ";
			else if (sol[i] == 2) cout << "verde ";
		}
		cout << "\n";
	}
}

// función que resuelve el problema
void construir(tColor c, int k, vector <int>& torre, int nColores, vector <int> &cont, bool &ok) {
	//caso base
	ok = false;
	if (c.alt == 1) {
		escribir(torre);
	}
	else {
		for (int i = 0; i < nColores; i++) {
			torre[k] = i;
			cont[i]++;
			if (esValido(torre, k, cont, c)) {
				if (k == c.alt - 1) {
					if (suma(cont)) {
						ok = true;
						escribir(torre);
					}
				}
				else {
					construir(c, k + 1, torre, nColores, cont, ok);
				}
			}
			cont[i]--;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nColores = 3;
	tColor c;
	bool ok;
	// leer los datos de la entrada
	cin >> c.alt;
	if (c.alt == 0)return false;
	cin >> c.a >> c.r >> c.v;
	// 0-AZUL, 1-ROJO, 2-VERDE
	vector <int> torre(c.alt);
	vector <int> cont(nColores);
	
	// inicializamos el contador de los colores a cero
	cont[0] = 0;
	cont[1] = 0;
	cont[2] = 0;
	
	// la primera pieza siempre es roja
	torre[0] = 1;
	cont[1]++;
	
	construir(c, 1, torre, nColores, cont, ok);
	if (!ok)cout << "SIN  SOLUCION \n";
	cout << "\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}