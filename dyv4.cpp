#include <iostream>
#include <vector>
using namespace std;

/*
Mi idea aqui fue ignorar un poco el vector que nos dan y trucarlo para
hacer un busqueda binaria y ya.
Lo que hago es que creando el vector le voy restando los indices para que
directamente pueda buscar luego el valor que se canta.
Lo unico luego te piden devolver el valor real por lo que cuando lo halles le
sumas su indice.
El otro problema es que aqui puedo no haber el valor que buscas por lo que
si no se encuentra devuelvo -1.
El coste del algoritmo es log(n).
*/

int solucion (vector<int> &vec, const int i, const int j, const int val){
    int sol;
    if (j - i < 2){
      if ((vec[j]-j) == val){
        sol = val + j;
      } 
      else if ((vec[i]-i) == val){
        sol = val + i;
      }
      else{
        sol = -1;
      }
    }
    else{
        int m = (i + j)/2;
        if (vec[m]-m < val){
            sol = solucion(vec, m, j, val);
        }
        else if (vec[m]-m == val){
            sol = val + m;
        }
        else{
            sol = solucion(vec, i, m, val);
        }
    }
    return sol;
}

void resuelveCaso() {
  int lon, val;
  cin >> lon >> val;
  vector<int> vec;
  int elem;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  if (vec[lon-1] -lon + 1 == val){
    cout << val + lon - 1 << "\n";
  }
  else{
    int sol = solucion (vec, 0, lon-1, val);
    if (sol == -1){
      cout << "NO" << "\n";
    }
    else{
      cout << sol << "\n";
    }
  }
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}