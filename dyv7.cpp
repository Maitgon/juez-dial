#include <iostream>
#include <vector>
using namespace std;

int solucion (const vector <int> vec, const int i, const int j){
  int sol;
  int m = (i+j)/2;
  if (vec[m-1] != vec[m] && vec[m] != vec[m+1]){
      sol = m;
  }
  else if (m%2 == 1){
    if (vec[m+1] == vec[m]){
      sol = solucion (vec, i, m);
    }
    if (vec[m-1] == vec[m]){
      sol = solucion (vec, m, j);
    }
  }
  else {
    if (vec[m+1] == vec[m]){
      sol = solucion (vec, m, j);
    }
    if (vec[m-1] == vec[m]){
      sol = solucion (vec, i, m);
    }
  }
  return sol;
}

void resuelveCaso() {
  int lon;
  cin >> lon;
  vector<int> vec;
  int elem;
  for (int i = 0; i < lon; i++){
    cin >> elem;
    vec.push_back(elem);
  }
  int sol;
  if (lon == 1){
    sol = 0;
  }
  else if (vec[0] != vec[1]){
    sol = 0;
  }
  else if (vec[lon-1] != vec[lon-2]){
    sol = lon-1;
  }
  else {sol = solucion (vec, 0, lon-1);}
  cout << sol << "\n";
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}