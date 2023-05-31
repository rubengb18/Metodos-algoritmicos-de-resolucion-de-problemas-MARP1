// Grupo DG, Ruben Gomez Blanco
/*
Para el caso base (cuando el arbol es vacio, estamos en la hoja) devolvemos la altura a 0, y el maximo y el minimo a valores para que al ir subiendo al arbol los datos se introduzcan correctamente en l la recursion, y se devuelve true.
Para los demas guardamos todos los datos para el hijo izquierdo y derecho, y calculamos tanto la altura, como el posible nuevo maximo o minimo de ese subarbol.
Una vez tengo todos estos datos, comprobamos que los dos hijos son AVL, y vemos que el subarbol donde nos encontramos tambien lo es, comprobando si la altura del hijo izq y der solo distan en 1,
y ademas viendo que es de busqueda comprobando maxi<raiz<mind
*/
#include <fstream>
#include "bintree_eda.h"
#include <algorithm>
using namespace std;
/*
Coste lineal respecto a n, siendo n el numero de nodos que forman el arbol, ya que voy por todos los caminos desde la 
raiz hasta todas las hojas pasando por cada nodo solo una vez de forma recursiva
*/
bool resolver(bintree<int> arbol,int& altura,int& maximo,int& minimo) {
	if (arbol.empty()) {
		maximo = -1;
		minimo = 100000000;
		altura = 0;
		return true;
	}
	else {
		int maxi, maxd, mini, mind, alturai, alturad;
		auto esIzq = resolver(arbol.left(), alturai, maxi, mini);
		auto esDer = resolver(arbol.right(), alturad, maxd, mind);
		altura = max(alturai, alturad) + 1;
		maximo = max(arbol.root(), maxd);
		minimo=min(arbol.root(), mini);
		return esIzq && esDer && abs(alturai - alturad) < 2 && arbol.root() > maxi && arbol.root() < mind;
	}
}

void resuelveCaso() {
	bintree<int> arbol= leerArbol(-1);
	int altura, max, min;
	bool sol = resolver(arbol, altura, max, min);
	if (sol) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}