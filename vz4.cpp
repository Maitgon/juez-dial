#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Mi estrategia para el algoritmo voraz ha sido, usar la clase intervalos, y
ordenar el vector intervalos de forma creciente respecto su primera coordenada,
luego tengo un bucle que me selecciona cual es el mejor candidato a ser
la el intervalo que cubre (el bucle dentro del bucle, y el primer bucle de todos
que uso para ver con que intervalo empiezo), lo que voy haciendo es explorar
todos los intercambios de iz a dr y en cuanto veo alguno que me tapa menos que
el resto paso de el, en cambio voy acumulando los que tapen mas y cuando se
pasen de la derecha del intervalo seleccionado anteriormente pues cojo
el que mayor cubria de esta tanda y voy a buscar el siguiente.

La complejidad es O(n(log(n))) ya que el algoritmo voraz es lineal pero tenemos
que ordenar el vector que es O(n(log(n))).
*/

typedef struct Intervalo {
  int iz;
  int dr;
} Intervalo;

istream &operator>>(istream &entrada, Intervalo &intervalo){
  entrada >> intervalo.iz;
  entrada >> intervalo.dr;
  return entrada;
}

bool operator< (Intervalo edif1, Intervalo edif2){
  return edif1.iz < edif2.iz;
}

int solucion (vector<Intervalo> &vec, Intervalo CF){
  int i = 0;
  int sol = 0;
  int N = vec.size();
  int i_max = 0;
  int max_dr = CF.iz;
  while (i < N && vec[i].iz <= CF.iz){
    if (vec[i].dr > max_dr){
      max_dr = vec[i].dr;
      i_max = i;
    }
      i++;
    }
  if (vec[0].iz > CF.iz){
      return -1;
  }
  Intervalo inter_max = vec[i_max];
  i = i_max;
  while (i < N && inter_max.dr < CF.dr){
    while (i < N && vec[i].iz <= inter_max.dr){
        if (vec[i].dr > max_dr){
            max_dr = vec[i].dr;
            i_max = i;
        }
        i++;
    }
    inter_max = vec[i_max];
    sol++;
    if (vec[i].iz > inter_max.dr){
        return -1;
    }
  }
  if (vec[i_max].dr < CF.dr){
      return -1;
  }
  sol++;
  return sol;
}

bool resuelveCaso() {
  int lon;
  Intervalo CF;
  cin >> CF;
  cin >> lon;
  if (lon == 0 && CF.iz == 0 && CF.dr == 0){
    return false;
  }
  vector<Intervalo> vec;
  Intervalo elem;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  sort(vec.begin(),vec.end());
  int sol = solucion (vec, CF);
  if (sol == -1){
    cout << "Imposible" << "\n";
  }
  else {cout << sol << "\n";}
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}