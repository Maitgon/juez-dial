#include <iostream>
#include <string>
using namespace std;

char solucion (long long int lon_total, int lon, long long int num){
  long long int len_ant;
  len_ant = lon_total/2 - (lon/2);
  char sol;
  if (num <= len_ant){
    sol = solucion (len_ant, lon-1, num);
  }
  else if (num > len_ant + lon){
    sol = solucion (len_ant, lon-1, num - (len_ant + lon));
  }
  else {
    if (num == len_ant + 1){
      sol = 'B';
    }
    else if (num == len_ant + lon){
      sol = 'H';
    }
    else {sol = 'U';}
  }
  return sol;
}

long long int get_long_total (int lon){
  long long int sol;
  if (lon == 1){
    sol = 3;
  }
  else {
    sol = 2 * get_long_total (lon-1) + 2 + lon;
  }
  return sol;
}

bool resuelveCaso() {
  int lon;
  long long int num;
  cin >> lon >> num;
  if (!cin) {return false;}
  long long int lon_total = get_long_total (lon);
  char sol = solucion (lon_total, lon+2, num);
  cout << sol << endl;
  return true;
}

int main() {
  while (resuelveCaso());
  return 0;
}