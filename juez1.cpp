#include <iostream>
using namespace std;

bool vec_crec (int vec[],int N){
  int i;
  i = 1;
  bool b;
  b = true;
  while (i <= N-1 && b ){
      b = vec[i] > vec[i-1];
      i += 1;
  }
  return b;
}

bool vec_decrec (int vec[],int N){
  int i;
  i = 1;
  bool b;
  b = true;
  while (i <= N-1 && b ){
      b = vec[i] < vec[i-1];
      i += 1;
  }
  return b;
}

/*
Precondicion
(N > 0)
*/
bool solucion (int vec[], int N){
  return vec_decrec (vec, N) || vec_crec(vec, N);
}
/*
Poscondicion
(Para todo i : 0 < i < N : vec[i] > vec[i-1]) o (Para todo i : 0 < i < N : vec[i] < vec[i-1])
*/

/*
Funcion de cota: C = N - i
Invariante: {(0 < i < N) y (b = ((Para todo j : 0 < j <= i : V[j] > [j-1]) o (Para todo j : 0 < j <= i : V[j] < [j-1])))}
*/

bool resuelveCaso() {
  int j;
  cin >> j;
  if (j == 0){
    return false;
  }
  else{
    int i = 1;
    int alturas[j];
    while (i <= j){
      int alt;
      cin >> alt;
      alturas[i-1] = alt;
      i += 1;
   }
   bool es_dalton = solucion(alturas, j);
   if (es_dalton){
     cout << "DALTON" << endl;
   }
   else{
      cout << "DESCONOCIDOS" << endl;
    }
    return true;
  }
}

int main() {
  while (resuelveCaso());
  return 0;
}