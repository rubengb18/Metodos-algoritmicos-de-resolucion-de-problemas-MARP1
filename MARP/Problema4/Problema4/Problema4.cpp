// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "PriorityQueue.h"
#include <algorithm>
using namespace std;
/*
El coste del algoritmo completo sera O(N log N + envios log N)
Definimos el comparador para saber con que criterio ordenaremos la cola de prioridad, teniendo preferencia los elementos con el valor sig menor (les toca antes)
El atributo sig sirve para irle sumando el periodo,y que se vaya a la parte final de la cola de prioridad, dejando paso al siguiente.
*/


struct usuario {
	int id;
	int periodo;
	int sig;
};


bool operator<(usuario const& a, usuario const& b) {
	return a.sig < b.sig || (a.sig == b.sig && a.id < b.id);
}

bool resuelveCaso() {
	int N,periodo,id,envios;
	PriorityQueue<usuario>cola;
	cin >> N;
	if (N == 0) {
		return false;
	}
	for (int i = 0;i < N;i++) {			//coste O(N log N) ya que repetimos N veces el push que tiene orden log N (log 1 + log 2 +...+log N tiene orden NlogN)
		cin >> id>>periodo;
		cola.push({id,periodo,periodo});
	}
	cin >> envios;
	while (envios > 0) {					//O(envios log N)
		auto aux=cola.top();//O(1)
		cout << aux.id << '\n';
		aux.sig += aux.periodo;
		cola.pop();//O(log N)
		cola.push(aux);//O(logN)
		envios--;
	}
	cout << "---\n";
	return true;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}