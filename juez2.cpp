#include <iostream>
#include <vector>
using namespace std;

/*
Precondicion:
A = {(0 < M < 10^4) y (para todo i : 0 <= i < N : 0 < temps[i] <= 10^18 )}
Funcion de cota:
C = M - index
Invariante:
I = {0 <= index <= N y (Min = (min j : 0 <= j < index : temps[j])) y
(n_Min = (#i : 0 <= i < index : temps[i] == Min)) y
(Max = (max j : 0 <= j < index : temps[j]) y
(#i : 0 <= i < index : temps[i] == Max))}
*/

vector<long int> solucion(vector<long int> temps){
  vector<long int> W (4);
  int M = temps.size();
  int index = 1;
  long int Max, Min, n_Max, n_Min;
  Max = temps[0];
  Min = temps[0];
  n_Max = 1;
  n_Min = 1;
  while (index < M){
    long int cu_temp = temps[index];
    if (cu_temp == Max){
      n_Max++;
    }
    if (cu_temp > Max){
      Max = cu_temp;
      n_Max = 1;
    }
    if (cu_temp == Min){
      n_Min++;
    }
    if (cu_temp < Min){
      Min = cu_temp;
      n_Min = 1;
    }
    index ++;
  }
  W[0] = Min;
  W[1] = n_Min;
  W[2] = Max;
  W[3] = n_Max;
  return W;
}

/*
B = {(W[0] = (min i : 0 <= i < M : temps[i])) y (W[1] = (#i : 0 <= i < M : temps[i] == W[0])) y (W[2] = (max i : 0 <= i < M : temps[i])) y (W[3] = (#i : 0 <= i < M : temps[i] == W[2])) y (index = M)}
*/

void resuelveCaso() {
  vector<long int> V;
  long int j;
  cin >> j;
  while (j != 0){
    V.push_back (j);
    cin >> j;
  }
  vector<long int> sol;
  sol = solucion(V);
  int i = 0;
  while (i < sol.size()){
    cout << sol[i] << " ";
    i++;
  }
  cout << "\n";
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}