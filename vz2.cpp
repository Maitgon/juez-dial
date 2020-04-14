#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Mi estrategia para este problema ha sido primero crear una clase de datos para
los edificios (que simula intervalos cerrados), lo que quiero es una vez he leido
todos los quiero ordenar por quien tiene el incio de intervalos mas corto
(es decir, ordenados de forma creciente en edif.iz), mi idea es coger el primer
intervalo, mirar el siguiente, y si la interseccion abierta no es vacia,
lo que hago es actualizar el primer intervalo como la interseccion de estos dos.

Seguiriamos asi hasta que haya una interseccion abierta vacia, estonces ya hemos
terminado con nuestra primera linea perpendicular y vamos a por la siguiente,
cojemos el siguiente edificio y lo usamos como intervalo, y repetimos el proceso
de antes hasta que terminemos los edificios.

El coste del algoritmo voraz es O(n) ya que recorremos el vector de iz a dr,
en cambio el coste de ordenar el vector es de O(nlog(n)) por tanto el coste
total del algoritmo es O(nlog(n)).
*/

typedef struct Edificio {
  int iz;
  int dr;
} Edificio;

istream &operator>>(istream &entrada, Edificio &edif){
  entrada >> edif.iz;
  entrada >> edif.dr;
  return entrada;
}

bool operator< (Edificio edif1, Edificio edif2){
  return edif1.iz < edif2.iz;
}

int solucion (vector<Edificio> &vec){
  int i = 0;
  int N = vec.size();
  int sol= 0;
  Edificio int_restante;
  while (i < N){
    int_restante = vec[i];
    sol++;
    i++;
    while (i < N && vec[i].iz < int_restante.dr){
      int_restante.iz = vec[i].iz;
      int_restante.dr = min(vec[i].dr, int_restante.dr);
      i++;
    }
  }
  return sol;
}

bool resuelveCaso() {
  int lon;
  cin >> lon;
  if (lon == 0){
    return false;
  }
  vector<Edificio> vec;
  Edificio elem;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  sort(vec.begin(),vec.end());
  int sol = solucion (vec);
  cout << sol << "\n";
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}