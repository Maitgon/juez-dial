#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

/*
Precondicion:
A = {(N >= 1) y (N <= 100000) y (Para todo i : 0 <= i < N : vec[i] >= 0)}
*/

int solucion (vector<int> vec){
  int size = vec.size();
  int max_plano = 0;
  int cu_plano = 0;
  for (int i = 0; i < size - 1; i++){
    if (vec[i] == vec[i+1]){
      cu_plano++;
      if (cu_plano > max_plano){
        max_plano = cu_plano;
      }
    }
    else{
      cu_plano = 0;
    }
  }
  return max_plano;
}

/*
Postcondicion:
B = {max_plano = (max i,j : 0 <= i <= j y (Para todo k : i <= k < j : vec[k] = vec[k+1]) :
    j - i)}
*/

bool resuelveCaso(){
  int elem;
  cin >> elem;
  if (elem == -1) {
    return false;
  }
  vector<int> vec;
  while (elem != -1) {
    vec.pb(elem);
    cin >> elem;
  }
  int sol = solucion (vec);
  if (sol == 0) {
    cout << "HOY NO COMEN" << endl;
  }
  else {cout << sol << endl;}
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}