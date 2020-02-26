#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
#include<algorithm>

string solucion (vector<int> vec, int cota){
  int N = vec.size();
  int max_pen = 0;
  int cu_pen = 0;
  int comienzo_subida = vec[0];
  for (int i = 0 ; i < N-1 ; i++){
    if (vec[i] < vec[i+1]){
      cu_pen = vec[i+1] - comienzo_subida;
      max_pen = max(max_pen, cu_pen);
    }
    else{
      cu_pen = 0;
      comienzo_subida = vec[i+1];
    }
  }
  string sol;
  if (max_pen > cota) {
    sol = "NO APTA";
  }
  else {sol = "APTA";}
  return sol;
}

bool resuelveCaso() {
  int cota;
  int num;
  cin >> cota >> num;
  int elem;
  vector<int> vec;
  for (int i = 0; i < num ; i++){
    cin >> elem;
    vec.pb(elem);
  }
  if (!cin) {return false;}
  string sol = solucion (vec, cota);
  cout << sol << endl;
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}