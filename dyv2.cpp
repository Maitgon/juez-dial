#include <iostream>
#include <vector>
using namespace std;

/*
Para este problema lo que uso es una especia de busqueda binaria.

Y el coste del algoritmo sera O(log n).
*/

int solucion (vector<int> vec, int i, int j){
    int sol;

    /*
    Aqui tengo los casos base (la funcion pequeño),
    que es cuando el principio y final del vector son adyacentes,
    en el cual devuelvo el minimo de los 2
    */

    if (j-i < 2){
        if (vec[i] < vec[j]){
            sol = vec[i];
        }
        else{
            sol = vec[j];
        }
    }

    /*
    Para la parte recursiva lo que hacemos es dividir el vector
    en 2 y miramos a los elementos adyacentes para ver si en
    nuestra posicion la curva esta decreciendo, creciendo, o si
    estamos en el minimo,

    si decrece miremos en la mitad derecha, si crece en la izquierda
    y si estamos en el minimo pues hemos hallado la solucion
    */

    else{
        int m = (i + j) / 2;
        if (vec[m-1] < vec[m] && vec[m] < vec[m+1]){
            sol = solucion (vec, i, m);
        }
        else if (vec[m-1] > vec[m] && vec[m] < vec[m+1]){
            sol = vec[m];
        }
        else{
            sol = solucion (vec, m, j);
        }
    }
    return sol;
}

bool resuelveCaso() {
  int lon;
  cin >> lon;
  vector<int> vec;
  int elem;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  if (!cin) {return false;}
  int sol = solucion (vec, 0, vec.size() - 1);
  cout << sol << endl;
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}