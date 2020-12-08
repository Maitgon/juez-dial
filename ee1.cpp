#include <iostream>
#include <vector>
using namespace std;

int reinas_va3 (int sol[], int k, vector<bool> C, vector<bool> D){
    int n = C.size();
    int solucion = 0;
    for (int columna=1; columna<=n; columna++){
        sol[k-1] = columna;
        if (!C[sol[k-1]-1] && !D[sol[k-1]-k+n-1] && !D[k+sol[k-1]+2*n - 3]){

            // preparar solucion
            C[(sol[k-1])-1] = true;
            D[sol[k-1]-k+n-1] = true;
            D[k+sol[k-1]+2*n-3] = true;
            if (k=n){
                //sumar una solucion
                solucion += 1;
            }
            else{
                solucion += reinas_va3(sol, k+1, C, D);
            }

            //Desmarcamos
            C[sol[k-1]-1] = false;
            D[sol[k-1]-k+n-1] = false;
            D[k+sol[k-1]+2*n-3] = false;
        }
    }
    return solucion;
}

int reinas(int &n){
    int sol[n];
    vector<bool> C;
    vector<bool> D;
    for (int i=0; i < n; i++){
        C.push_back(false);
    }
    for (int i=0; i < 4*n-2; i++){
        D.push_back(false);
    }
    int solucion = reinas_va3(sol, 1, C, D);
    return solucion;
}

void resuelveCaso(){
    int n;
    cin >> n;
    int sol;
    sol = reinas(n);
    cout << sol << "\n";
}

int main() {
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}