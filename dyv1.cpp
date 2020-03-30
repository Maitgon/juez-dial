#include <iostream>
#include <vector>
using namespace std;

/*
Para este problema he utilizado una variente parecida a la
busqueda binaria, solo que voy mirando en cada mitad, cual
se corresponde con la diferencia de vertices y cual no, la que
no se corresponda sera donde falte una letra

Por ultimo el caso base es cuando el inicio y el final son
dos elementos del vector adyacentes por tanto el valor que
buscamos es el que estan en medio de los dos
*/

int solucion (vector<int> vec, int init, int fin){
    int sol;
    if (fin == init + 1){
        sol = vec[init] + 1;
    }
    else{
        int m = (init + fin) / 2;
        if (vec[m] - vec[init] != m - init){
            sol = solucion (vec, init, m);
        }
        else{
            sol = solucion (vec, m, fin);
        }
    }
    return sol;
}

/*
Para coger los datos he decidido meterlos en el vector ya
siendo enteros, para facilitar la lectura del programa
*/

void resuelveCaso() {
    char inicio, fin;
    cin >> inicio >> fin;
    int init, fi;
    init = (int)inicio;
    fi = (int)fin;
    char valor;
    int val;
    vector<int> vec;
    int i = fi - init;
    while (i != 0){
        cin >> valor;
        val = (int)valor;
        vec.push_back(val);
        i--;
    }
    char sol;
    if (vec.front() != init){
        sol = inicio;
    }
    else if (vec.back() != fi){
        sol = fin;
    }
    else {sol = (char)(solucion (vec, 0, vec.size() - 1));}
    cout << sol << endl;
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}