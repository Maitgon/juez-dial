#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

vector<int> solucion (vector<int> vec, int cota){
  int cu_len, max_len, primero, N, cu_primero;
  N = vec.size();
  cu_len = 0;
  max_len = 0;
  primero = 0;
  cu_primero = 0;
  for (int i = 0 ; i < N ; i++){
    if (vec[i] > cota){
      cu_len++;
      if (cu_len == 1){
        cu_primero = i;
      }
      if (cu_len > max_len){
        max_len = cu_len;
        primero = cu_primero;
      }
    }
    else {
      cu_len = 0;
    }
  }
  vector<int> sol (2);
  sol[0] = primero;
  sol[1] = primero + max_len - 1;
  return sol;
}

void resuelveCaso(){
  int num, cota, elem;
  cin >> num >> cota;
  vector<int> vec;
  for (int i = 0; i < num ; i++){
    cin >> elem;
    vec.pb(elem);
  }
  vector<int> sol = solucion (vec, cota);
  cout << sol[0] << " " << sol[1] << endl;
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}