#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

/*
Mi idea para este problema es usar una funcion auxiliar
llamada solucion_aux que devuelva una tupla de 3 elementos
el primero indicando si el movil o submovil es balanceado,
el segundo indica el peso total de este movil o submovil,
y el tercero indica la posicion del vector que tienes que
acceder para coger los datos del correspondiente submovil
son las variables b, p e i en concreto,

La idea es que si coges algun 0, preguntes el peso al submovil
que corresponda (viene indicado por i) y asi hasta que no haya 0
que sera el caso base, de este modo tendremos un algoritmo de
coste lineal
*/

tuple<bool,long long int,int> solucion_aux (vector<long long int> vec, int i){
    bool b;
    long long int p;
    if (vec[i] != 0 && vec[i+2] != 0){
        b = (vec[i]*vec[i+1] == vec[i+2]*vec[i+3]);
        p = (vec[i] + vec[i+2]);
    }
    else{
        tuple<bool,long long int,int> tuple1;
        tuple<bool,long long int,int> tuple2;
        int i0 = i;
        if (vec[i0] == 0){
            i += 4;
            tuple1 = (solucion_aux(vec,i));
            i = get<2> (tuple1);
        }
        if (vec[i0+2] == 0){
            i += 4;
            tuple2 = (solucion_aux(vec,i));
            i = get<2> (tuple2);
        }
        b = (get<0> (tuple1) && get<0> (tuple2) &&
                 (vec[i0+1]*get<1> (tuple1)) == (vec[i0+3]*get<1> (tuple2)));
        p = get<1> (tuple1) + get<1> (tuple2);
    }
    tuple<bool,long long int,int> sol (b,p,i);
    return sol;
}

bool solucion (vector<long long int> vec){
    bool sol;
    sol = get<0>(solucion_aux (vec, 0));
    return sol;
}

/*
Para interceptar los datos lo que hago es tener un contador (i),
este contador indica el numero de numeros que faltan por leer,
si ve un cero sumara 4 y por cada numero que cuente se disminuira
en 1, por ultimo cuando llegue a 0 parara
*/

void resuelveCaso() {
    long long int elem;
    vector<long long int> vec;
    int i = 4;
    while (i > 0){
        cin >> elem;
        if (elem == 0){
            i += 4;
        }
        vec.push_back(elem);
        i--;
    }
    bool sol = solucion (vec);
    if (sol) {
        cout << "SI" << endl;
    }
    else{
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