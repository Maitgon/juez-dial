#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Para el algoritmo voraz, mi estrategia es ordenador ambos vectores,
el de rivales en creciente, y el de broncos en decreciente, y voy a tener
mi variable solucion en la que acumulare la diferencia de puntos, la forma
en la que mas beneficio se puede tener es poniendo los que mas beneficio tienen
al principio y parar de sumar en cuanto el beneficio sea negativo.

Al final ordenar ambos vectores es O(nlog(n)) y el algoritmo se ejecuta en O(n).
Por lo que el algoritmo total es O(nlog(n)).
*/

int solucion (vector<int> &rivales, vector<int> &broncos){
    int sol = 0;
    int i = 0;
    int N = rivales.size();
    while (i < N && rivales[i] < broncos[i]){
        sol += broncos[i] - rivales[i];
        i++;
    }
    return sol;
}

bool resuelveCaso() {
  int lon;
  cin >> lon;
  vector<int> vec;
  int elem;
  if (lon == 0) {return false;}
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  vector<int> vec2;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec2.push_back(elem);
  }
  sort(vec.begin(), vec.end());
  sort(vec2.rbegin(), vec2.rend());
  int sol = solucion (vec, vec2);
  cout << sol << "\n";
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}