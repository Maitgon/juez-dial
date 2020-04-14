#include <iostream>
#include <vector>
using namespace std;

// Me he definido un tipo de pares de enteros para ayudarme con la salida

typedef struct par{
  int ent1;
  int ent2;
} par;

/*
Mi idea aqui es hacer algo parecido a una busqueda binaria, salvo que vamos viendo
si es si el elemento del creciente es menor que el del decreciente o al reves
y en base a eso decidimos si buscar a la izquierda o a la derecha de ambos
vectores.
*/

par solucion (const vector<int> crec, const vector<int> decr, const int i, const int j){
  par sol;

  // Esta seria mi funcion pequeno, que mira si el "final" del vector y el "inicio"
  // estan lo suficientemente proximos

  if (j - i < 2){
    if (crec[j] == decr[j]){
      sol.ent1 = j;
      sol.ent2 = j;
    }
    else if (crec[i] == decr[i]){
      sol.ent1 = i;
      sol.ent2 = i;
    }
    else if (i == 0 && crec[i] > decr[i]){
      sol.ent1 = -1;
      sol.ent2 = 0;
    }
    else if (j == (crec.size()-1) && crec[j] < decr[j]){
      sol.ent1 = j;
      sol.ent2 = j+1;
    }
    else{
      sol.ent1 = i;
      sol.ent2 = j;
    }
  }

  // Y aqui es donde dividimos el vector a la mitad y miramos que necesitamos

  else{
    int m = (i+j) / 2;
    if (crec[m] == decr[m]){
      sol.ent1 = m;
      sol.ent2 = m;
    }
    else if (crec[m] < decr[m]){
      sol = solucion (crec, decr, m, j);
    }
    else{
      sol = solucion (crec, decr, i, m);
    }
  }
  return sol;
}

bool resuelveCaso() {
  int lon;
  cin >> lon;
  if (lon==0){
    return false;
  }
  vector<int> vec;
  int elem;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  vector<int> vec2;
  for (int j = 0; j < lon; j++){
    cin >> elem;
    vec2.push_back(elem);
  }
  par sol;
  sol = solucion (vec,vec2,0,lon-1);
  if (sol.ent1 == sol.ent2){
      cout << "SI " << sol.ent1 << "\n";
  }
  else{
      cout << "NO " << sol.ent1 << " " << sol.ent2 << "\n";
  }
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}