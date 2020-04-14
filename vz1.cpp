#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Estrategia para el algoritmo voraz, la idea es maximizar el numero de viajes
en parejas o disminuir el numero total de viajes, entonces lo que hago es
ordeno a las personas por pesos de forma decreciente y mantengo un indice
i y otro j que me van apuntando a las personas mas pesadas y menos pesadas que
van quedando, en el bucle voy juntando a la mas pesada con la menos pesada que
queda, al final el bucle del algoritmo voraz se hace en coste lineal con el
tamano del vector O(n), y la ordenacion se hace por el algoritmo introsort que
tiene una complejidad de O(nlog(n)) por tanto el algoritmo total sera:

O(nlog(n) + n) = O(nlog(n))
*/

int solucion (const vector<int> vec, int &peso){
    int i = 0;
    int j = vec.size() - 1;
    while (i <= j){
        if (vec[i] + vec[j] <= peso && j != i){
            i++; j--;
        }
        else{
            i++;
        }
    }
    return i;
}

bool resuelveCaso() {
  int peso, lon;
  cin >> peso >> lon;
  vector<int> vec;
  int elem;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  if (!cin) {return false;}
  sort(vec.rbegin(), vec.rend());
  int sol = solucion (vec, peso);
  cout << sol << "\n";
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}