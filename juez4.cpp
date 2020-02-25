#include <iostream>
#include <vector>
using namespace std;
#define pb push_back

/*
Precondicion:
A = vec[0..N] (N > 0) y (N <= 10000) y (Para todo i : 0 <= i < N : -50 > vec[i] > 60)
*/

vector<int> solucion (vector<int> vec){
  int n_picos = 0;
  int n_valles = 0;
  int size = vec.size();
  if (size > 2){
    for (int i = 1; i < size - 1; i++){
      if ((vec[i-1] < vec[i]) && (vec[i] > vec[i+1])){
        n_picos++;
      }
      if ((vec[i-1] > vec[i]) && (vec[i] < vec[i+1])){
        n_valles++;
      }
    }
  }
  vector<int> sol_vec (2);
  sol_vec[0] = n_picos;
  sol_vec[1] = n_valles;
  return sol_vec;
}

/*
Postcondicion:
B = ((sol_vec[0] = (#i : 1 <= i < N-1 : (vec[i-1] < vec[i]) y (vec[i] > vec[i+1]))) y
(sol_vec[1] = (#i : 1 <= i < N-1 : (vec[i-1] > vec[i]) y (vec[i] < vec[i+1]))))
*/

void resuelveCaso() {
  int num;
  cin >> num;
  vector<int> vec;
  for (int i = 0; i < num; i++){
    int elem;
    cin >> elem;
    vec.pb(elem);
  }
  vector<int> sol;
  sol = solucion(vec);
  cout << sol[0] << " " << sol[1] << endl;
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}