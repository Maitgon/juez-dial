#include <iostream>
#include <vector>
using namespace std;

/*
Precondicion:
A = {(N > 0) y (0 <= corte < N)}
Funcion de cota:
C = N - i
Invariante:
I = {(0 < i < N) y (max == (max j: (0 <= j <= i) y (i <= corte) : vec[j])) y min ==
  (min j: (corte < j <= i) y (i > corte) : vec[j]) y (cu_temp == vec[i])}
*/

bool solucion (vector<int> vec, int N, int corte){
  int i = 1;
  int max = vec[0];
  while (i <= corte){
    int cu_temp = vec[i];
    if (max < cu_temp){
      max = cu_temp;
    }
    i++;
  }
  int min = vec[i];
  i++;
  while (i < N){
    int cu_temp = vec[i];
    if (min > cu_temp){
      min = cu_temp;
    }
    i++;
  }
  bool sol = (max < min) || (N - corte == 1);
  return sol;
}

/*
Postcondicion:
B = {(i == N) y (max == (max i : 0 <= i <= corte : vec[i])) y
  (min == (min i : corte < i < N)) y (b == (max < min) o ((N - corte) == 1)}
*/

void resuelveCaso(){
  int N, corte;
  vector<int> vec;
  cin >> N >> corte;
  for (int i = 0; i < N; i++){
    int j;
    cin >> j;
    vec.push_back (j);
  }
  bool b = solucion (vec, N, corte);
  if (b) {
    cout << "SI" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}