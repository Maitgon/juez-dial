#include <iostream>
#include <vector>
using namespace std;

/*
Mi idea para esto es que el vector este dividido en 2 partes, hay una en la que
todos los numeros son mas grandes que en la otra, por lo que hago busqueda
binaria pero siempre comprobando que el v[m] es mayor que el v[0] ya que del
v[0] hasta el v[sol] va a ser decreciente hasta la sol optima y si nuestra m
es despues de esa sol optima entonces habra que mirar a la izquierda, el resto
es busqueda binaria
*/

int solucion (vector<int> vec, int init, int fin){

    //Esta seria la funcion pequeño

    int sol;
    if (fin-init < 2){
        if (vec[init] < vec[fin]){
            sol = vec[init];
        }
        else{
            sol = vec[fin];
        }
    }

    //Aqui dividimos el problema en problemas mas pequeños como explique arriba

    else{
        int m = (init + fin) / 2;
        if (vec[m] > vec[0]){
            sol = solucion (vec, init, m);
        }
        else if (vec[m-1] > vec[m] && vec[m] > vec[m+1]){
            sol = solucion (vec, m, fin);
        }
        else{
            sol = vec[m];
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
  int sol = solucion (vec, 0, lon-1);
  cout << sol << "\n";
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}