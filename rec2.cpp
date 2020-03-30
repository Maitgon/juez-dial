#include <iostream>
#include <vector>
using namespace std;

/*
Para este problema, mi idea es usar una funcion
auxiliar llamada solucion_2 que recoja ademas del
vector, la posicion de la mitad del vector, y el ancho
de este e ir partiendo el vector por la mitad hasta que
lleguemos al caso trivial que es cuando el tamaó del
vector es 1
*/

bool solucion_2 (vector<int> vec, int mid, int size){
    //En vez de hallar los min y max en la parte no
    //trivial los hallé aquí por más comodidad para
    //poder leer yo el programa
  int principio = mid - size/2;
  int fin = mid + size/2;
  int max_iz, max_dr;
  int min_iz, min_dr;
  max_iz = 0;
  max_dr = 0;
  min_iz = vec[principio];
  for (int i = principio; i < mid; i++){
    if (vec[i] > max_iz){
      max_iz = vec[i];
    }
    if (min_iz > vec[i]){
      min_iz = vec[i];
    }
  }
  min_dr = vec[mid];
  for (int i = mid; i < fin; i++){
    if (vec[i] > max_dr){
      max_dr = vec[i];
    }
    if (min_dr > vec[i]){
      min_dr = vec[i];
    }
  }
  bool sol;
    //Aquí es cuando ya divido entre caso trivial y
    //no trivial

    //Caso trivial si el tamaño es 1
  if (size == 1){
    sol = true;
  }
    
    //Caso no trivial cuando es mas de 1
  else{
    sol = (max_dr >= max_iz) && (min_iz <= min_dr) &&
       (solucion_2 (vec, mid - size/4, size/2)) &&
       (solucion_2 (vec, mid + size/4, size/2));
  }
  return sol;
}

bool solucion (vector<int> vec) {
  int size = vec.size();
  bool sol = solucion_2 (vec, size/2, size);
  return sol;
}

bool resuelveCaso() {
  vector<int> vec;
  int valor;
  cin >> valor;
  if (valor == 0) {return false;}
  while (valor != 0){
    vec.push_back(valor);
    cin >> valor;
  }
  bool sol = solucion (vec);
  if (sol) {cout << "SI" << endl;}
  else {cout << "NO" << endl;}
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}